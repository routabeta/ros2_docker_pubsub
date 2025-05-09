#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;


class CppPublisher : public rclcpp::Node {
    private:
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        int16_t count_;

    public:
        CppPublisher() : Node("cpp_pub"), count_(0) {
            publisher_ = this->create_publisher<std_msgs::msg::String>("/random_float_str", 10);

            timer_ = this->create_wall_timer(1000ms, [this](){
                auto message = std_msgs::msg::String();
                float rand_float = (float) (std::rand()) / (RAND_MAX) * 100;

                message.data = "Generated float #" + std::to_string(count_++) + ": " + std::to_string(rand_float);
                publisher_->publish(message);
                RCLCPP_INFO(this->get_logger(), "Publishing at 1 Hz on count: %d", count_-1);
            });
        }
};


int main(int argc, char * argv[]){
    std::srand(std::time(0));
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CppPublisher>());
    rclcpp::shutdown();
    return 0;
}