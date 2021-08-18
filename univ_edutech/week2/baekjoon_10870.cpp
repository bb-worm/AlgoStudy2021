#include <stdio.h>
#include <unordered_map>

using namespace std;

long long fibo(int n, unordered_map<int, long long>& fibo_map) {
    if (fibo_map.find(n) != fibo_map.end())
        return fibo_map.find(n)->second;
        
    if (n == 0 || n == 1)
        return n;
    else {
        return fibo_map[n] = fibo(n-1, fibo_map) + fibo(n-2, fibo_map);
    }
}

int main() {
    unordered_map<int, long long> fibo_map;
    int n;
    scanf("%d", &n);
    printf("%lld\n", fibo(n, fibo_map));
}