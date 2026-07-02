/*
    参数服务器操作之查询_C++实现:
    在 roscpp 中提供了两套 API 实现参数操作
    ros::NodeHandle

        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached(键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

    ros::param ----- 与 NodeHandle 类似
    */

    #include "ros/ros.h"

    int main(int argc, char *argv[])
    {   
        setlocale(LC_ALL,"");
        ros::init(argc,argv,"get_param");

        ros::NodeHandle nh;
        // 1. param
        ROS_INFO("----使用 param 获取参数----");
        std::string robot_type = nh.param<std::string>("robot_type", "GroundRobot");
        ROS_INFO("robot_type: %s", robot_type.c_str());
        
        double radius = nh.param<double>("max_radius", 5525);
        ROS_INFO("radius: %.2f", radius);
      
        // 2. getParam
        ROS_INFO("----使用 getParam 获取参数----");
        double max_speed2 = 0.0;
        bool result = nh.getParam("max_speed", max_speed2);
        if (result)
        {
            ROS_INFO("max_speed2: %.2f", max_speed2);
        }
        else
        {
            ROS_WARN("没有查询到 max_speed 参数");
        }
        
        //3. getParamCached -- similar with getparam,提高变量获取效率
        ROS_INFO("----使用 getParamCached 获取参数----");
        double max_speed3 = 0.0;
        bool result2 = nh.getParam("max_speed1", max_speed3);
        if (result2)
        {
            ROS_INFO("max_speed3: %.2f", max_speed3);
        }
        else
        {
            ROS_WARN("没有查询到 max_speed 参数");
        }
        
        // 4. getParamNames
        ROS_INFO("----获取所有参数的键----");
        std::vector<std::string> param_names;
        nh.getParamNames(param_names);
        for (auto name : param_names)
        {
            ROS_INFO("param_name: %s", name.c_str());
        }

        // 5. hasParam
        ROS_INFO("----检查参数是否存在----");
        bool flag1 = nh.hasParam("robot_name");
        bool flag2 = nh.hasParam("robot_type1");
        ROS_INFO("参数服务器包含 robot_name 参数: %d", flag1);
        ROS_INFO("参数服务器包含 robot_type1 参数: %d", flag2);

        // 6. searchParam
        ROS_INFO("----搜索参数键名----");
        std::string key;
        std::string key2;
        nh.searchParam("radius", key);
        ROS_INFO("搜索键名: %s", key.c_str());
        nh.searchParam("radiusXXX", key2);
        ROS_INFO("搜索键名: %s", key2.c_str());




        return 0;
    }

