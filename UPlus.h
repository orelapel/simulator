//
// Created by noa on 09/11/2019.
//

#ifndef EX1_UPLUS_H
#define EX1_UPLUS_H
#include "Expression.h"
#include "UnaryOperator.h"

class UPlus: public UnaryOperator {
public:
    UPlus(Expression *expression);
    double calculate();
    virtual ~UPlus();
};

#endif //EX1_UPLUS_H
