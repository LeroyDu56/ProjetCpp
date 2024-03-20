#include <ros/ros.h>
#include <sstream>
#include <geometry_msgs/Twist.h> // Correct the case of the header file

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rond1");
    ros::NodeHandle n;
    // Correct the queue size in advertise method and ensure generic type is properly cased
    ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
        std::stringstream ss;
        ss << "Cmd#" << count;
        ROS_INFO("%s", ss.str().c_str());

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
