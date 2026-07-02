/* 
    参数服务器操作之删除_C++实现:

    ros::NodeHandle
        deleteParam("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false

    ros::param
        del("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false
*/

#include "ros/ros.h"

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"delete_param");

    ros::NodeHandle nh;
    bool flag = nh.deleteParam("robot_name");
    if(flag)
    {
        ROS_INFO("使用 nh.deleteParam 删除 robot_name 参数成功");
    }
    else
    {
        ROS_WARN("使用 nh.deleteParam 删除 robot_name 参数失败");
    }
    
    bool flag2 = ros::param::del("robot_type");
    if(flag2)
    {
        ROS_INFO("使用 ros::param::del 删除 robot_type 参数成功");
    }
    else
    {
        ROS_WARN("使用 ros::param::del 删除 robot_type 参数失败");
    }

    return 0;
}
