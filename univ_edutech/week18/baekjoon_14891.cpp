#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;


struct Gear {
    string status;
    int top = 0;
};

void rotate_gear(Gear& gear, int dir) {
    if (dir == 1)
        gear.top = (gear.top + 7) % 8;
    else if (dir == -1)
        gear.top = (gear.top + 1) % 8; 
}

char left(const Gear& gear) {
    return gear.status[(gear.top + 6) % 8];
}

char right(const Gear& gear) {
    return gear.status[(gear.top + 2) % 8];
}

int get_point(const Gear& gear) {
    if (gear.status[gear.top] == '0')
        return 0;
    return 1;
}

void rotate_gears(vector<Gear>& gears, int start, int dir) {
    vector<int> rotate_dir(4);
    rotate_dir[start] = dir;

    // check left
    for (int i=start-1; i>=0; i--) {
        auto& now = gears[i];
        auto& right_gear = gears[i+1];
        if (right(now) == left(right_gear))
            break;
        rotate_dir[i] = rotate_dir[i+1] * -1;
    }

    // check right
    for (int i=start+1; i<4; i++) {
        auto& now = gears[i];
        auto& left_gear = gears[i-1];
        if (right(left_gear) == left(now))
            break;
        rotate_dir[i] = rotate_dir[i-1] * -1;
    }

    // rotate
    for (int i=0; i<4; i++) {
        rotate_gear(gears[i], rotate_dir[i]);
    }
}

int main() {
    // set gears
    vector<Gear> gears(4);
    for (int i=0; i<4; i++) {
        cin >> gears[i].status;
    }

    // rotate gears
    int k;
    cin >> k;
    for (int i=0; i<k; i++) {
        int start, dir;
        cin >> start >> dir;
        rotate_gears(gears, start-1, dir);
    }

    // cal point
    int ans = 0;
    for (int i=0; i<4; i++)
        ans += get_point(gears[i]) * (pow(2, i));
    cout << ans;
}