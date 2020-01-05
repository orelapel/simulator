//
// Created by noa on 11/11/2019.
//

#ifndef EX1_INTERPRETER_H
#define EX1_INTERPRETER_H
#include<iostream>
#include<string>
#include "Expression.h"
#include <map>

using namespace std;
class Interpreter {
private:
    map<std::string, double> mapVariable;
public:
    Expression* interpret(string expression);
    void setVariables(string forAssign);
};


#endif //EX1_INTERPRETER_H
