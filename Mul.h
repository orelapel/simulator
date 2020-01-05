//
// Created by noa on 09/11/2019.
//

#ifndef EX1_MUL_H
#define EX1_MUL_H


#include "Expression.h"
#include "BinaryOperator.h"

class Mul: public BinaryOperator {
public:
    Mul(Expression *leftExpression, Expression *rightExpression);
    double calculate();
    virtual ~Mul();
};



#endif //EX1_MUL_H
