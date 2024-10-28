#include "HeatFlow.h"

HeatFlow::HeatFlow(const map<int, float> &sourcesAndSinks, float initialTemp, int sections, float k) : sourcesAndSinks(
        sourcesAndSinks), initialTemp(initialTemp), sections(sections), K(k) {}

void HeatFlow::tick() {

}

string HeatFlow::prettyPrint() {
    return std::string();
}
