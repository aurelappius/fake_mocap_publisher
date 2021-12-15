
// FastDDS
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "MocapPubSubTypes.h"
#include "default_participant.h"
#include "default_publisher.h"
#include "paths.h"
#include "sensor_msgs/msgs/Mocap.h"
#include "set_parameters.h"

int main(int argc, char *argv[]) {
  // load from YAML File
  set_parameters(paths::parameters_path);
  const int N = parameters::objects.size();  // Number of Objects

  // FastDDS objects

  // Create participant. Arguments-> Domain id, QOS name
  DefaultParticipant dp(0, "mocap_publisher");

  // Create publisher with msg type
  DDSPublisher mocap_pub(idl_msg::MocapPubSubType(), "mocap_pose",
                         dp.participant());

  // .idl message
  cpp_msg::Mocap mocap_msg;

  // Initalize mocap_publisher
  mocap_pub.init();

  mocap_msg.pose.position.x = 1;
  mocap_msg.pose.position.y = 1;
  mocap_msg.pose.position.z = 1;
  while (true) {
    mocap_pub.publish(mocap_msg);
  }
}
