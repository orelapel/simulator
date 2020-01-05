//
// Created by noa on 07/11/2019.
//

#ifndef EX1_VALUE_H
#define EX1_VALUE_H

#include "Expression.h"

class Value: public Expression{
protected:
    double value;
public:
    Value(double num);
    double calculate();
    virtual ~Value();
};


#endif //EX1_VALUE_H
