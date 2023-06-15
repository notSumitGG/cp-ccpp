#include<iostream>
#include<string>
#include<vector>
using namespace std;

class manacher {
    string s;
    vector<int> p;
public:
    manacher(string &st) {
        s += string("#");
        for(auto ch : st)
            s += ch + string("#");
        int n = s.size();
        p = vector<int> (n, 1);

        int l = 1;
        int r = 1;
        for(int i=1; i<n; ++i) {
            p[i] = max(0, min(p[l+r-i], r-i));
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]])
                p[i]++;
            if(i+p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }
    int getLongest(int center, bool isOdd) {
        int pos = 2*center + 1 + (!isOdd);
        return p[pos]-1;
    }
    bool checkPalindrome(int l, int r) {
        if((r-l+1) <= getLongest((l+r)/2, l%2==r%2))
            return 1;
        else 
            return 0;
    }
    void print() {
        for(auto ch : s) 
            cout << ch << " ";
        cout << endl;
        for(auto it : p) 
            cout << it << " ";
        cout << endl;
    }
};
// babbabbabc
