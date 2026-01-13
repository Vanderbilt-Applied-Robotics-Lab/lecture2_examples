#ifndef PUBLISHER_NODE_H
#define PUBLISHER_NODE_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

/**
 * Publishes a sine wave to the /sine_wave topic
 * Applied Robotics
 * Author: Garrison Johnston
 */
class PublisherNode : public rclcpp::Node
{
public:
    // constructor
    PublisherNode();

    // destructor
    ~PublisherNode() = default;

    // publishes the sine wave
    void publishSineWave();

private:
    // publisher object
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;

    // output message
    std_msgs::msg::Float32 msg_ = std_msgs::msg::Float32();
    
    // Time at start of node
    rclcpp::Time start_time_; 
};

#endif // PUBLISHER_NODE_H