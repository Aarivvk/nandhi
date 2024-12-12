
#include <gz/common/Console.hh>
#include <gz/sim/Entity.hh>
#include <gz/sim/Model.hh>
#include <gz/sim/components.hh>
#include <gz/sim/components/Link.hh>
#include <gz/sim/components/Model.hh>
#include <ostream>
#include <string>

// This header is required to register plugins. It's good practice to place it
// in the cc file, like it's done here.
#include <gz/plugin/Register.hh>

// Don't forget to include the plugin's header.
#include <gz/msgs/details/double.pb.h>
#include <gz/msgs/details/float.pb.h>

#include "distance.hh"

// This is required to register the plugin. Make sure the interfaces match
// what's in the header.
GZ_ADD_PLUGIN(nandhi::Distance, gz::sim::System,
              nandhi::Distance::ISystemConfigure,
              nandhi::Distance::ISystemPostUpdate)

using namespace nandhi;

void Distance::Configure(const gz::sim::Entity &_entity,
                           const std::shared_ptr<const sdf::Element> &_sdf,
                           gz::sim::EntityComponentManager &_ecm,
                           gz::sim::EventManager &_eventMgr) {
    robot_entity_ = _entity;
    auto robot_model = gz::sim::Model(robot_entity_);

    if (!robot_model.Valid(_ecm)) {
        gz::common::Console::err
            << "Distance sensor should be attached to a module entity "
            << std::endl;
        return;
    }

    if (_sdf->HasElement("target_model")) {
        target_model_name_ = _sdf->Get<std::string>("target_model");
        gz::common::Console::msg << "Found SDF tag for target ["
                                 << target_model_name_ << "]" << std::endl;
    } else {
        gz::common::Console::err << "SDF do not have the tag target_model "
                                 << std::endl;
    }
    if (_sdf->HasElement("topic")) {
        auto topic_name = _sdf->Get<std::string>("topic");
        dis_pub_ = t_node_.Advertise<gz::msgs::Double>(topic_name);
        gz::common::Console::msg
            << "Distance to a target distance will be published to "
            << topic_name << std::endl;
    } else {
        auto topic_name = "/module/distance";
        dis_pub_ = t_node_.Advertise<gz::msgs::Double>(topic_name);
        gz::common::Console::warn
            << "Distance to a target distance will be published to "
            << topic_name << std::endl;
    }
}

// Here we implement the PostUpdate function, which is called at every
// iteration.
void Distance::PostUpdate(const gz::sim::UpdateInfo &_info,
                            const gz::sim::EntityComponentManager &_ecm) {
    if (_info.paused) {
        return;
    }
    if (target_model_name_.empty()) {
        return;
    }
    auto target_entity_option = _ecm.EntityByName(target_model_name_);
    if (!target_entity_option.has_value()) {
        return;
    }

    target_entity_ = target_entity_option.value();
    if (target_entity_ == gz::sim::kNullEntity) {
        return;
    }
    if (!dis_pub_.HasConnections()) {
        return;
    }
    // Current target
    auto target_pose =
        _ecm.Component<gz::sim::components::Pose>(target_entity_)->Data();
    auto robot_pose =
        _ecm.Component<gz::sim::components::Pose>(robot_entity_)->Data();

    auto distance = target_pose.Pos() - robot_pose.Pos();
    gz::msgs::Double msg{};
    msg.set_data(distance.Length());
    dis_pub_.Publish(msg);
}