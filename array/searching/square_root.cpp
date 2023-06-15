#include<iostream>
#include<iomanip>
using namespace std;

double square_root(double n){
    double low = 0, high = n, mid;
	double eps = 1e-15;

    while(high - low > eps){
        mid = low + (high - low)/2;
        if(mid*mid < n)
            low = mid;
        else
            high = mid;
    }
    return mid;
}
int main(){
    double n, sq_rt;
    cin >> n;
    sq_rt = square_root(n);
    cout << setprecision(14) << sq_rt << endl;
    return 0;
}
