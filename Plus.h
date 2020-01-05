//
// Created by noa on 09/11/2019.
//

#ifndef EX1_PLUS_H
#define EX1_PLUS_H

#include "Expression.h"
#include "BinaryOperator.h"


class Plus : public BinaryOperator {
    public:
    Plus(Expression *leftExpression, Expression *rightExpression);
    double calculate();
    virtual ~Plus();
};


#endif //EX1_PLUS_H
