#include "MonochromeCommand.hpp"

MonochromeCommand::MonochromeCommand(Session* const session) : session(session) {}

MonochromeCommand::MonochromeCommand(const MonochromeCommand& rhs) : session(rhs.session) {
		for (Image* img : rhs.snapshots) {
			snapshots.push_back(img->clone());
		}
	}

std::string MonochromeCommand::execute() {
	for (Image* img : session->images) 
		snapshots.push_back(img->clone());
	session->monochrome();
	return "Monochrome was successful.\n";
}

void MonochromeCommand::undo() {
	for (Image* img : session->images) {
		delete img;
	}
	session->images.clear();
	for (Image* img : snapshots) {
		session->images.push_back(img->clone());
	}
}

MonochromeCommand::~MonochromeCommand() {
	for (Image* img : snapshots) {
		delete img;
	}
}