#include<stdio.h>

void sort(int x[], int n){
	int temp, min;
	for(int i=0; i<n-1; ++i){
		min = i;
		for(int j=i+1; j<n; ++j)
			if(x[j] < x[min])
				min = j;

		temp = x[i];
		x[i] = x[min];
		x[min] = temp;
	}
}
int main(){
	int x[100000], n, sum;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]);
    scanf(" %d", &sum);

    sort(x, n);
	int left=0, right=n-1;
	while(left < right){
		if(x[left]+x[right] == sum){
			printf(" %d %d\n", left, right);
			printf(" %d %d\n", x[left], x[right]);
			break;
		}
		else if(x[left]+x[right] < sum)
			++left;
		else
			--right;
	}
	return 0;
}
