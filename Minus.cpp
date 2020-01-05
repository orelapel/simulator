//
// Created by noa on 09/11/2019.
//

#include "Minus.h"
Minus::Minus(Expression *leftExpression, Expression *rightExpression) : BinaryOperator (leftExpression,rightExpression) {}

double Minus::calculate() {
    return left->calculate() - right->calculate();
}
Minus::~Minus() {

}