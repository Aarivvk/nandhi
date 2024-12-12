#ifndef SRC_NANDHI_SIMULATION_GZ_MODULE_PLUGINS_DISTANCE_SENSOR_DISTANCE
#define SRC_NANDHI_SIMULATION_GZ_MODULE_PLUGINS_DISTANCE_SENSOR_DISTANCE

// The only required include in the header is this one.
// All others will depend on what your plugin does.
#include <gz/sim/Entity.hh>
#include <gz/sim/System.hh>
#include <gz/transport/Node.hh>

// It's good practice to use a custom namespace for your project.
namespace nandhi {
// This is the main plugin's class. It must inherit from System and at least
// one other interface.
// Here we use `ISystemPostUpdate`, which is used to get results after
// physics runs. The opposite of that, `ISystemPreUpdate`, would be used by
// plugins that want to send commands.
class Distance : public gz::sim::System,
                   public gz::sim::ISystemConfigure,
                   public gz::sim::ISystemPostUpdate {
   public:
    void Configure(const gz::sim::Entity &_entity,
                   const std::shared_ptr<const sdf::Element> &_sdf,
                   gz::sim::EntityComponentManager &_ecm,
                   gz::sim::EventManager &_eventMgr) override;
    // Plugins inheriting ISystemPostUpdate must implement the PostUpdate
    // callback. This is called at every simulation iteration after the physics
    // updates the world. The _info variable provides information such as time,
    // while the _ecm provides an interface to all entities and components in
    // simulation.
   public:
    void PostUpdate(const gz::sim::UpdateInfo &_info,
                    const gz::sim::EntityComponentManager &_ecm) override;

   private:
    gz::sim::Entity robot_entity_{gz::sim::kNullEntity};

   private:
    gz::sim::Entity target_entity_{gz::sim::kNullEntity};
    std::string target_model_name_{};
    // Create a transport node.
    gz::transport::Node t_node_;
    gz::transport::Node::Publisher dis_pub_;
};
}  // namespace hello_world
#endif /* SRC_NANDHI_SIMULATION_GZ_MODULE_PLUGINS_DISTANCE_SENSOR_DISTANCE */
