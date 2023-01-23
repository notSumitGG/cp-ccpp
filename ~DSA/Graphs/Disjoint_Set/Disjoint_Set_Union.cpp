#include<iostream>
#include<valarray>

class dsu {
public:
    int parent[10000];
    // non made elements = 0
    // leader elements = -size
    // set elements = parent element
    void make_set(int key) {
        parent[key] = -1;
    }

    // finds root of the specified key
    int find_root(int key) {
        if(parent[key] < 0) return key;
        // path compression
        return parent[key] = find_root(parent[key]);
    }

    // merges two sets
    void union_sets(int k1, int k2) {
        k1 = find_root(k1);
        k2 = find_root(k2);
        
        if(k1 != k2) {
            if(-parent[k1] < -parent[k2])
                std::swap(k1, k2);
            parent[k1] += parent[k2];
            parent[k2] = k1;
        }
    }
};

class dsu {
public:
    int parent[10000];
    int size_set[10000];
    // non made elements = 0
    // leader elements = key
    // set elements = parent element

    void make_set(int v) {
        parent[v] = v;
        size_set[v] = 1;
    }

    // finds root of the specified key
    int find_root(int v) {
        if(v == parent[v]) return v;
        // path compression
        return parent[v] = find_root(parent[v]);
    }

    // merges two sets
    void union_sets(int a, int b) {
        a = find_root(a);
        b = find_root(b);
        if(a != b) {
            if(size_set[a] < size_set[b])
                std::swap(a, b);
            size_set[a] += size_set[b];
            parent[b] = a;
        }
    }
};
