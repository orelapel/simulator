//
// Created by noa on 22/12/2019.
//

#ifndef SIMULATOR_SLEEP_H
#define SIMULATOR_SLEEP_H

#include "Command.h"
#include <unistd.h>
#include "Interpreter.h"



class Sleep: public Command {
    virtual int execute (vector<string>lexer, int index, SimbolTable *st) ;
};
#endif //SIMULATOR_SLEEP_H
