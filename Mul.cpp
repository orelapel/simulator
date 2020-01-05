//
// Created by noa on 09/11/2019.
//

#include "Mul.h"

Mul::Mul(Expression *leftExpression, Expression *rightExpression) : BinaryOperator (leftExpression,rightExpression) {}

double Mul::calculate() {
    return  left -> calculate() * right->calculate();
}
Mul::~Mul() {

}