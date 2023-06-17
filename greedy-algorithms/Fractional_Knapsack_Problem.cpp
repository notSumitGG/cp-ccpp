#include <iostream>
#include <algorithm>
using namespace std;

// ob[i].wt = weight of the object
// ob[i].profit = profit on including the object
struct object {
    int wt, profit;
    double pw; // profit per weight
};

object ob[10000];

bool mycmp(object a, object b) {
    if(a.pw > b.pw)
        return true;
    else
        return false;
}

int main() {
    int n, twt;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ob[i].wt >> ob[i].profit;
        ob[i].pw = (double) ob[i].profit / (double) ob[i].wt;
    }
    cin >> twt;

    sort(ob, ob + n, mycmp);

    for(int i=0; i<n; ++i) {
        cout << ob[i].wt << " " << ob[i].profit << " " << ob[i].pw << endl;
    }

    double tp = 0.0;
    int i = 0;
    while(twt != 0 || i<n) {
        if(twt - ob[i].wt > 0) {
            twt -= ob[i].wt;
            tp += ob[i].profit;
        } else {
            tp += ((double)twt / (double)ob[i].wt) * ob[i].profit;
            twt = 0;
        }
        i++;
    }
    cout << tp << "\n";

    return 0;
}

/*
7
4 18
3 5
1 3
1 6
5 15
7 7
2 10
15
*/
