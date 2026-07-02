/*
    需求: 循环发布人的信息

*/

#include "ros/ros.h"
#include "hello_topics_pkg/person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    //1.初始化 ROS 节点
    ros::init(argc,argv,"talker_person");

    //2.创建 ROS 句柄
    ros::NodeHandle nh;

    //3.创建发布者对象
    ros::Publisher pub = nh.advertise<hello_topics_pkg::person>("chatter_person",1000);

    //4.组织被发布的消息，编写发布逻辑并发布消息
    hello_topics_pkg::person p;
    p.name = "liuhe";
    p.age = 2001;
    p.height = 1.70;

    ros::Rate r(1);
    while (ros::ok())
    {
        pub.publish(p);
        p.age += 1;
        ROS_INFO("我叫:%s,今年%d岁,高%.2f米", p.name.c_str(), p.age, p.height);

        r.sleep();
        ros::spinOnce();
    }



    return 0;
}