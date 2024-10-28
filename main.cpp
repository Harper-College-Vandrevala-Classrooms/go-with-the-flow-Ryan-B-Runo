
#include <iostream>
#include "HeatFlow.h"

int main(){
    map<int, float>s;
    s[0] = 1.1;
    s[3] = 1.5;
    HeatFlow h(s, 100, 10, 2);
    cout << h.prettyPrint() << endl;
}