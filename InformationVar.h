//
// Created by noa on 21/12/2019.
//

#ifndef SIMULATOR_INFORMATIONVAR_H
#define SIMULATOR_INFORMATIONVAR_H
#include <string>

using namespace std;

class InformationVar {
private :
    double value;
    string path;
    string direction;
public:
    ~InformationVar() {

    }
    InformationVar(double v,string dir,string p) {
        value = v;
        direction = dir;
        path = p;
    }
    void setVal(double updateValue) {
        value=updateValue;
    }
    void setDir(string dir) {
        direction = dir;
    }
    string getDir(){
        return direction;
    }

    double getVal(){
        return value;
    }
    string getPath() {
        return path;
    }
};
#endif //SIMULATOR_INFORMATIONVAR_H
