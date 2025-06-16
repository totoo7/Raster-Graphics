#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include <vector>
#include "SessionManager.hpp"

/**
 * @brief A static factory class for creating Command objects based on input strings.
 * 
 * This class maps user input to concrete Command objects.
 */
class CommandFactory {
    public:
        /**
         * @brief Creates a command object based on the provided command string and arguments.
         * 
         * @param cmd The command name (e.g., "load", "save", "undo", etc.).
         * @param args A vector of additional arguments relevant to the command.
         * @param session_manager A pointer to the current SessionManager to associate with the command.
         * @return A pointer to the created Command object. Caller is responsible for its lifetime.
         */
        static Command* create(const std::string& cmd, const std::vector<std::string>& args, SessionManager* session_manager);
    private:
        /**
         * @brief Deleted constructor to prevent instantiation of the factory.
         */
        CommandFactory() = delete;

        /**
         * @brief Deleted copy constructor to prevent copying.
         */
        CommandFactory(const CommandFactory& rhs) = delete;

        /**
         * @brief Deleted copy assignment operator to prevent assignment.
         */
        CommandFactory& operator=(const CommandFactory& rhs) = delete;
};

#endif