//
// Created by noa on 09/11/2019.
//

#include "UMinus.h"
UMinus::UMinus(Expression *expression) :UnaryOperator(expression) {}

double UMinus::calculate() {
    return -exp->calculate();
}
UMinus::~UMinus() {

}