
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

  ////////////////////////////////////////////////////////////
  // FastDDS objects

  // Create participant. Arguments-> Domain id, QOS name
  DefaultParticipant dp(0, "mocap_publisher");

  // Create DDS publisher vector
  std::vector<DDSPublisher> mocap_pub;

  // Create Mocap Message Vector
  std::vector<cpp_msg::Mocap> mocap_msg(N);

  // Initialize each Element of the vector
  for (int i = 0; i < N; i++) {
    std::string topic = parameters::topic_prefix + parameters::objects.at(i);
    mocap_pub.push_back(
        DDSPublisher(idl_msg::MocapPubSubType(), topic, dp.participant()));
    mocap_pub.at(i).init();
  }

  // ////////////////////////////////////////////////////////
  // for (int i = 0; i < N; i++) {
  //   mocap_msg.at(i).header.timestamp = _Output_GetFrameNumber.FrameNumber;
  // }
  // ////////////////////////////////////////////////////////

  // ///////////////////////////////////////////////////////////////
  // for (int i = 0; i < N; i++) {
  //   mocap_msg.at(i).latency = MyClient.GetLatencyTotal().Total;
  // }

  // ////////////////////////////////////////////
  // for (int i = 0; i < N; i++) {
  //   if (SubjectName.compare(parameters::objects.at(i)) == 0) {
  //     mocap_msg.at(i).header.id = SubjectName;
  //   }
  // }
  // ////////////////////////////////////////////

  // // Capture position in FastDDS message
  // ////////////////////////////////////////////
  // for (int i = 0; i < N; i++) {
  //   if (SubjectName.compare(parameters::objects.at(i)) == 0) {
  //     mocap_msg.at(i).pose.position.x =
  //         _Output_GetSegmentGlobalTranslation.Translation[0] / 1000.0;
  //     mocap_msg.at(i).pose.position.y =
  //         _Output_GetSegmentGlobalTranslation.Translation[1] / 1000.0;
  //     mocap_msg.at(i).pose.position.z =
  //         _Output_GetSegmentGlobalTranslation.Translation[2] / 1000.0;
  //   }
  // }

  // ////////////////////////////////////////////
  // for (int i = 0; i < N; i++) {
  //   if (SubjectName.compare(parameters::objects.at(i)) == 0) {
  //     mocap_msg.at(i).pose.orientation_quat.x =
  //         _Output_GetSegmentGlobalRotationQuaternion.Rotation[0];
  //     mocap_msg.at(i).pose.orientation_quat.y =
  //         _Output_GetSegmentGlobalRotationQuaternion.Rotation[1];
  //     mocap_msg.at(i).pose.orientation_quat.z =
  //         _Output_GetSegmentGlobalRotationQuaternion.Rotation[2];
  //     mocap_msg.at(i).pose.orientation_quat.w =
  //         _Output_GetSegmentGlobalRotationQuaternion.Rotation[3];
  //   }
  // }

  // // Publish data
  // for (int i = 0; i < N; i++) {
  //   if (SubjectName.compare(parameters::objects.at(i)) == 0) {
  //     mocap_pub.at(i).publish(mocap_msg.at(i));
  //   }
  // }
  // ////////////////////////////////////
}
