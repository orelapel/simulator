//
// Created by noa on 25/12/2019.
//

#ifndef EX1_BIGOREQUAL_H
#define EX1_BIGOREQUAL_H


#include "Expression.h"
#include "BinaryOperator.h"
using namespace std;
class BigOrEqual:public BinaryOperator {
public:
    BigOrEqual(Expression *leftExpression, Expression *rightExpresion);
    double calculate();
    virtual ~BigOrEqual();
};


#endif //EX1_BIGOREQUAL_H
