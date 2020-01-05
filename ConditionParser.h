//
// Created by orelapel on 25.12.2019.
//

#ifndef UNTITLED3_CONDITIONPARSER_H
#define UNTITLED3_CONDITIONPARSER_H

#include <unordered_map>
#include "Command.h"
#include "Interpreter.h"

using namespace std;

class ConditionParser : public Command {
public:
    ~ConditionParser() {

    }
    unordered_map<string, Command *> commandMap;
    int condition = 0;
    int i = 0;

    void initCondition(vector<string> lexer, int index, SimbolTable *symbolTable);

    void makeMap();

    virtual int execute(vector<string> lexer, int index, SimbolTable *st) {

    }
};

#endif //UNTITLED3_CONDITIONPARSER_H
