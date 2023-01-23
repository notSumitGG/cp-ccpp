#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

void generate_subsets(string vowel, unordered_map<string, int> &hash) {
    int n = 1<<vowel.size();
    for(int mask=0; mask < n; ++mask) {
        string ss;
        for(int i=0; i<vowel.size(); ++i) {
            if(mask & (1<<i))
                ss.push_back(vowel[i]);
        }
        if(ss.size())
            ++hash[ss];
    }
}

int main() {
    int t;
    cin >> t;
    char vow[5] = {'a', 'e', 'i', 'o', 'u'};
    while(t--) {
        int n;
        cin >> n;
        vector<string> st(n);
        unordered_map<string, int> hash;
        for(int i=0; i<n; ++i) {
            cin >> st[i];

            int vhash = 0;
            for(char ch : st[i]) {
                if(ch == 'a') vhash |= 1<<0;
                else if(ch == 'e') vhash |= 1<<1;
                else if(ch == 'i') vhash |= 1<<2;
                else if(ch == 'o') vhash |= 1<<3;
                else if(ch == 'u') vhash |= 1<<4;
                else continue;
            }

            string v;// creating the string with the vowels present in the original string
            for(int i=0; i<5; ++i) {
                if(vhash & (1<<i)) 
                    v.push_back(vow[i]);
            }
            generate_subsets(v, hash);
        }
        
        long long ans = 0;
        for(auto &pr : hash) {
            if(pr.second < 3) continue;
            long long ct = pr.second;
            long long ways = ct * (ct-1) * (ct-2) / 6;
            // odd sized string should be added and even sized should be substracted
            if(pr.first.size() & 1 == 1) 
                ans += ways;
            else 
                ans -= ways;
        }
        cout << endl << ans ;
    }
    return 0;
}
/*2
5
helen
irena
arthos
pentos
tulu
3
alen
bira
cult*/