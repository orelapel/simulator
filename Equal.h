//
// Created by noa on 25/12/2019.
//

#ifndef EX1_EQUAL_H
#define EX1_EQUAL_H

#include "Expression.h"
#include "BinaryOperator.h"

class Equal:public BinaryOperator {
public:
    Equal(Expression *leftExpression, Expression *rightExpresion);
    double calculate();
    virtual ~Equal();
};


#endif //EX1_EQUAL_H
