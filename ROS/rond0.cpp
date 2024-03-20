// =====================================================
// rond0.cpp
//------------------------------------------------------
//
//
//=====================================================

#include <ros/ros.h>
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rond0");
    ros::NodeHandle n;
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
        std::stringstream ss;
        ss << "Cmd#" << count;
        
        ROS_INFO ("%s", ss.str().c_str());
        
        ros::spinOnce();
        loop_rate.sleep();
        count++;
    }

    return 0;
}