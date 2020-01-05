//
// Created by noa on 07/11/2019.
//
// Include the string library
#include <set>
#include "Variable.h"

Variable::Variable(string nameVariable, double valueVariable){
    this->name = nameVariable;
    this->value = valueVariable;
}
double Variable::calculate() {
    return this->value;
}
Variable &Variable::operator++(){
    ++(this->value);
    return *this;
}
Variable &Variable::operator--(){
    --(this->value);
    return *this;
}
Variable &Variable::operator+=(double d) {
    this->value =  this->value + d;
    return *this;
}
Variable &Variable::operator-=(double d){
    this->value =  this->value - d;
    return *this;
}
Variable &Variable::operator++(int)  {
    ++(this->value);
    return *this;
}
Variable &Variable::operator--(int) {
    --(this->value);
    return *this;
}
string Variable::getName() {
    return this->name;
}
int Variable::getValue() {
    return this->value;
}
Variable::~Variable() {

}