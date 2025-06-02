#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command {
    public:
        virtual std::string execute() = 0;
        virtual bool is_undoable() const = 0;
        virtual void undo();
        virtual Command* clone() { return nullptr; };
        static size_t args_count();
        virtual ~Command() = default;
    private:
        static const size_t args = 0;
};

#endif