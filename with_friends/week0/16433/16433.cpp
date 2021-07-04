#include <iostream>
#include <vector>

using namespace std;

void make_farm(vector<vector<char> >&, int, int, bool);
void print_farm(vector<vector<char> >&);

int main() {
    int N, R, C;
    cin >> N >> R >> C;
    R--;
    C--;
    vector<vector<char> > farm(N, vector<char>(N, '.'));

    make_farm(farm, R, C%2, true);
    make_farm(farm, R+1, (C+1)%2, false);

    print_farm(farm);
}

void make_farm(vector<vector<char> > &farm, int r, int c, bool is_upper) {
    if (r < 0 || r >= farm.size())
        return;

    for (; c<farm.size(); c+=2) 
        farm[r][c] = 'v';

    if (is_upper)
        make_farm(farm, r-1, (c+1)%2, is_upper);
    else
        make_farm(farm, r+1, (c+1)%2, is_upper);
}

void print_farm(vector<vector<char> > &farm) {
    for (int i=0; i<farm.size(); i++) {
        for (int j=0; j<farm.size(); j++) {
            printf("%c", farm[i][j]);
        }
        printf("\n");
    }
}