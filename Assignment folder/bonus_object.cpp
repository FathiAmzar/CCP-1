#include "bonus_object.h"

int getRandomSteps(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void applyBonusEffect(int& position, int& steps, const int& effect, int value) {
    if (effect == 1) {
        position += value;
    } else if (effect == 2) {
        position -= value;
    } else if (effect == 3) {
        steps *= 2;
    } else if (effect == 4) {
        steps += getRandomSteps(1, 6);
    }
}
