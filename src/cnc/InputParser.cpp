#include "InputParser.h"

InputParser::InputParser (int &argc, char **argv) {
    // Tokenize the input files
    for (int i = 1; i < argc; ++i)
        this->tokens.push_back(std::string(argv[i]));
}

// Get the argument associated with an option
const std::string& InputParser::getArg(const std::string &option) const {
    std::vector<std::string>::const_iterator itr;
    itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end()){
        return *itr;
    }
    static const std::string empty_string("");
    return empty_string;
}

// Check if an argument was passed
bool InputParser::argExists(const std::string &option) const {
    return std::find(this->tokens.begin(), this->tokens.end(), option)
           != this->tokens.end();
}

// Toggles an option with either a short or a long flag
bool InputParser::toggleOption(std::string shortFlag, std::string longFlag) const {
    if (this->argExists(shortFlag) || this->argExists(longFlag)) {
      return true;
    }
    return false;
}

// Toggles an option with an arbitrary flag
bool InputParser::toggleOption(std::string flag) const {
    if (this->argExists(flag)) {
      return true;
    }
    return false;
}

std::vector<std::string> InputParser::getTokens() {
    return this->tokens;
}

void InputParser::setTokens(std::vector<std::string> tokens) {
    this->tokens = tokens;
}
