//
// Created by noa on 09/11/2019.
//

#include "Plus.h"

Plus::Plus(Expression *leftExpression, Expression *rightExpression) : BinaryOperator (leftExpression,rightExpression) {}

double Plus::calculate() {
    return  left -> calculate() + right->calculate();
}
Plus::~Plus() {

}
