#pragma once

#include <thread>
#include <atomic>

namespace detm
{

class Publisher
{
    public:
        /**
         * @brief Publisher Constructor
         */
        Publisher();

        /**
         * @brief Publisher Destructor
         */
        ~Publisher();

        /**
         * @brief Deleted Copy Constructor for Publisher
         */
        Publisher(const Publisher&) = delete;

        /**
         * @brief Deleted Copy Constructor for Publisher
         */
        Publisher& operator=(const Publisher&) = delete;

        /**
         * @brief Deleted Move Constructor for Publisher
         */
        Publisher(Publisher&&) = delete;

        /**
         * @brief Deleted Move Assignment for Publisher
         */
        Publisher& operator=(Publisher&&) = delete;

        /**
         * @brief Method to start the publisher
         */
        void start();

        /**
         * @brief Method to stop the publisher
         */
        void stop();

    private:
        /**
         * @brief Publisher run method
         */
        void run();

        /// A thread to run the publisher process
        std::thread worker_;
        /// A flag to check the status of publisher whether its running/not
        std::atomic<bool> is_running_{false};
};

} // namespace detm