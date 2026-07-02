/*
    参数服务器操作之新增与修改(二者API一样)_C++实现:
    在 roscpp 中提供了两套 API 实现参数操作
    ros::NodeHandle
        setParam("键",值)
    ros::param
        set("键","值")

    示例:分别设置整形、浮点、字符串、bool、列表、字典等类型参数
        修改(相同的键，不同的值)

*/


#include "ros/ros.h"

int main(int argc, char *argv[])
{
    // 设置编码
    setlocale(LC_ALL, "");

    // 2. 初始化 ROS 节点: 命名(唯一)
    ros::init(argc, argv, "set_update_param");

    // 增 
    // 方法一: 使用 nh 方法
    ros::NodeHandle nh;

    nh.setParam("robot_name", "RoboMaster");
    nh.setParam("robot_id", 101);
    nh.setParam("max_speed", 5.5);

    // 方法二: ros::param
    ros::param::set("robot_type", "Quadrotor");
    ros::param::set("robot_id", 102);
    ros::param::set("radius", 0.3);

    // 改,其实就是覆盖
    // 方法一: 使用 nh 方法
    nh.setParam("max_speed", 10);   

    // 方法二: ros::param 
    ros::param::set("robot_type", "Hexarotor");
    ros::param::set("radius", 2);


    ROS_INFO("参数已修改完成!");

    return 0;
}