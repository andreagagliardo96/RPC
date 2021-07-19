#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
int main(int argc, char **argv){
    ros::init(argc, argv, "talker");

    ros::NodeHandle n;
    ros::NodeHandle n_("~");
    double speed;
    double radius;
    //n.getParam("speed", speed);

    n_.getParam("speed", speed);
    n_.getParam("radius", radius);

    ROS_INFO("Got %f %f", speed, radius);

    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    ros::Rate loop_rate(10);



    while(ros::ok()){

        geometry_msgs::Twist msg;

        msg.linear.x = speed;
        msg.linear.y = 0.0;
        msg.linear.z = 0.0;

        msg.angular.x = 0.0;
        msg.angular.y = 0.0;
        msg.angular.z = speed*radius;        


        //ROS_INFO("%s", msg.data.c_str()); //equivalent of printf for ROS

        pub.publish(msg);

        ros::spinOnce();    //not needed here, but good practice

        loop_rate.sleep();
    }
    return 0;
}