/*
    控制台输出 HelloROS !!!
*/
#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //执行节点初始化
    ros::init(argc,argv,"Hello");

    //输出日志
    ROS_INFO("Hello ROS!!!哈哈哈哈哈哈哈哈哈哈");
    return 0;
}