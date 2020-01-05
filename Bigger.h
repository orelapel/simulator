//
// Created by noa on 25/12/2019.
//

#ifndef EX1_BIGGER_H
#define EX1_BIGGER_H

#include "Expression.h"
#include "BinaryOperator.h"
using namespace std;
class Bigger:public BinaryOperator {
public:
    Bigger(Expression *leftExpression, Expression *rightExpresion);
    double calculate();
    virtual ~Bigger();
};


#endif //EX1_BIGGER_H
