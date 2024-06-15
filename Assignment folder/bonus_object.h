#ifndef BONUS_OBJECT_H
#define BONUS_OBJECT_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class BonusObject {
public:
    int location;
    int effect;
    int value;

    BonusObject(int loc, int eff, int val) : location(loc), effect(eff), value(val) {}
};

void applyBonusEffect(int& position, int& steps, const int& effect, int value);
int getRandomSteps(int min, int max);

#endif
