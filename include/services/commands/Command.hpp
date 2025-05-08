#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command {
    public:
        virtual std::string execute() = 0;
        static size_t args_count();
    private:
        static const size_t args = 0;
};

#endif