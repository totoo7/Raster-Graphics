#include "SnapshotCommand.hpp"

SnapshotCommand::SnapshotCommand(const SnapshotCommand& rhs) {
	for (Image* img : rhs.snapshots) {
		snapshots.push_back(img->clone());
	}
}

void SnapshotCommand::take_snapshot(Session* const session) {
    for (Image* img : session->get_images()) 
		snapshots.push_back(img->clone());
}

void SnapshotCommand::restore_snapshot(Session* const session) {
    for (Image* img : session->get_images()) {
		delete img;
	}
	session->get_images().clear();
	for (Image* img : snapshots) {
		session->get_images().push_back(img->clone());
	}
}

SnapshotCommand::~SnapshotCommand() {
    for (Image* img : snapshots) {
        delete img;
    }
}