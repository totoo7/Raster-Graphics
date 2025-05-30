#include "SaveAsCommand.hpp"

SaveAsCommand::SaveAsCommand(Session* const session, const std::vector<std::string>& files) : 
    session(session), files(files) {}

std::string SaveAsCommand::execute() {
    session->saveAs(files);
    std::string res = "Files ";
    for (size_t i = 0; i < files.size(); i++) {
        res += files[i];
        res += ' ';
    }

    res += "successfully saved.\n";
    return res;
}