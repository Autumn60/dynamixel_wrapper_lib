#pragma once

#ifndef DYNAMIXEL_WRAPPER_LIB_MOTOR_H
#define DYNAMIXEL_WRAPPER_LIB_MOTOR_H

#include <ros/ros.h>

#include "dynamixel_wrapper_lib/handler.h"
#include "dynamixel_wrapper_lib/config.h"

namespace dynamixel_wrapper_lib
{

    class Motor
    {
        public:
            Motor() {}
            Motor(const int& id, Handler& handler, Config& config);

            void init(const int& id, Handler& handler, Config& config);

            inline void setDriveMode(int drive_mode) { write(_config->drive_mode, drive_mode); }
            inline void setOperatingMode(int operating_mode) { write(_config->operating_mode, operating_mode); }
            inline double getHomingOffset() { return read_signed(_config->homing_offset) * rev_to_rad / _config->resolution; }
            inline void setHomingOffset(double rad) { write(_config->homing_offset, rad * rad_to_rev * _config->resolution); }
            inline void setMovingThreshold(double rad_per_sec) { write(_config->moving_threshold, rad_per_sec * rad_per_sec_to_rpm / _config->velocity_scaling_factor); }
            inline void setMaxVoltageLimit(double voltage) { write(_config->max_voltage_limit, voltage / _config->voltage_scaling_factor); }
            inline void setMinVoltageLimit(double voltage) { write(_config->min_voltage_limit, voltage / _config->voltage_scaling_factor); }
            inline void setCurrentLimit(double ampere) { write(_config->current_limit, ampere*ampere_to_milli_ampere/_config->current_scaling_factor); }
            inline void setAccelerationLimit(double rad_per_sec2) { write(_config->acceleration_limit, rad_per_sec2 * rad_per_sec2_to_rpm2 / _config->acceleration_scaling_factor); }
            inline void setVelocityLimit(double rad_per_sec) { write(_config->velocity_limit, rad_per_sec * rad_per_sec_to_rpm / _config->velocity_scaling_factor); }
            inline void setMaxPositionLimit(double rad) { write(_config->max_position_limit, rad*rad_to_rev * _config->resolution); }
            inline void setMinPositionLimit(double rad) { write(_config->min_position_limit, rad*rad_to_rev * _config->resolution); }
            inline void setTorqueEnable(bool state) { write(_config->torque_enable, (int)state); }
            void setLED(int r, int g, int b);
            std::string getHardwareErrorStatus();
            void setVelocityGain(int Kp, int Ki);
            void setPositionGain(int Kp, int Ki, int Kd);
            inline void setGoalCurrent(double ampere) { write(_config->goal_current, ampere * ampere_to_milli_ampere / _config->current_scaling_factor); }
            inline void setGoalVelocity(double rad_per_sec) { write(_config->goal_velocity, rad_per_sec * rad_per_sec_to_rpm / _config->velocity_scaling_factor); }
            inline void setProfileAcceleration(double rad_per_sec2) { write(_config->profile_acceleration, rad_per_sec2 * rad_per_sec2_to_rpm2 / _config->acceleration_scaling_factor); }
            inline void setProfileVelocity(double rad_per_sec) { write(_config->profile_velocity, rad_per_sec * rad_per_sec_to_rpm / _config->velocity_scaling_factor); }
            inline void setGoalPosition(double rad) { write(_config->goal_position, rad * rad_to_rev * _config->resolution); }
            inline bool getMoving() { return read(_config->moving); }
            inline bool getIsInPosition() { return read(_config->moving_status)&0x01; }
            inline double getPresentCurrent() { return read_signed(_config->present_current) * _config->current_scaling_factor * milli_ampere_to_ampere; }
            inline double getPresentVelocity() { return read_signed(_config->present_velocity) * _config->velocity_scaling_factor * rpm_to_rad_per_sec; }
            inline double getPresentPosition() { return read_signed(_config->present_position) / _config->resolution * rev_to_rad; }
            inline double getGoalCurrent() { return read_signed(_config->goal_current) * _config->current_scaling_factor * milli_ampere_to_ampere; }
            inline double getGoalVelocity() { return read_signed(_config->goal_velocity) * _config->velocity_scaling_factor * rpm_to_rad_per_sec; }
            inline double getGoalPosition() { return read_signed(_config->goal_position) / _config->resolution * rev_to_rad; }
            inline double getPresentTemperature() { return read(_config->present_temperature); }
            
            void write(Item item, int value);
            uint32_t read(Item item);
            int32_t read_signed(Item item);    

        private:
            int _id;
            Handler* _handler;
            Config* _config;

            const double rad_to_rev = 0.1592; // = 1 / 2pi
            const double rad_per_sec_to_rpm = 9.5493; // = (1 / 2pi) * 60
            const double ampere_to_milli_ampere = 1e3;
            const double rad_per_sec2_to_rpm2 = 572.9578; // = (1 / 2pi) * 60 * 60

            const double milli_ampere_to_ampere = 1e-3;
            const double rpm_to_rad_per_sec = 0.1047;
            const double rev_to_rad = 6.283;
    };  // class Motor

} // namespace dynamixel_wrapper_lib

#endif