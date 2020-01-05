//
// Created by noa on 22/12/2019.
//

#ifndef SIMULATOR_SIMBOLTABLE_H
#define SIMULATOR_SIMBOLTABLE_H
#include <string>
#include <map>
#include "InformationVar.h"
#include <queue>

using namespace std;

class SimbolTable {
public:
    map<string, InformationVar*> varMap;
    map<string, InformationVar*> simMap;
    map<int, string> numSimMap;
    queue <string> sets;
    bool dontstop = true;
    SimbolTable() {

    }
    ~SimbolTable() {
        map<string, InformationVar*>::iterator it;
        for ( it = simMap.begin(); it != simMap.end(); it++ ) {
            delete (*it).second;
        }
        for ( it = varMap.begin(); it != varMap.end(); it++ ) {
            delete (*it).second;
        }
    }
    void createMapForSimulatorInfo() {
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/airspeed-indicator/indicated-speed-kt",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/airspeed-indicator/indicated-speed-kt")));
        simMap.insert(
                std::pair<string, InformationVar *>("/sim/time/warp", new InformationVar(0, "", "/sim/time/warp")));;
        simMap.insert(std::pair<string, InformationVar *>("/controls/switches/magnetos",
                                                          new InformationVar(0, "", "/controls/switches/magnetos")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/heading-indicator/offset-deg",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/heading-indicator/offset-deg")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/altimeter/indicated-altitude-ft",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/altimeter/indicated-altitude-ft")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/altimeter/pressure-alt-ft",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/altimeter/pressure-alt-ft")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/attitude-indicator/indicated-pitch-deg",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/attitude-indicator/indicated-pitch-deg")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/attitude-indicator/indicated-roll-deg",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/attitude-indicator/indicated-roll-deg")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/attitude-indicator/internal-pitch-deg",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/attitude-indicator/internal-pitch-deg")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/attitude-indicator/internal-roll-deg",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/attitude-indicator/internal-roll-deg")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/encoder/indicated-altitude-ft",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/encoder/indicated-altitude-ft")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/encoder/pressure-alt-ft",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/encoder/pressure-alt-ft")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/gps/indicated-altitude-ft",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/gps/indicated-altitude-ft")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/gps/indicated-ground-speed-kt",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/gps/indicated-ground-speed-kt")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/gps/indicated-vertical-speed",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/gps/indicated-vertical-speed")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/heading-indicator/indicated-heading-deg",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/heading-indicator/indicated-heading-deg")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/magnetic-compass/indicated-heading-deg",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/magnetic-compass/indicated-heading-deg")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/slip-skid-ball/indicated-slip-skid",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/slip-skid-ball/indicated-slip-skid")));
        simMap.insert(std::pair<string, InformationVar *>("/instrumentation/turn-indicator/indicated-turn-rate",
                                                          new InformationVar(0, "",
                                                                             "/instrumentation/turn-indicator/indicated-turn-rate")));
        simMap.insert(
                std::pair<string, InformationVar *>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                                    new InformationVar(0, "",
                                                                       "/instrumentation/vertical-speed-indicator/indicated-speed-fpm")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/flight/aileron",
                                                          new InformationVar(0, "", "/controls/flight/aileron")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/flight/elevator",
                                                          new InformationVar(0, "", "/controls/flight/elevator")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/flight/rudder",
                                                          new InformationVar(0, "", "/controls/flight/rudder")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/flight/flaps",
                                                          new InformationVar(0, "", "/controls/flight/flaps")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/engines/engine/throttle", new InformationVar(0, "",
                                                                                                                  "/controls/engines/engine/throttle")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/engines/current-engine/throttle",
                                                          new InformationVar(0, "",
                                                                             "/controls/engines/current-engine/throttle")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/switches/master-avionics",
                                                          new InformationVar(0, "",
                                                                             "/controls/switches/master-avionics")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/switches/starter",
                                                          new InformationVar(0, "", "/controls/switches/starter")));
        simMap.insert(std::pair<string, InformationVar *>("/engines/active-engine/auto-start", new InformationVar(0, "",
                                                                                                                  "/engines/active-engine/auto-start")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/flight/speedbrake",
                                                          new InformationVar(0, "", "/controls/flight/speedbrake")));
        simMap.insert(std::pair<string, InformationVar *>("/sim/model/c172p/brake-parking",
                                                          new InformationVar(0, "", "/sim/model/c172p/brake-parking")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/engines/engine/primer", new InformationVar(0, "",
                                                                                                                "/controls/engines/engine/primer")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/engines/current-engine/mixture",
                                                          new InformationVar(0, "",
                                                                             "/controls/engines/current-engine/mixture")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/switches/master-bat",
                                                          new InformationVar(0, "", "/controls/switches/master-bat")));
        simMap.insert(std::pair<string, InformationVar *>("/controls/switches/master-alt",
                                                          new InformationVar(0, "", "/controls/switches/master-alt")));
        simMap.insert(std::pair<string, InformationVar *>("/engines/engine/rpm",
                                                          new InformationVar(0, "", "/engines/engine/rpm")));
    }
    void createNumberedMapForSim() {
        numSimMap.insert(std::pair<int, string>(1,"/instrumentation/airspeed-indicator/indicated-speed-kt"));
        numSimMap.insert(std::pair<int, string>(2,"/sim/time/warp"));
        numSimMap.insert(std::pair<int, string>(3,"/controls/switches/magnetos"));
        numSimMap.insert(std::pair<int, string>(4,"/instrumentation/heading-indicator/offset-deg"));
        numSimMap.insert(std::pair<int, string>(5,"/instrumentation/altimeter/indicated-altitude-ft"));
        numSimMap.insert(std::pair<int, string>(6,"/instrumentation/altimeter/pressure-alt-ft"));
        numSimMap.insert(std::pair<int, string>(7,"/instrumentation/attitude-indicator/indicated-pitch-deg"));
        numSimMap.insert(std::pair<int, string>(8,"/instrumentation/attitude-indicator/indicated-roll-deg"));
        numSimMap.insert(std::pair<int, string>(9,"/instrumentation/attitude-indicator/internal-pitch-deg"));
        numSimMap.insert(std::pair<int, string>(10,"/instrumentation/attitude-indicator/internal-roll-deg"));
        numSimMap.insert(std::pair<int, string>(11,"/instrumentation/encoder/indicated-altitude-ft"));
        numSimMap.insert(std::pair<int, string>(12,"/instrumentation/encoder/pressure-alt-ft"));
        numSimMap.insert(std::pair<int, string>(13,"/instrumentation/gps/indicated-altitude-ft"));
        numSimMap.insert(std::pair<int, string>(14,"/instrumentation/gps/indicated-ground-speed-kt"));
        numSimMap.insert(std::pair<int, string>(15,"/instrumentation/gps/indicated-vertical-speed"));
        numSimMap.insert(std::pair<int, string>(16,"/instrumentation/heading-indicator/indicated-heading-deg"));
        numSimMap.insert(std::pair<int, string>(17,"/instrumentation/magnetic-compass/indicated-heading-deg"));
        numSimMap.insert(std::pair<int, string>(18,"/instrumentation/slip-skid-ball/indicated-slip-skid"));
        numSimMap.insert(std::pair<int, string>(19,"/instrumentation/turn-indicator/indicated-turn-rate"));
        numSimMap.insert(std::pair<int, string>(20,"/instrumentation/vertical-speed-indicator/indicated-speed-fpm"));
        numSimMap.insert(std::pair<int, string>(21,"/controls/flight/aileron"));
        numSimMap.insert(std::pair<int, string>(22,"/controls/flight/elevator"));
        numSimMap.insert(std::pair<int, string>(23,"/controls/flight/rudder"));
        numSimMap.insert(std::pair<int, string>(24,"/controls/flight/flaps"));
        numSimMap.insert(std::pair<int, string>(25,"/controls/engines/engine/throttle"));
        numSimMap.insert(std::pair<int, string>(26,"/controls/engines/current-engine/throttle"));
        numSimMap.insert(std::pair<int, string>(27,"/controls/switches/master-avionics"));
        numSimMap.insert(std::pair<int, string>(28,"/controls/switches/starter"));
        numSimMap.insert(std::pair<int, string>(29,"/engines/active-engine/auto-start"));
        numSimMap.insert(std::pair<int, string>(30,"/controls/flight/speedbrake"));
        numSimMap.insert(std::pair<int, string>(31,"/sim/model/c172p/brake-parking"));
        numSimMap.insert(std::pair<int, string>(32,"/controls/engines/engine/primer"));
        numSimMap.insert(std::pair<int, string>(33,"/controls/engines/current-engine/mixture"));
        numSimMap.insert(std::pair<int, string>(34,"/controls/switches/master-bat"));
        numSimMap.insert(std::pair<int, string>(35,"/controls/switches/master-alt"));
        numSimMap.insert(std::pair<int, string>(36,"/engines/engine/rpm"));
    }
};



#endif //SIMULATOR_SIMBOLTABLE_H
