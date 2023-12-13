#include <ros/ros.h>
#include "dynamixel_wrapper_lib/motor.h"
#include "dynamixel_wrapper_lib/configs/PH54_200_S500_R.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "position_control_node");
    ros::NodeHandle nh;
    ros::NodeHandle pn("~");

    int frequency;
    pn.param<int>("frequency", frequency, 20);

    ros::Rate loop_rate(frequency);

    std::string port_name("/dev/ttyUSB0");
    int baudrate = 1000000;

    dynamixel_wrapper_lib::Handler handler(port_name, baudrate);
    dynamixel_wrapper_lib::Motor motor(1, handler, dynamixel_wrapper_lib::PH54_200_S500_R);

    motor.setTorqueEnable(false);
    motor.setOperatingMode(4);
    motor.setTorqueEnable(true);

    while(ros::ok())
    {
        motor.setGoalPosition(6.28);
        // std::cout << motor.getPresentPosition() << std::endl;
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}