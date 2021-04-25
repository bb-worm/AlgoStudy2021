#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int> > dungches;

int main() {

    int N;
    cin >> N;
    dungches.reserve(N);

    for (int i=0; i<N; i++) {
        int h, w;
        cin >> h >> w;
        dungches.push_back(make_pair(h, w));
    }

    vector<int> bigger_nums(N, 1);
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            if (dungches[i].first > dungches[j].first && dungches[i].second > dungches[j].second)
                bigger_nums[j] += 1;
            else if (dungches[i].first < dungches[j].first && dungches[i].second < dungches[j].second)
                bigger_nums[i] += 1;
        }
    }

    for (int i=0; i<N; i++){
        cout << bigger_nums[i] << " ";
    }
}