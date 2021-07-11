#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Gear {
private:
    string gear;
    int topidx = 0;
public:
    void set_gear(string);
    int get_top();
    int get_left();
    int get_right();
    void rotate_clockwise();
    void rotate_counterclockwise();
};

void Gear::set_gear(string gear) {
    this->gear = gear;
}
int Gear::get_top() {
    return gear[topidx];
}
int Gear::get_left() {
    return gear[(topidx + 6) % 8];
}
int Gear::get_right() {
    return gear[(topidx + 2) % 8];
}
void Gear::rotate_clockwise() {
    topidx = (topidx + 7) % 8;
}
void Gear::rotate_counterclockwise() {
    topidx = (topidx + 1) % 8;
}

Gear gears[4];
int K;

void set_input();
void rotate_all(int[]);
int cal_total_score();

int main() {
    ios_base::sync_with_stdio(0);
    set_input();

    int n, dir;
    for (int i=0; i<K; i++) {
        cin >> n >> dir;
        n--;
        int rotate[4] = {0, 0, 0, 0};
        rotate[n] = dir;
        for (int left=n-1; left>=0; left--) {
            if (gears[left].get_right() == gears[left+1].get_left())
                break;
            rotate[left] = rotate[left+1] * -1;
        }
        for (int right=n+1; right<4; right++) {
            if (gears[right].get_left() == gears[right-1].get_right())
                break;
            rotate[right] = rotate[right-1] * -1;
        }
        rotate_all(rotate);
    }
    int ans = cal_total_score();
    cout << ans << endl;
}

void set_input() {
    for (int i=0; i<4; i++) {
        string gear;
        cin >> gear;
        gears[i].set_gear(gear);
    }
    cin >> K;
}

void rotate_all(int rotate[]) {
    for (int i=0; i<4; i++) {
        if (rotate[i] == 1)
            gears[i].rotate_clockwise();
        else if (rotate[i] == -1)
            gears[i].rotate_counterclockwise();
    }
}

int cal_total_score() {
    int total_score = 0;
    for (int i=0; i<4; i++) {
        if (gears[i].get_top() == '1')
            total_score += pow(2, i);
    }
    return total_score;
}