//
// Created by noa on 11/11/2019.
//
#include "Value.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include <stack>
#include "Interpreter.h"
#include "Expression.h"
#include<string>
#include <queue>
#include "Variable.h"
#include <map>
#include <math.h>
#include "UPlus.h"
#include "UMinus.h"
#include "Bigger.h"
#include "BigOrEqual.h"
#include "Smaller.h"
#include "SmallOrEqual.h"
#include "Equal.h"
#include "UnEqual.h"


using namespace std;
//for the assign of the diffrent variable in the expressions
map<std::string, double> mapVariable;

Expression* Interpreter::interpret(string expression) {
    // stack to store operators.
    stack<char> ops;
    //for all the expression
    queue<string> outquence;
    string stringPassing;
    char passing;
    unsigned int i = 0;
    int countOpen = 0;
    int countClose = 0;
    string num;
    string stringVariable;
    while (i < expression.length()) {
        if (isdigit(expression[i])) {
            //turn from string to number
            num.assign(1, expression[i]);
            i++;
            //change
            while ((expression[i] != '-') && (expression[i] != '+') && (expression[i] != '*') &&
                   (expression[i] != '/') && (expression[i] != ')') && (expression[i] != '(')&&(expression[i]!='>')&&
                   (expression[i]!= '<')&&(expression[i]!='=') &&(expression[i]!='!')&&
                   (i<expression.length())) {
                if (isdigit(expression[i]) || (expression[i] == '.')) {
                    num = num + expression[i];
                    i++;
                } else {
                    throw ("unvalid expression");
                }
            }
            outquence.push(num);
        }
        //push to the outquence- the varible from the string
        if (isalpha(expression[i]) || expression[i] == '_') {
            stringVariable = expression[i];
            i++;
            while (isalpha(expression[i]) || expression[i] == '_' || isdigit(expression[i])) {
                stringVariable = stringVariable + expression[i];
                i++;
            }
            outquence.push(stringVariable);
        }
        if ((expression[i] == '-') && (isalpha(expression[i + 1]))) {
            throw ("unvalid expression");
        }
        int flag = 0;
        if ((expression[i] == '+') && ((i == 0) || (i != 0 && expression[i - 1] == '('))) {
            ops.push('&');
            flag = 1;
        }
        if ((expression[i] == '-') && ((i == 0) || (i != 0 && expression[i - 1] == '('))) {
            ops.push('%');
            flag = 1;
        }
        //push the operator according to the postfix
        //&-for UPlus
        //%- for UMinus
        if (((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*') || (expression[i] == '/')||
        (expression[i]=='>')||(expression[i]=='<')||((expression[i+1]=='=') &&((expression[i]=='<')
        ||(expression[i]=='>')||(expression[i]=='!')||expression[i]=='=')))&& (flag == 0)) {
            while ((!ops.empty()) &&
                   ((((expression[i] == '*' || (expression[i]) == '/') && (ops.top() == '*' || ops.top() == '/' ||
                       expression[i] == '%' || expression[i] == '&'))
                     || ((expression[i] == '+' || (expression[i]) == '-') &&
                         (ops.top() == '*' || ops.top() == '/' || ops.top() == '+' || ops.top() == '-'
                          || ops.top() == '&' || ops.top() == '%'||ops.top()=='>'||ops.top()=='<'||ops.top()=='='))||
                           ((expression[i]=='>'||expression[i]=='<'||expression[i]=='='||expression[i]=='!')&&
                                   (ops.top() == '*' || ops.top() == '/' || ops.top() == '+' || ops.top() == '-'
                                    || ops.top() == '&' || ops.top() == '%'||ops.top()=='>'||ops.top()=='<'||ops.top()=='=')))

                    && (expression[i] != '('))) {
                if (ops.top()=='=') {
                    passing = ops.top();
                    stringPassing.assign(1, passing);
                    ops.pop();
                    passing = ops.top();
                    stringPassing += passing;
                    ops.pop();
                }
                else{
                    passing = ops.top();
                    ops.pop();
                    stringPassing.assign(1, passing);
                    outquence.push(stringPassing);
                }
            }
            ops.push(expression[i]);
        }
        if (expression[i] == '(') {
            countOpen++;
            ops.push(expression[i]);
        }
        //enter all variables/numbers/operators between the parenthesis
        if (expression[i] == ')') {
            countClose++;
            while (ops.top() != '(') {
                passing = ops.top();
                stringPassing.assign(1, passing);
                outquence.push(stringPassing);
                ops.pop();
            }
            if (ops.top() == '(') {
                ops.pop();
            }
        }
        i++;
    }
    while (!ops.empty()) {
        passing = ops.top();
        stringPassing.assign(1, passing);
        outquence.push(stringPassing);
        ops.pop();
    }
    if (countClose != countOpen) {
        throw ("there is not a match between open and close Parenthesis");
    }
    //calculate the expression
    stack <Expression*> solvePostfix;
    Expression *exp1;
    Expression *exp2;
    while(!outquence.empty()) {
        double forNumber;
        string forVariable;
        i=0;
        string checkingType= outquence.front();
        outquence.pop();
        if(isdigit(checkingType[0])){
            //turn the string to number - to double
            forNumber=checkingType[0]-'0';
            i++;
            while(i < checkingType.length()){
                if (isalpha(checkingType[i])) {
                    throw("illegal variable");
                }
                if (checkingType[i] !='.'){
                    forNumber=forNumber*10+checkingType[i]-'0';
                    i++;
                }
                else {
                    i++;
                    int k=1;
                    while(i < checkingType.length()) {
                        //for numbers after the point
                        if (checkingType[i]!='.'){
                            forNumber=forNumber+(checkingType[i]-'0')*pow(10,-1*k);
                            k++;
                            i++;
                        }
                        else {
                            throw("unvalid number");
                        }
                    }
                }
            }
            solvePostfix.push(new Value(forNumber));
        }
        unsigned int j=0;
        if(((checkingType[0]) == '_')||(isalpha(checkingType[0]))) {
            //for create variable and push to the stack
            forVariable = checkingType[0];
            j++;
            while(j < checkingType.length()){
                forVariable=forVariable + checkingType[j];
                j++;
            }
            if(mapVariable.find(forVariable) == mapVariable.end()) {
                throw("the variable is not been set");
            }
            else {
                solvePostfix.push(new Variable(forVariable,mapVariable[forVariable]));
            }
        }
        //for preform unaryOperator and BinaryOperator
        else if(((checkingType[0]=='+')||(checkingType[0]=='-')||(checkingType[0]=='*')||
                (checkingType[0]=='/')||(checkingType[0]=='%')||(checkingType[0]=='&')||(checkingType[0]=='>')||
                (checkingType[0]=='<')||(checkingType[0]=='!')||(checkingType[0]=='='))&&(!solvePostfix.empty())) {
            if((checkingType[0]=='%')||(checkingType[0]=='&')){
                exp1 = solvePostfix.top();
                solvePostfix.pop();
            }
            else {
                exp1 = solvePostfix.top();
                solvePostfix.pop();
                if (!solvePostfix.empty()) {
                    exp2 = solvePostfix.top();
                    solvePostfix.pop();
                }
                else {
                    throw ("illegal math expression");
                }
            }
            string secondOp;
            switch (checkingType[0])
            {
                case '+': solvePostfix.push(new Plus(exp1,exp2));break;
                case '-': solvePostfix.push(new Minus(exp2,exp1));break;
                case '*': solvePostfix.push(new Mul(exp1,exp2));break;
                case '/': solvePostfix.push(new Div(exp2,exp1));break;
                case '>':
                    if(!outquence.empty()) {
                        secondOp= outquence.front();
                        if (secondOp[0]=='=') {
                            solvePostfix.push(new BigOrEqual(exp2,exp1));
                        }
                    }
                    else {
                        solvePostfix.push(new Bigger(exp2,exp1));
                    }
                    break;
                case '<':
                    if (!outquence.empty()) {
                        secondOp= outquence.front();
                        if (secondOp[0]=='=') {
                            solvePostfix.push(new SmallOrEqual(exp2,exp1));
                        }
                    }
                    else {
                        solvePostfix.push(new Smaller(exp2,exp1));
                    }
                    break;
                case '=': solvePostfix.push(new Equal(exp2,exp1));break;
                case '!': solvePostfix.push(new UnEqual(exp2,exp1));break;
                case '%': solvePostfix.push(new UMinus(exp1));break;
                case '&': solvePostfix.push(new UPlus(exp1));break;
                default:
                    break;
            }
        }
    }
    Expression* e= solvePostfix.top();
    return e;
}

void Interpreter::setVariables(string forAssign) {
    //for check if the sign is minus
    int flagForMinus = 0;
    unsigned int i = 0;
    double forNumber;
    while (i < forAssign.length() - 1) {
        //create the name of the variable
        string name = "";
        if (!(isalpha(forAssign[i])) && (forAssign[i] != '_')) {
            throw ("illegal variable");
        }
        while (forAssign[i] != '=' && i < forAssign.length()) {
            if (!(isalpha(forAssign[i])) && (forAssign[i] != '_') && (!(isdigit(forAssign[i])))) {
                throw ("illegal variable");
            } else {
                name = name + forAssign[i];
                i++;
            }
        }
        if (forAssign[i] == '=') {
            if (forAssign[i + 1] == '-') {
                flagForMinus = 1;
                i++;
            }
            //create the value of the variable
            if (isdigit(forAssign[i + 1])) {
                forNumber = forAssign[i + 1] - '0';
                i = i + 2;
                while ((forAssign[i] != ';') && (i < forAssign.length())) {
                    if ((forAssign[i] != '.') && (!isdigit((forAssign[i])))) {
                        throw ("illegal number");
                    }
                    if (forAssign[i] != '.') {
                        forNumber = forNumber * 10 + forAssign[i] - '0';
                        i++;
                    } else {
                        i++;
                        int k = 1;
                        while (forAssign[i] != ';' && i < forAssign.length()) {
                            if (!isdigit((forAssign[i]))) {
                                throw ("illegal number");
                            }
                            forNumber = forNumber + (forAssign[i] - '0') * pow(10, -1 * k);
                            k++;
                            i++;
                        }
                    }
                }
                if (flagForMinus == 1) {
                    forNumber = forNumber * -1;
                }
                mapVariable[name] = forNumber;
            } else {
                //if the assign of the variable is failed - we stop the program
                throw ("illegal variable assignment!");
            }
        }
        i++;
    }
}
