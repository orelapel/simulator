//
// Created by orelapel on 25.12.2019.
//

#ifndef UNTITLED3_LOOPCOMMAND_H
#define UNTITLED3_LOOPCOMMAND_H

#include "unordered_map"
#include "Parser.h"
#include "ConditionParser.h"

class LoopCommand : public ConditionParser {
public:
    ~LoopCommand(){

    }
    LoopCommand();
    virtual int execute (vector<string>lexer, int index, SimbolTable *st);
};
#endif //UNTITLED3_LOOPCOMMAND_H
