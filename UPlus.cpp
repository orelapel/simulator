//
// Created by noa on 09/11/2019.
//

#include "UPlus.h"
UPlus::UPlus(Expression *expression):UnaryOperator(expression){}

double UPlus::calculate() {
    return exp->calculate();
}
UPlus::~UPlus() {

}