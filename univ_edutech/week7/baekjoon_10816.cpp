#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    
    int N;
    scanf("%d", &N);
    
    unordered_map<int, int> card_map;
    int card;
    for (int i=0; i<N; i++) {
        scanf("%d", &card);
        if (card_map.find(card) == card_map.end())
            card_map[card] = 0;
        card_map[card]++;    
    }

    int M;
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d", &card);
        if (card_map.find(card) == card_map.end())
            printf("0 ");
        else
            printf("%d ", card_map[card]);
    }
}