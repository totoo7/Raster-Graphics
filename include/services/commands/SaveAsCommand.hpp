#ifndef SAVE_AS_COMMAND_HPP
#define SAVE_AS_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

class SaveAsCommand : public Command {
public:
	SaveAsCommand(Session* const session, const std::vector<std::string>& files);
	static size_t args_count() { return args; };
	std::string execute() override;
	bool is_undoable() const override { return false; };
private:
	Session* const session;
    std::vector<std::string> files;
	static const size_t args = 0;
};

#endif