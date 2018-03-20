#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();

    // initial values for binary search variables
    int x1 = 0;
    int y1 = 0;
    int x2 = W - 1;
    int y2 = H - 1;

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();

        // This will be the comparisons used to judge where bound to move to
        if ((bombDir.find_first_of("U"))!=string::npos) {
            y2 = Y0 - 1;
        } else if ((bombDir.find_first_of("D"))!=string::npos) {
            y1 = Y0 + 1;
        }

        if ((bombDir.find_first_of("L"))!=string::npos) {
            x2 = X0 - 1;
        } else if ((bombDir.find_first_of("R"))!=string::npos) {
            x1 = X0 + 1;
        }

        // Recalculate mid points on both axis
        X0 = x1 + (x2 - x1) / 2;
        Y0 = y1 + (y2 - y1) / 2;

        cout << X0 << " " << Y0 << endl;
    }
}
