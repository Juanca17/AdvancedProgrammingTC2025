# Kata 6
###### Shadows of the Knight - Episode 1 (Codin Game)
### Context
Batman will look for the hostages on a given building by jumping from one window to another using his grapnel gun. Batman's goal is to jump to the window where the hostages are located in order to disarm the bombs. Unfortunately he has a limited number of jumps before the bombs go off...
### Input
**Line 1 :** 2 integers `W H`. The (`W`, `H`) couple represents the width and height of the building as a number of windows.

**Line 2 :** 1 integer `N`, which represents the number of jumps Batman can make before the bombs go off.

**Line 3 :** 2 integers `X0` `Y0`, representing the starting position of Batman.

### Output
A **single line** with 2 integers `X` `Y` separated by a space character. (`X`, `Y`) represents the location of the next window Batman should jump to. `X` represents the index along the horizontal axis, `Y` represents the index along the vertical axis. (0,0) is located in the top-left corner of the building.

### Constraints
1 ≤ `W` ≤ 10000  
1 ≤ `H` ≤ 10000  
2 ≤ `N` ≤ 100  
0 ≤ `X`, `X0` < W  
0 ≤ `Y`, `Y0` < H  
Response time per turn ≤ 150ms  
Response time per turn ≤ 150ms  

### Break Down
We have to find efficiently a specific point on a two dimensional space starting from a base coordinates. Each time we make a decision a feedback will be given to indicate ambiguously where to go. This seems similar to a **binary search**. In that algorithm we are given an array to look in; then we point three variables, one to the start and one to end of this array (creating then a searching area inside of them), and then another on the middle section between the last two. After comparing the value of the mid point, we can make the decision of selecting which bound to move so that the searching area looks in the good direction.

### Solution
```
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
```

### Analysis
This algorithm runs in O(log n) because there is no need to look on both of all spaces on the two dimensional array. As we reduce the checking options by a half on each iterations.

### Deployment
This code is part of the [Codin Game IDE](www.codingame.com), which is a platform of coding challenges that integrates programming problems with visual reference. To get this code running just copy and paste it on the [Shadows of the Knight - Episode 1](https://www.codingame.com/ide/puzzle/shadows-of-the-knight-episode-1) puzzle.
