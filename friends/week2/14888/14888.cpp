#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N;
vector<int> nums;
vector<int> opers;

int min_val = numeric_limits<int>::max();
int max_val = numeric_limits<int>::min();

void set_input();
void set_opers_and_find_ans(int, int);
int get_next_result(int, int, int);
void print_result();

int main() {

    set_input();
    set_opers_and_find_ans(1, nums[0]);
    print_result();
}

void set_input() {
    cin >> N;
    nums.reserve(N);
    int num;
    for (int i=0; i<N; i++) {
        cin >> num;
        nums.push_back(num);
    }
    int o;
    for (int i=0; i<4; i++) {
        cin >> o;
        opers.push_back(o);
    }
}

void print_result() {
    cout << max_val << endl << min_val << endl;
}

void set_opers_and_find_ans(int idx, int result) {
    if (idx >= N) {
        min_val = min(min_val, result);
        max_val = max(max_val, result);
        return;
    }

    for (int i=0; i<4; i++) {
        if (opers[i] == 0)
            continue;
        opers[i]--;
        int next_result = get_next_result(i, result, nums[idx]);
        set_opers_and_find_ans(idx+1, next_result);
        opers[i]++;
    }
}

int get_next_result(int oper, int A, int B) {
    if (oper == 0)
        return A+B;
    else if (oper == 1)
        return A-B;
    else if (oper == 2)
        return A*B;
    else {
        if (A >= 0)
            return (int)(A/B);
        else
            return ((int)(-1*A)/B)*(-1);
    }
}