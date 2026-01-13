#include <lecture2_example/publisher_node.h>

PublisherNode::PublisherNode() : Node("publisher_node")
{
    publisher_ = this->create_publisher<std_msgs::msg::Float32>("/sine_wave", 10); // 10 is history kept

    start_time_ = this->get_clock()->now();
}

void PublisherNode::publishSineWave()
{
    // current ros2 time
    rclcpp::Time current_time =  this->get_clock()->now();
    
    // time since start of node
    double t = (current_time - start_time_).seconds();
    
    // calculate force
    msg_.data = std::sin(t);

    // publish message
    publisher_->publish(msg_);
}

int main(int argc, char * argv[])
{
    // initialize the node
    rclcpp::init(argc, argv);

    // create instance of class
    auto node = std::make_shared<PublisherNode>();

    // Set loop rate
    rclcpp::Rate rate = rclcpp::Rate(10); // Hz

    // MAIN LOOP
    while (rclcpp::ok())
    {
        node->publishSineWave();
        rclcpp::spin_some(node); // updates publishers and subscribers
        rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}
