#include "race_track.h"
#include <iostream>
using namespace std;

void display_track(int position1, int position2, int position3, int rounds, char character1, char character2, char character3) {
    const int WIDTH = 57;
    const int HEIGHT = 27;

    char track[HEIGHT][WIDTH];

    // initialize all to spaces
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            track[i][j] = ' ';

    // top track
    for (int i = 0; i <= 2; i = i + 2) {
        for (int j = 0; j < WIDTH - 1; j = j + 4) {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][WIDTH - 1] = '+';
    }

    for (int j = 0; j < WIDTH; j = j + 4)
        track[1][j] = '|';

    // left and right tracks - vertical lines
    for (int i = 3; i < HEIGHT - 3; i = i + 2) {
        track[i][0] = '|';
        track[i][4] = '|';
        track[i][WIDTH - 5] = '|';
        track[i][WIDTH - 1] = '|';
    }

    // left track - horizontal lines
    for (int i = 4; i < HEIGHT - 3; i = i + 2) {
        track[i][0] = '+';
        track[i][1] = '-';
        track[i][2] = '-';
        track[i][3] = '-';
        track[i][4] = '+';
    }

    // right track - horizontal lines
    for (int i = 4; i < HEIGHT - 3; i = i + 2) {
        track[i][WIDTH - 5] = '+';
        track[i][WIDTH - 4] = '-';
        track[i][WIDTH - 3] = '-';
        track[i][WIDTH - 2] = '-';
        track[i][WIDTH - 1] = '+';
    }

    // bottom track
    for (int i = HEIGHT - 3; i < HEIGHT; i = i + 2) {
        for (int j = 0; j < WIDTH - 1; j = j + 4) {
            track[i][j] = '+';
            track[i][j + 1] = '-';
            track[i][j + 2] = '-';
            track[i][j + 3] = '-';
        }
        track[i][WIDTH - 1] = '+';
    }

    // initialize for next round
    for (int j = 0; j < WIDTH; j = j + 4)
        track[HEIGHT - 2][j] = '|';

    while (position1 >= 50)
        position1 -= 50;
    while (position2 >= 50)
        position2 -= 50;
    while (position3 >= 50)
        position3 -= 50;

    // racer 1
    if (position1 <= 13 && position1 >= 0) {
        int x;
        x = position1 * 4 + 1;
        track[25][x] = character1;
    } else if (position1 > 13 && position1 <= 25) {
        int x = 25 - ((position1 - 13) * 2);
        track[x][53] = character1;
    } else if (position1 > 25 && position1 < 38) {
        int x = 53 - (position1 - 25) * 4;
        track[1][x] = character1;
    } else if (position1 >= 38 && position1 < 50) {
        int x = (position1 - 38) * 2 + 1;
        track[x][1] = character1;
    }

    // racer 2
    if (position2 <= 13 && position2 >= 0) {
        int x;
        x = position2 * 4 + 2;
        track[25][x] = character2;
    } else if (position2 > 13 && position2 <= 25) {
        int x = 25 - ((position2 - 13) * 2);
        track[x][54] = character2;
    } else if (position2 > 25 && position2 < 38) {
        int x = 54 - (position2 - 25) * 4;
        track[1][x] = character2;
    } else if (position2 >= 38 && position2 < 50) {
        int x = (position2 - 38) * 2 + 1;
        track[x][2] = character2;
    }

    // racer 3
    if (position3 <= 13 && position3 >= 0) {
        int x;
        x = position3 * 4 + 3;
        track[25][x] = character3;
    } else if (position3 > 13 && position3 <= 25) {
        int x = 25 - ((position3 - 13) * 2);
        track[x][55] = character3;
    } else if (position3 > 25 && position3 < 38) {
        int x = 55 - (position3 - 25) * 4;
        track[1][x] = character3;
    } else if (position3 >= 38 && position3 < 50) {
        int x = (position3 - 38) * 2 + 1;
        track[x][3] = character3;
    }

    // display the track
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            cout << track[i][j];
        cout << endl;
    }
    cout << endl;
}

int update_current_round(int a, int b, int c) {
    if (a >= b && a >= c) return a / 50 + 1;
    if (b >= a && b >= c) return b / 50 + 1;
    return c / 50 + 1;
}
