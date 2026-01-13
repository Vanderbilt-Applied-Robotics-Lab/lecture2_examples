cmake_minimum_required(VERSION 3.8)
project(lecture2_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)
include_directories(launch)

add_executable(subscriber_node src/subscriber_node.cpp)
add_executable(publisher_node src/publisher_node.cpp)

ament_target_dependencies(subscriber_node rclcpp std_msgs)
ament_target_dependencies(publisher_node rclcpp std_msgs)

install(TARGETS subscriber_node
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS publisher_node
  DESTINATION lib/${PROJECT_NAME})

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
