#include<iostream>
#include<string.h>
#include<limits.h>
#include<algorithm>
using namespace std;
// https://atcoder.jp/contests/dp/tasks/dp_a

int stone[100000];
int cost[100000];

int bruteforce(int n) {
    if(n == 0) return 0;
    int cost = INT_MAX;

    cost = min(cost, bruteforce(n-1) + abs(stone[n-1] - stone[n]));
    if(n > 1)
        cost = min(cost, bruteforce(n-2) + abs(stone[n-2] - stone[n]));

    return cost;
}
int run(int n) {
    if(n == 1)  return 0;
    if(cost[n] != -1) return cost[n];

    return cost[n] = min(run(n-1)+abs(stone[n]-stone[n-1]), run(n-2)+abs(stone[n]-stone[n-2]));
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) 
        cin >> stone[i];

    memset(cost, -1, sizeof(int)*n);
    cout << bruteforce(n-1) << endl;
    return 0;
}