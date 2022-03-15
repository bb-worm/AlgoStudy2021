#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


struct Genre {
    int total_play = 0;
    vector<pair<int, int>> play_id_vec;
};


vector<int> solution(vector<string> genres, vector<int> plays) {
    // make genre map
    unordered_map<string, Genre> genre_info;
    for (int i=0; i<genres.size(); ++i) {
        auto play = plays[i];
        genre_info[genres[i]].total_play += play;
        genre_info[genres[i]].play_id_vec.push_back({play, i});
    }

    // sort Genre
    vector<Genre> genres_uniq;
    for (auto& it : genre_info)
        genres_uniq.push_back(it.second);
    auto cmp_genre = [](const Genre& a, const Genre& b) { return a.total_play > b.total_play; };
    sort(genres_uniq.begin(), genres_uniq.end(), cmp_genre);

    // get ans
    vector<int> ans;
    auto cmp_play = [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; };
    for (auto& g : genres_uniq) {
        sort(g.play_id_vec.begin(), g.play_id_vec.end(), cmp_play); // sort plays in Genre
        
        ans.push_back(g.play_id_vec[0].second);
        if (g.play_id_vec.size() > 1)
            ans.push_back(g.play_id_vec[1].second);
    }

    return ans;
}

int main() {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    auto ans = solution(genres, plays);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}