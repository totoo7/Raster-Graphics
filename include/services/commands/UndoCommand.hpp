#ifndef UNDO_COMMAND_HPP
#define UNDO_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

class UndoCommand : public Command {
	public:
		UndoCommand(Session* const session);
		static size_t get_args() { return args; };
		std::string execute() override;
		void undo() override;
		bool is_undoable() const override { return false; };
	private:
		Session* const session;
		static const size_t args = 0;
};

#endif