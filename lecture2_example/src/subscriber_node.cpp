#include <lecture2_example/subscriber_node.h>

SubscriberNode::SubscriberNode() : Node("subscriber_node")
{
    // create subscribers
    subscriber_ = this->create_subscription<std_msgs::msg::Float32>("/sine_wave", 10, std::bind(&SubscriberNode::sineWaveCallback, this, std::placeholders::_1));
}

void SubscriberNode::sineWaveCallback(const std_msgs::msg::Float32 & msg)
{
    RCLCPP_INFO(this->get_logger(), "Current sine wave value %0.2f", msg.data);
}

int main(int argc, char * argv[])
{
    // initialize the node
    rclcpp::init(argc, argv);

    // create instance of class
    auto node = std::make_shared<SubscriberNode>();

    // MAIN LOOP
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
