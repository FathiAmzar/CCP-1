#include <iostream>
#include <vector>
#include <ctime>
#include "bonus_object.h"
#include "race_track.h"

using namespace std;

int main() {
    srand(time(0));

    int enterpriseTrack = 0;
    int voyagerTrack = 0;
    int sonicTrack = 0;
    int current_round = 1, rounds = 1, finish;

    vector<BonusObject> bonuses;

    cout << "***************************************************************************" << endl;
    cout << "This game consist of 3 racers." << endl;
    cout << "Player need to press enter to start a turn." << endl;
    cout << "Player must put the bonus object on the track at the beginning of the game." << endl;
    cout << "***************************************************************************" << endl;

    cout << "\nEnter the number of the rounds: ";
    cin >> rounds;
    finish = rounds * 50;

    cout << "Enter the number of bonus objects (2-6): ";
    int bonusCount;
    cin >> bonusCount;
    if (bonusCount < 2) bonusCount = 2;
    if (bonusCount > 6) bonusCount = 6;

    cout << "bonus objects is set to " << bonusCount << endl;

    for (int i = 0; i < bonusCount; ++i) {
        int location;
        int effect;
        int value;

        cout << "\nEnter location for bonus object " << i + 1 << " (1-49): ";
        cin >> location;
        while (location < 1 || location > 49) {
            cout << "Invalid location. Enter location for bonus object " << i + 1 << " (1-49): ";
            cin >> location;
        }

        cout << "Choose effect. \n1.forward \n2.backward \n3.double \n4.bonus turn\n";
        cin >> effect;
        while (effect < 1 || effect > 4) {
            cout << "Invalid effect type. Choose effect. \n1. forward \n2. backward \n3. double \n4. bonus turn: ";
            cin >> effect;
        }

        cout << "Enter value of the effect chosen: ";
        cin >> value;

        bonuses.push_back(BonusObject(location, effect, value));
    }

    cin.ignore(); // prevent race to start after entering round value
    cout << "\nPress Enter to start the race\n";

    while (true) {
        cin.ignore();
        cin.get(); // Wait for user to press Enter

        // Generate random steps for Enterprise, Voyager, and Sonic
        int enterpriseStep = getRandomSteps(1, 6);
        int voyagerStep = getRandomSteps(2, 5);
        int sonicStep = getRandomSteps(0, 7);

        // Apply any collected bonus objects before moving
        for (BonusObject& bonus : bonuses) {
            if (enterpriseTrack % 50 == bonus.location) {
                applyBonusEffect(enterpriseTrack, enterpriseStep, bonus.effect, bonus.value);
            }
            if (voyagerTrack % 50 == bonus.location) {
                applyBonusEffect(voyagerTrack, voyagerStep, bonus.effect, bonus.value);
            }
            if (sonicTrack % 50 == bonus.location) {
                applyBonusEffect(sonicTrack, sonicStep, bonus.effect, bonus.value);
            }
        }

        // Update track positions
        enterpriseTrack += enterpriseStep;
        voyagerTrack += voyagerStep;
        sonicTrack += sonicStep;

        // Display track
        display_track(enterpriseTrack, voyagerTrack, sonicTrack, rounds, 'e', 'v', 's');

        // Display current track positions and steps taken
        cout << "Current round: " << current_round << "/" << rounds << endl;
        cout << "\n";
        cout << "Enterprise current track: " << enterpriseTrack << endl;
        cout << "Voyager current track: " << voyagerTrack << endl;
        cout << "Sonic current track: " << sonicTrack << endl;
        cout << "\n";
        cout << "Enterprise step: " << enterpriseStep << endl;
        cout << "Voyager step: " << voyagerStep << endl;
        cout << "Sonic step: " << sonicStep << endl;

        // Check if any racer has reached the finish line
        if (enterpriseTrack >= finish && voyagerTrack >= finish && sonicTrack >= finish) {
            cout << "It's a tie between all racers!" << endl;
            break;
        } else if (enterpriseTrack >= finish && voyagerTrack >= finish) {
            cout << "It's a tie between Voyager and Enterprise!" << endl;
            break;
        } else if (enterpriseTrack >= finish && sonicTrack >= finish) {
            cout << "It's a tie between Sonic and Enterprise!" << endl;
            break;
        } else if (voyagerTrack >= finish && sonicTrack >= finish) {
            cout << "It's a tie between Voyager and Sonic" << endl;
            break;
        } else if (enterpriseTrack >= finish) {
            cout << "Enterprise wins!" << endl;
            break;
        } else if (voyagerTrack >= finish) {
            cout << "Voyager wins!" << endl;
            break;
        } else if (sonicTrack >= finish) {
            cout << "Sonic wins!" << endl;
            break;
        } else {
            cout << "\nPress Enter for the next turn\n";
        }
    }

    return 0;
}
