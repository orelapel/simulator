//
// Created by noa on 09/11/2019.
//

#ifndef EX1_UNARYOPERATOR_H
#define EX1_UNARYOPERATOR_H


#include "Expression.h"

class UnaryOperator : public Expression{
protected:
    Expression *exp;
public:
    UnaryOperator(Expression *expression);
    ~UnaryOperator();
};


#endif //EX1_UNARYOPERATOR_H
