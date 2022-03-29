
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

#include "Mocap_msg.h"
#include "Mocap_msgPubSubTypes.h"
#include "domain_participant.h"
#include "publisher.h"

int main(int argc, char *argv[]) {
  // Create participant. Arguments-> Domain id, QOS name
  DefaultParticipant dp(0, "mocap_publisher");

  // if (argc > 11) {
  //   std::cout << "[ERROR] Mocap publisher only supports 10 objects. Change "
  //                "code to allow for more."
  //             << std::endl;
  //   return 0;
  // }

  // std::vector<std::string> objects(10, "empty");
  // std::vector<std::string> topics = {"empty0", "empty1", "empty2", "empty3",
  //                                    "empty4", "empty5", "empty6", "empty7",
  //                                    "empty8", "empty9"};

  // // load names from argument list
  // for (int i = 1; i < argc; i++) {
  //   objects.at(i - 1) = argv[i]; // first argument is the command
  //   topics.at(i - 1) =
  //       "mocap_" + objects.at(i - 1); // first argument is the command
  // }
  // // Print objects and topics (INFO)
  // std::cout << "publishing the following objecst and topics:" << std::endl;
  // for (int i = 0; i < argc - 1; i++) {
  //   std::cout << "object: \t" << objects.at(i) << "\t topic: \t" <<
  //   topics.at(i)
  //             << std::endl;
  // }

  DDSPublisher mocap_pub(idl_msg::Mocap_msgPubSubType(), "mocap_srl_quad",
                         dp.participant());

  // mocap_pub.init();
  idl_msg::Mocap_msg msg;
  msg.position().x() = 1;
  msg.position().y() = 1;
  msg.position().z() = 1;

  // cpp_msg::Mocap_msg msg;
  // msg.position.x = 1.0;
  // msg.position.y = 1.0;
  // msg.position.z = 1.0;
  // msg.orientation.roll = 0.0;
  // msg.orientation.pitch = 0.0;
  // msg.orientation.yaw = 0.0;

  while (true) {
    mocap_pub.publish(msg);
  }

  // // create publishers
  // DDSPublisher pub[10] = {DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(0), dp.participant()),
  //                         DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(1), dp.participant()),
  //                         DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(2), dp.participant()),
  //                         DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(3), dp.participant()),
  //                         DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(4), dp.participant()),
  //                         DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(5), dp.participant()),
  //                         DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(6), dp.participant()),
  //                         DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(7), dp.participant()),
  //                         DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(8), dp.participant()),
  //                         DDSPublisher(idl_msg::Mocap_msgPubSubType(),
  //                                      topics.at(9), dp.participant())};
  // // create messages
  // cpp_msg::Mocap_msg msg[10]{};

  // for (int i = 0; i < 10; i++) {
  //   msg[i].position.x = 1.0;
  //   msg[i].position.y = 1.0;
  //   msg[i].position.z = 1.0;
  //   msg[i].orientation.roll = 0.0;
  //   msg[i].orientation.pitch = 0.0;
  //   msg[i].orientation.yaw = 0.0;
  // }
  // while (true) {
  //   for (int i = 0; i < argc - 1; i++) {
  //     std::cout << "Publishing" << i << std::endl;
  //     pub[i].publish(msg[i]);
  //   }
  // }
}
