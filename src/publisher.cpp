#include "publisher.hpp"
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>

namespace detm
{

    Publisher::Publisher()
    {
        is_running_ = false;
    }

    void Publisher::start()
    {
        bool expected = false;
        // check if its already running, if yes then skip else start the process
        if(!is_running_.compare_exchange_strong(expected, true))
            return;

        worker_ = std::thread(&Publisher::run, this);
    }

    void Publisher::stop()
    {
        is_running_ = false;

        if(worker_.joinable())
            worker_.join();
    }

    void Publisher::run()
    {
        int counter = 0;
        std::cout << "Publisher starts ..." << std::endl;
        while(is_running_.load())
        {
            std::cout << "Publisher : " << ++counter << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "Publisher stops ..." << std::endl;
    }

    Publisher::~Publisher()
    {
        stop();
    }

} // namespace detm
