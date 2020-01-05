//
// Created by noa on 25/12/2019.
//

#ifndef EX1_SMALLOREQUAL_H
#define EX1_SMALLOREQUAL_H

#include "Expression.h"
#include "BinaryOperator.h"

class SmallOrEqual:public BinaryOperator {
public:
    SmallOrEqual(Expression *leftExpression, Expression *rightExpresion);
    double calculate();
    virtual ~SmallOrEqual();
};



#endif //EX1_SMALLOREQUAL_H
