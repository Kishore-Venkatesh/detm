#include "publisher.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    detm::Publisher pub;

    std::cout << "[Main] Publisher starts ....." << std::endl;
    // publisher start
    pub.start();
    // run for ten seconds before stop
    std::this_thread::sleep_for(std::chrono::seconds(10));
    // publisher stop
    pub.stop();
    std::cout << "[Main] Publisher stops ....." << std::endl;
    return 0;
}