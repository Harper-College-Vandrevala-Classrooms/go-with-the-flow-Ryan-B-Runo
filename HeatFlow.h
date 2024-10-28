#include <map>
#include <string>

using namespace std;

#ifndef GO_WITH_THE_FLOW_RYAN_B_RUNO_HEATFLOW_H
#define GO_WITH_THE_FLOW_RYAN_B_RUNO_HEATFLOW_H

class HeatFlow {
private:
    map<int, float> sourcesAndSinks;
    float initialTemp;
    int sections;
    float K;
    map<int, float> rod;
public:
    HeatFlow(const map<int, float> &sourcesAndSinks, float initialTemp, int sections, float k);
    void tick();
    string prettyPrint();
};


#endif //GO_WITH_THE_FLOW_RYAN_B_RUNO_HEATFLOW_H
