//
// Created by noa on 25/12/2019.
//

#include "Smaller.h"
#include <iostream>

//inherit the constructor from binary
Smaller::Smaller(Expression *leftExpression, Expression *rightExpression) : BinaryOperator (leftExpression,rightExpression) {}


//1 for true  and 0 for false
double Smaller::calculate() {
    if (left->calculate()<right->calculate()){
        return  1;
    }
    else {
        return 0;
    }
}

Smaller::~Smaller() {

}