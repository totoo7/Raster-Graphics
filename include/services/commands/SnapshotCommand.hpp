#ifndef SNAPSHOT_COMMAND_HPP
#define SNAPSHOT_COMMAND_HPP

#include "Command.hpp"
#include "Image.hpp"
#include "Session.hpp"
#include <vector>

/**
 * @brief Base class for commands that need to take and restore image snapshots.
 * 
 * Provides functionality for storing and restoring the state of images
 * in a session to support undo/redo operations.
 */
class SnapshotCommand : public Command {
    public:
		/**
		 * @brief Default constructor.
		 */
        SnapshotCommand() = default;

		/**
		 * @brief Copy constructor.
		 * @param rhs SnapshotCommand to copy from.
		 */
        SnapshotCommand(const SnapshotCommand& rhs);

		/**
		 * @brief Takes a snapshot of the current session state.
		 * @param session Pointer to the session whose images will be saved.
		 */
        void take_snapshot(Session* const session);

		/**
		 * @brief Restores the session to the previously saved snapshot.
		 * @param session Pointer to the session to restore.
		 */
        void restore_snapshot(Session* const session);

		/**
		 * @brief Virtual destructor.
		 */
        virtual ~SnapshotCommand();
    protected:
        std::vector<Image*> snapshots;
};

#endif