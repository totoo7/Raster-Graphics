#ifndef SNAPSHOT_COMMAND_HPP
#define SNAPSHOT_COMMAND_HPP

#include "Command.hpp"
#include "Image.hpp"
#include "Session.hpp"
#include <vector>


class SnapshotCommand : public Command {
    public:
        SnapshotCommand() = default;
        SnapshotCommand(const SnapshotCommand& rhs);
        void take_snapshot(Session* const session);
        void restore_snapshot(Session* const session);
        virtual ~SnapshotCommand();
    protected:
        std::vector<Image*> snapshots;
};

#endif