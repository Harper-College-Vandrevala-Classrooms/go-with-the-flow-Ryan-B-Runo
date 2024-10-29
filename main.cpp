#include <iostream>
#include "HeatFlow.h"

int main(){
    map<int, float> sources_and_sinks;
    sources_and_sinks[0] = 100.0;
    float initial_temperature = 10;
    int number_of_sections = 5;
    float K = 0.1;

    HeatFlow h(sources_and_sinks, initial_temperature, number_of_sections, K);
    //cout << h.prettyPrint() << endl;

// Prints out:
// +------+------+------+------+------+
// | 100  |  10  |  10  |  10  |  10  |
// +------+------+------+------+------+

    h.tick();
    cout << h.prettyPrint() << endl;

// Prints out:
// +------+------+------+------+------+
// | 100  |  19  |  10  |  10  |  10  |
// +------+------+------+------+------+

    h.tick();
    //cout << h.prettyPrint() << endl;

// Prints out:
// +------+--------+--------+------+------+
// | 100  |  26.2  |  10.9  |  10  |  10  |
// +------+--------+--------+------+------+
}