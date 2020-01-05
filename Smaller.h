//
// Created by noa on 25/12/2019.
//

#ifndef EX1_SMALLER_H
#define EX1_SMALLER_H

#include "Expression.h"
#include "BinaryOperator.h"

class Smaller:public BinaryOperator {
public:
    Smaller(Expression *leftExpression, Expression *rightExpresion);
    double calculate();
    virtual ~Smaller();
};



#endif //EX1_SMALLER_H
