//
// Created by noa on 09/11/2019.
//

#ifndef EX1_UMINUS_H
#define EX1_UMINUS_H

#include "Expression.h"
#include "UnaryOperator.h"

class UMinus: public UnaryOperator {
public:
    UMinus(Expression *expression);
    double calculate();
    virtual ~UMinus();
};

#endif //EX1_UMINUS_H
