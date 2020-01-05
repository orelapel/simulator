//
// Created by orelapel on 25.12.2019.
//

#ifndef UNTITLED3_IFCOMMAND_H
#define UNTITLED3_IFCOMMAND_H
#include "unordered_map"
#include "ConditionParser.h"
using namespace std;

class IfCommand: public ConditionParser {
public:
    IfCommand();
    ~IfCommand(){

    }
    virtual int execute (vector<string>lexer, int index, SimbolTable *st);
};
#endif //UNTITLED3_IFCOMMAND_H
