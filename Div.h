//
// Created by noa on 09/11/2019.
//

#ifndef EX1_DIV_H
#define EX1_DIV_H


#include "Expression.h"
#include "BinaryOperator.h"

class Div: public BinaryOperator {
public:
    Div(Expression *leftExpression, Expression *rightExpresion);
    double calculate();
    virtual ~Div();
};



#endif //EX1_DIV_H
