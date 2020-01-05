//
// Created by noa on 25/12/2019.
//

#include "Bigger.h"
#include <iostream>

//inherit the constructor from binary
Bigger::Bigger(Expression *leftExpression, Expression *rightExpression) : BinaryOperator (leftExpression,rightExpression) {}


//1 for true  and 0 for false
double Bigger::calculate() {
    if (left->calculate()>right->calculate()){
        return  1;
    }
    else {
        return 0;
    }
}

Bigger::~Bigger() {

}