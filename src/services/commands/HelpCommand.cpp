#include "HelpCommand.hpp"

const size_t HelpCommand::args = 0;

std::string HelpCommand::execute() {
    std::string out;
    out += "-- All commands --\n";
    out += "> load <file1> <file2> ... :- Loads all arguments into one session. Commands are executed on every image in the session.\n";
    out += "> list :- Gives information on the current session.\n";
    out += "> add <file> :- Adds a new image to the active session.\n";
    out += "> switch <session_id> :- Switches to the session with the given ID.\n";
    out += "> save :- Saves all images in the current session to their original filenames.\n";
    out += "> saveas <file1> <file2> ... <name1> <name2> ... :- Saves all images in the session to the given files.\n";
    out += "> grayscale :- Converts all images in the session to grayscale.\n";
    out += "> monochrome :- Converts all images in the session to monochrome.\n";
    out += "> negative :- Applies a negative filter to all images in the session.\n";
    out += "> rotate <left|right> :- Rotates all images in the session in the specified direction.\n";
    out += "> flip <top|left> :- Flips all images in the session in the specified direction.\n";
    out += "> paste <img_src> <img_dest> <x> <y> <new_filename> :- Makes a collage. \n";
    out += "> undo :- Reverts the last undoable command in the session.\n";
    out += "> redo :- Reapplies the last undone command in the session.\n";
    out += "> help :- Displays this help message.\n";
    out += "> exit :- Exits the program.\n";
    return out;
}