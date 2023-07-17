#include<iostream>
#include<algorithm>
using namespace std;

// “Given ‘n’ number of jobs with ending time, they need to 
// be scheduled in such a way that maximum profit is 
// received within the maximum deadline”.

struct job {        // default time taken is 1 unit
    int profit;     // profit after completing the job
    int deadline;   // maximum deadline to complete the job
};

job j[10000];       // total given jobs
int com[10000];     // allocated & completed jobs

bool cmp(job a, job b) {
    if(a.profit != b.profit) {
        if(a.profit > b.profit)
            return true;
        else 
            return false;
    } else {
        if(a.deadline < b.deadline) 
            return true;
        else
            return false;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> j[i].profit >> j[i].deadline;
        com[i] = -1;
    }

    sort(j, j+n, cmp);
    cout << n << endl;
    for(int i=0; i<n; ++i) {
        cout << j[i].profit << " " << j[i].deadline << endl;
    }

    int tp = 0;
    // jobs are marked when they are started
    for(int i=0; i<n; ++i) {
        // job allocation
        for(int k=j[i].deadline-1; k>=0; --k) {
            if(com[k] == -1) {
                com[k] = i;
                tp += j[i].profit;
                break;
            }
        }
    }

    cout << tp << endl;
    for(int i=0; i<n; ++i) {
        cout << com[i] << endl;
    }

    return 0;
}

/*
5
10 1
20 2
5 3
15 2
1 3
*/
