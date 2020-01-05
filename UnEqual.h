//
// Created by noa on 25/12/2019.
//

#ifndef EX1_UNEQUAL_H
#define EX1_UNEQUAL_H

#include "Expression.h"
#include "BinaryOperator.h"

class UnEqual:public BinaryOperator {
public:
    UnEqual(Expression *leftExpression, Expression *rightExpresion);
    double calculate();
    virtual ~UnEqual();
};



#endif //EX1_UNEQUAL_H
