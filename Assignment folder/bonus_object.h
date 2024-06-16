#ifndef BONUS_OBJECT_H
#define BONUS_OBJECT_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int getRandomSteps(int min, int max);

class BonusObject {
public:
    int location;
    int effect;
    int value;

    BonusObject() : location(0), effect(0), value(0) {}
    BonusObject(int loc, int eff, int val) : location(loc), effect(eff), value(val) {}

    void applyBonusEffect(int& position, int& steps) const {
        switch (effect) {
            case 1: // Forward
                position += value;
                break;
            case 2: // Backward
                position -= value;
                break;
            case 3: // Double steps
                steps *= 2;
                break;
            case 4: // Extra turn
                steps += getRandomSteps(1, 9);
                break;
            default:
                break;
        }
    }
};

#endif
