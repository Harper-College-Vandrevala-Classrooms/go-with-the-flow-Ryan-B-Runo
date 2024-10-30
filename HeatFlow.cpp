#include "HeatFlow.h"
#include <stdexcept>
#include <iostream>
#include <vector>

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

int minIndex(map<int, float> m){//returns the maximum integer key in an (int, float) map
    int min;
    min = m.begin()->first;
    for(const auto &pair : m){
        if(pair.first < min){
            min = pair.first;
        }
    }
    return min;
}

HeatFlow::HeatFlow(const map<int, float> &sourcesAndSinks, float initialTemp, int sections, float K){
    if(sourcesAndSinks.size() > sections || maxIndex(sourcesAndSinks)+1 > sections || minIndex(sourcesAndSinks) < 0){//can't have more heat sources than sections of the rod and the source/sink map cant reference a position outside the length of the rod.
        throw invalid_argument("\nThe number of heat sources/sinks cannot be greater than the number of sections int the rod.\nThere cannot be a source/sink outside of the bounds of the rod.\nThere cannot be a source/sink before the zero position.");
    }else{
        this->sourcesAndSinks = sourcesAndSinks;
        this->sections = sections;
        this->initialTemp = initialTemp;
        this->K = K;
        for(int i = 0; i < sections; i++){
            if(sourcesAndSinks.count(i) != 0){//if the key exists, translate the source/sink to the rod.
                rod[i] = sourcesAndSinks.at(i);
            }else{//key does not exist, set to initial temp
                rod[i] = initialTemp;
            }
        }
    }
}

void HeatFlow::tick() {
    map<int, float> newRod;
    newRod = rod;
    for(const auto &pair : rod){
        if(sourcesAndSinks.count(pair.first) == 0){//if the point on the rod is not a source
            float past, leftPast, rightPast;
            if(pair.first != 0 && pair.first != rod.size()-1){//not at either end of rod
                past = rod.at(pair.first);
                leftPast = rod.at(pair.first-1);
                rightPast = rod.at(pair.first+1);
            }
            if(pair.first == 0){//at start of rod, has no left
                leftPast = this->initialTemp;

                past = rod.at(pair.first);
                rightPast = rod.at(pair.first+1);
            }
            if(pair.first == rod.size()-1){//at end of rod, has no right
                rightPast = this->initialTemp;

                past = rod.at(pair.first);
                leftPast = rod.at(pair.first-1);
            }
            newRod[pair.first] = (past +( this->K)*(rightPast - (2 * past) + leftPast));
        }
    }
    this->rod = newRod;
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
