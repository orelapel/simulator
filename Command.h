//
// Created by noa on 18/12/2019.
//

#ifndef SIMULATOR_COMMAND_H
#define SIMULATOR_COMMAND_H
#include <string>
#include <vector>
#include "SimbolTable.h"
#include "iostream"
using namespace std;

class Command {
public:
    ~Command(){

    }
    virtual int execute(vector<string>lexer, int index, SimbolTable *st){
    }
};
#endif //SIMULATOR_COMMAND_H
