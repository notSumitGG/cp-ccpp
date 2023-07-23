#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

vector<int> cutTheSticks(vector<int> arr) {
    int n = arr.size();
    vector<int> res;
    int mini = INT_MAX;
    for(int i=0; i<n; ++i) {
        if(arr[i] < mini)
            mini = arr[i];
    }
    
    while(true) {
        int sticksCut = 0;
        int nextMin = INT_MAX;
        for(int i=0; i<n; ++i) {
            if(arr[i] >= mini) {
                arr[i] -= mini;
                sticksCut += 1;
                if(arr[i] < nextMin && arr[i] > 0) {
                    nextMin = arr[i];
                }
            }
        }
        cout << "mini " << mini << endl;
        mini = nextMin;
        if(sticksCut == 0)
            break;
        res.push_back(sticksCut);
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = cutTheSticks(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
