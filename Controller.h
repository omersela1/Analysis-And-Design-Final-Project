#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "CLI.h"
#include "Adapter.h"
#include "Demo.h"

class CLI;

class Command {
    void(*m_command)(std::string s);

    public:
    Command(): m_command(nullptr) {};
    Command(void(*copy_command)(std::string s)) { m_command = copy_command; };
    Command& operator= (Command& c) { m_command = c.m_command; return *this; };
    void(*getCommand())(std::string s) { return m_command; };
};


class Controller {

    public:
    Controller();
    bool addCommandToCLI(CLI& cli, std::string name, void(*command)(std::string s));
};


#endif