#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Command.hpp"
#include "SessionManager.hpp"

/**
 * @brief Singleton class that provides the main interface for running the program.
 * 
 * The Interface class acts as the main control loop of the application.
 * It handles user input, manages commands, and coordinates session operations.
 */
class Interface {
    public:
        /**
         * @brief Returns the single instance of the Interface.
         * 
         * Implements the Singleton design pattern to ensure only one instance exists.
         * @return Reference to the single Interface instance.
         */
        static Interface& get_instance();
        /**
         * @brief Runs the main command-processing loop.
         * 
         * Handles user input, parses commands, and delegates execution to the appropriate Command object.
         */
        void run();
    private:
        /**
         * @brief Private constructor to enforce Singleton pattern.
         */
        Interface();
        // Deleted copy constructor and assignment operator to prevent duplication
        Interface(const Interface& rhs) = delete;
        Interface& operator=(const Interface& rhs) = delete;
    private:
        Command* cmd;
        SessionManager session_manager;
};

#endif