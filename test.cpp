#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "Timer started" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Timer finished" << std::endl;

    return 0;
}