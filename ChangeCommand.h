//
// Created by noa on 21/12/2019.
//

#ifndef SIMULATOR_CHANGECOMMAND_H
#define SIMULATOR_CHANGECOMMAND_H

#include "Command.h"
#include "SimbolTable.h"
using namespace std;
class ChangeCommand:public Command {
public:
    ~ChangeCommand(){

    }
    int execute (vector<string>lexer, int index, SimbolTable *st) {
        double newVal = 0;

        // check if the param contains math operator
        if (lexer[index+1].find('+') == std::string::npos&& lexer[index+1].find('-') == std::string::npos&&
            lexer[index+1].find('*') == std::string::npos&& lexer[index+1].find('/') == std::string::npos) {
            if  (st->varMap.find(lexer[index-1])!=st->varMap.end()){
                st->varMap.find(lexer[index-1])->second->setVal(stod(lexer[index+1]));
                newVal = stod(lexer[index+1]);
            }
            else {
                cerr<<"var not exist"<<endl;
            }
        } else {
            vector<string> variables;
            int j = 0;
            int flag;
            string wholeWord;
            string assign = lexer[index+1];

            // find the variables in the assign
            while (j < assign.length()) {
                wholeWord = "";
                flag = 0;
                while (j < assign.length() && assign[j] != '(' && assign[j] != ')' && assign[j] != '+' &&
                       assign[j] != '-' && assign[j] != '*' && assign[j] != '/'){
                    wholeWord = wholeWord + assign[j];
                    j++;
                    flag = 1;
                }
                if (isalpha(wholeWord[0])) {
                    variables.push_back(wholeWord);
                }
                if (flag == 0) {
                    j++;
                }
            }

            // build the set variables string
            string setVar;
            if (!variables.empty()) {
                for (std::vector<string>::iterator it = variables.begin(); it != variables.end(); ++it) {
                    setVar += (*it) + "=" + to_string(st->varMap[(*it)]->getVal());
                    if ((it + 1) != variables.end()) {
                        setVar = setVar + ";";
                    }
                }
            }

            // take care of the case -(-var)
            int flagVar=0;
            string newAssign = "";
            int k=0;
            int t=0;
            while (k<assign.length()) {
                if (assign[k]=='-' && isalpha(assign[k+1])){
                    newAssign = assign.substr(0, k+1)+ "(";
                    t=k+1;
                    string var="";
                    while(assign[t]!='+'&&assign[t]!='-'&& assign[t]!='*'&&assign[t]!='/'&&t<assign.length()) {
                        var =var+assign[t];
                        t++;
                        flagVar=1;
                    }
                    newAssign = newAssign + var + ")" +  assign.substr(t, assign.length() - 1);
                }
                if (flagVar==1) {
                    k=t;
                    flagVar=0;
                }
                else {
                    k++;
                }
            }

            // calculate the exp
            Interpreter *inter = new Interpreter();
            Expression *exp = nullptr;
            try {
                if (!variables.empty()) {
                    inter->setVariables(setVar);
                }
                if (newAssign!=""){
                     assign =newAssign;
                }
                exp = inter->interpret(assign);
                newVal = exp->calculate();
                delete exp;
                delete inter;
            } catch (const char *e) {
                if (exp != nullptr) {
                    delete exp;
                }
                if (inter != nullptr) {
                    delete inter;
                }
            }
        }

        // set the new value to the var
        map<string, InformationVar *>::iterator it;
        st->varMap[lexer[index - 1]]->setVal(newVal);

        // check if we need to change also in the simulator
        if (st->varMap[lexer[index - 1]]->getDir() == "->") {
            st->sets.push("set " + st->varMap[lexer[index - 1]]->getPath() + " " + to_string(newVal) + "\r\n");
        }
        return 2;
    }
};

#endif //SIMULATOR_CHANGECOMMAND_H
