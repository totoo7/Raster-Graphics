#include "MonochromeCommand.hpp"

MonochromeCommand::MonochromeCommand(Session* const session) : session(session) {}

std::string MonochromeCommand::execute() {
	for (size_t i = 0; i < session->images.size(); i++)
		session->images[i]->monochrome();

	return "Monochrome was successful.\n";
}
