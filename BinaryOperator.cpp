//
// Created by noa on 09/11/2019.
//

#include "BinaryOperator.h"

//Constructor
BinaryOperator:: BinaryOperator(Expression *leftExpression,Expression *rightExpression) {
    this->left= leftExpression;
    this->right = rightExpression;
}
//Destructor
BinaryOperator::~BinaryOperator() {
    delete this->left;
    delete this->right;
}