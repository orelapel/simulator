//
// Created by noa on 09/11/2019.
//

#ifndef EX1_BINARYOPERATOR_H
#define EX1_BINARYOPERATOR_H


#include "Expression.h"
using namespace std;
class BinaryOperator : public Expression{
protected:
    Expression *right;
    Expression *left;
public:
    BinaryOperator(Expression *leftExpression, Expression *rightExpression);
    ~BinaryOperator();
};


#endif //EX1_BINARYOPERATOR_H
