#include<iostream>
#include<set>
using namespace std;
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/

int parent[10000];
int size_set[10000];
multiset<int> sizes;    // for keeping all the sizes of sets/parents

void make_set(int v) {
    parent[v] = v;
    size_set[v] = 1;
}

int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void merge(int a, int b) {
    sizes.erase(sizes.find(size_set[a]));
    sizes.erase(sizes.find(size_set[b]));

    sizes.insert(size_set[a] + size_set[b]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(size_set[a] < size_set[b])
            std::swap(a, b);
        merge(a, b);
        size_set[a] += size_set[b];
        parent[b] = a;
    }
}

int main(void) {
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; ++i) {
        make_set(i);
        sizes.insert(1);
    }
    while(q--) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
        if(sizes.size() == 0) {
            cout << 0;
        } else {
            int min = *(sizes.begin());
            int max = *(--sizes.end());
            cout << max - min << endl;
        }
    }
    return 0;
}