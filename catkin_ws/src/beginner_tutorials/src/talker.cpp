#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv){
    ros::init(argc, argv, "talker");

    ros::NodeHandle n;

    //advertise() returns a publisher object

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000);
    ros::Rate loop_rate(10);

    int count = 0;

    while(ros::ok()){

        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world from Andrea" << count;

        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str()); //equivalent of printf for ROS

        chatter_pub.publish(msg);

        ros::spinOnce();    //not needed here, but good practice

        loop_rate.sleep();
        ++count;
    }
    return 0;
}