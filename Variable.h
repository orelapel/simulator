//
// Created by noa on 07/11/2019.
//

#ifndef EX1_VARIABLE_H
#define EX1_VARIABLE_H


#include <string>
#include "Expression.h"

class Variable : public Expression{
protected:
    string name;
    double value;
public:
    Variable(string nameVariable, double valueVariable);
    double calculate();
    Variable& operator++();
    Variable& operator--();
    Variable& operator+=(double d);
    Variable& operator-=(double d);
    Variable& operator++(int);
    Variable& operator--(int);
    string getName();
    int getValue();
    virtual ~Variable();
};


#endif //EX1_VARIABLE_H
