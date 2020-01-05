//
// Created by noa on 09/11/2019.
//

#include "UnaryOperator.h"

//constructor
UnaryOperator:: UnaryOperator(Expression *expression) {
    this->exp =expression;
}
//Destructor
UnaryOperator::~UnaryOperator() {
    delete this->exp;
}