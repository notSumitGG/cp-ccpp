#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> valid;

void generate(string &par, int open, int closed) {
    if(open == 0 && closed == 0) {
        valid.push_back(par);
        return;
    }
    if(open > 0) {
        par.push_back('(');
        generate(par, open - 1, closed);
        par.pop_back();
    }
    if(closed > 0 && open < closed) {
        par.push_back(')');
        generate(par, open, closed - 1);
        par.pop_back();
    }
}
int main() {
    int n;
    cin >> n;
    string s;
    generate(s, n, n);
    for(auto it : valid)
        cout << it << endl;
    return 0;
}
