#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Member {
    int age;
    string name;
};

int main() {
    int N;
    cin >> N;

    vector<Member> members;

    // make members
    int age;
    string name;
    for (int i=0; i<N; i++) {
        cin >> age >> name;
        members.push_back({age, name});
    }

    // fill ages
    int age_cnt[201] = {0, };
    for (int i=0; i<N; i++)
        age_cnt[members[i].age]++;
    
    // accumulate age - for stable sort
    for (int i=1; i<=200; i++)
        age_cnt[i] += age_cnt[i-1];

    // decide member order
    vector<Member*> sorted_members;
    int idx;
    sorted_members.resize(N);
    for (int i=N-1; i>=0; i--) {
        age = members[i].age;
        age_cnt[age]--;
        idx = age_cnt[age];
        sorted_members[idx] = &members[i];
    }

    // print
    for (int i=0; i<N; i++) {
        cout << sorted_members[i]->age << " " << sorted_members[i]->name << "\n";
    }
}