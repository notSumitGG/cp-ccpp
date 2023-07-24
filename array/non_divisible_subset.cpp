#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// https://www.hackerrank.com/challenges/non-divisible-subset/problem?isFullScreen=true
int nonDivisibleSubset(int k, vector<int> s) {
    int n = s.size();
    vector<int> rem(n);
    vector<int> rem_count(k);
    for(int i=0; i<n; ++i) {
        rem[i] = s[i] % k;
        rem_count[rem[i]] += 1;
    }
    for(int i=0; i<k; i++)
        cout << rem_count[i] << " ";
    int res = 0;
    for(int i=1; i<=(k-1)/2; ++i) {
        int comp = k - i;
        if(rem_count[i] < rem_count[comp])
            res += rem_count[comp];
        else
            res += rem_count[i];
    }
    if(rem_count[0] > 0) res += 1;
    if(k%2==0 && rem_count[k/2]>0) res += 1;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

