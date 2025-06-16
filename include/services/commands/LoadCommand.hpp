#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "Command.hpp"
#include "SessionManager.hpp"

/**
 * @brief Command to load images into the session manager.
 */
class LoadCommand : public Command {
    public:
        /**
         * @brief Constructs a LoadCommand with the session manager and file arguments.
         * @param session_manager Pointer to the session manager.
         * @param args Vector of filenames to load.
         */
        LoadCommand(SessionManager* const session_manager, const std::vector<std::string>& args);

        /**
         * @brief Returns the expected number of arguments for this command.
         * @return Argument count (always 0).
         */
        static size_t args_count() { return args; };

        /**
         * @brief Executes the load command.
         * @return Status message after loading.
         */
        std::string execute() override;

        /**
         * @brief Indicates that this command cannot be undone.
         * @return False.
         */
        bool is_undoable() const override { return false; };

        /**
         * @brief Indicates that this command does not require an active session.
         * @return False.
         */
        bool needs_session() const override { return false; };
    private:
        SessionManager* const session_manager;
        std::vector<std::string> files;
        static const size_t args = 0;
};

#endif