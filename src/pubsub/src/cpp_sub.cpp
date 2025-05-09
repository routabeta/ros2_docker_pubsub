#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class CppSubscriber : public rclcpp::Node {
    private:
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    public:
        CppSubscriber() : Node("cpp_sub") { 
            subscription_ = this->create_subscription<std_msgs::msg::String>("/random_float_str", 
                10, 
                [this](std_msgs::msg::String::UniquePtr msg){
                RCLCPP_INFO(this->get_logger(), "Receiving: %s", msg->data.c_str());
            });
        }
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CppSubscriber>());
    rclcpp::shutdown();
    return 0;
}