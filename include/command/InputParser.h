#pragma once
#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <algorithm>
#include <string>
#include <vector>

class InputParser { 
    private:
        std::vector<std::string> tokens;
        std::vector<InputParser> subcommands;
    public:
        InputParser(int &argc, char **argv);
        const std::string& getArg(const std::string &option) const;
        bool argExists(const std::string &option) const; 
        bool toggleOption(std::string shortFlag, std::string longFlag) const;
        bool toggleOption(std::string flag) const;

        // Getters
        std::vector<std::string> getTokens();
        std::vector<InputParser> getSubcommands();

        // Setters
        void setTokens(std::vector<std::string> tokens);
        void setSubcommands(std::vector<InputParser> subcommands);
};

#endif // INPUT_PARSER_H
