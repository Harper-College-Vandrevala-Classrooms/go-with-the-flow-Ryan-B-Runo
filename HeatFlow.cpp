#include "HeatFlow.h"
#include <stdexcept>
#include <iostream>

using namespace std;

int maxIndex(map<int, float> m){//returns the maximum integer key in an (int, float) map
    int max;
    max = m.begin()->first;
    for(const auto &pair : m){
        if(pair.first > max){
            max = pair.first;
        }
    }
    return max;
}

HeatFlow::HeatFlow(const map<int, float> &sourcesAndSinks, float initialTemp, int sections, float K){
    if(sourcesAndSinks.size() > sections || maxIndex(sourcesAndSinks) > sections){//can't have more heat sources than sections of the rod and the source/sink map cant reference a position outside the length of the rod.
        throw invalid_argument("The number of heat sources/sinks cannot be greater than the number of sections int the rod.");
    }else{
        this->sourcesAndSinks = sourcesAndSinks;
        this->sections = sections;
        this->initialTemp = initialTemp;
        this->K = K;
        for(int i = 0; i < maxIndex(sourcesAndSinks)+1; i++){//maxIndex is size-1 because of the 0 index
            if(sourcesAndSinks.count(i) != 0){//if the key exists, translate the source/sink to the rod.
                rod[i] = sourcesAndSinks.at(i);
            }else{//key does not exist, set to -1 for now##########################################################################################################
                rod[i] = -1;
            }
        }
    }
}

void HeatFlow::tick() {

}

string HeatFlow::prettyPrint() {//just prints the rod
    string res;
    string inner;

    for(const auto &pair : this->rod){
        inner += "(";
        inner += to_string(pair.second);
        inner += ") ";
    }

    res += "|-";
    for(int i = 0; i < inner.size() ; i++){
        res += "-";
    }
    res += "|\n| ";
    res += inner;
    res += "|\n|-";
    for(int i = 0; i < inner.size(); i++){
        res += "-";
    }
    res += "|";
    return res;
}
