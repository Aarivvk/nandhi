#include <gz/msgs/entity_factory.pb.h>
#include <gz/msgs/Utility.hh>
#include <gz/sim/Server.hh>
#include <gz/transport/Node.hh>

#include <csignal>
#include <iostream>
#include <unistd.h>

bool is_terminated{false};

// Create a transport node.
gz::transport::Node node;

// timeout used for services
constexpr unsigned int timeout = 5000;

// Signal handler function
void signalHandler(int signum) {
  std::cout << "\nInterrupt signal (" << signum << ") received.\n";

  // Cleanup and close up stuff here
  // Terminate program
  is_terminated = true;
}

void createEntityFromStr(const std::string &modelStr,
                         const std::string &world_name) {
  //! [call service create sphere]
  bool result;
  gz::msgs::EntityFactory req;
  gz::msgs::Boolean res;
  req.set_sdf(modelStr);

  bool executed =
      node.Request("/world/empty/create", req, timeout, res, result);
  if (executed) {
    if (result)
      std::cout << "Entity was created : [" << res.data() << "]" << std::endl;
    else {
      std::cout << "Service call failed" << std::endl;
      return;
    }
  } else
    std::cerr << "Service call timed out" << std::endl;
  //! [call service create sphere]
}

int main() {
  // Register signal handler for SIGINT
  signal(SIGINT, signalHandler);

  gz::common::Console::SetVerbosity(4);

  gz::sim::ServerConfig serverConfig;

  serverConfig.SetSdfFile("./install/gazebo/share/gazebo/worlds/indoor.sdf");

  gz::sim::Server server(serverConfig);

  server.RunOnce(false);

  std::cout << "Press Ctrl+C to terminate the program...\n";

  // Infinite loop to keep the program running
  while (!is_terminated) {
    // Send observation
    // Get action from cmd_vel
    // Get reset command
    // 1 Step into the simulation with given action
    // Collect the state and observation
    // send information back
    is_terminated = !server.RunOnce(false);
  }

  server.Stop();

  return 0;
}
