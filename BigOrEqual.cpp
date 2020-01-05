//
// Created by noa on 25/12/2019.
//

#include "BigOrEqual.h"
#include <iostream>

//inherit the constructor from binary
BigOrEqual::BigOrEqual(Expression *leftExpression, Expression *rightExpression) : BinaryOperator (leftExpression,rightExpression) {}


//1 for true  and 0 for false
double BigOrEqual::calculate() {
    if (left->calculate()>=right->calculate()){
        return  1;
    }
    else {
        return 0;
    }
}

BigOrEqual::~BigOrEqual() {

}