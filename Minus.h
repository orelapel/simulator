//
// Created by noa on 09/11/2019.
//

#ifndef EX1_MINUS_H
#define EX1_MINUS_H

#include "Expression.h"
#include "BinaryOperator.h"

class Minus: public BinaryOperator {
public:
    Minus(Expression *leftExpression, Expression *rightExpression);
    double calculate();
    virtual ~Minus();
};


#endif //EX1_MINUS_H
