//
// Created by noa on 09/11/2019.
//

#include "Div.h"
#include <iostream>

//inherit the constructor from binary
Div::Div(Expression *leftExpression, Expression *rightExpression) : BinaryOperator (leftExpression,rightExpression) {}


double Div::calculate() {
    if (right->calculate()!=0){
        return  left -> calculate() / right->calculate();
    }
    else {
        throw ("division by zero");
    }
}

Div::~Div() {

}