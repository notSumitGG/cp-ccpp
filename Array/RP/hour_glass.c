#include<stdio.h>
#define INT_MIN -2147483648

int main(){
	int a[6][6], sum = 0, max = INT_MIN;

	for(int i=0; i<6; i++)
	   for(int j=0; j<6; j++)
	      scanf(" %d", &a[i][j]);

	for(int i=1; i<5; i++){
		for(int j=1; j<5; j++){
            sum += a[i][j];
            sum += a[i-1][j] + a[i+1][j];
            sum += a[i-1][j-1] + a[i+1][j+1];
            sum += a[i+1][j-1] + a[i-1][j+1];

			if(max<sum)  max=sum;
            sum = 0;
		}
	}
	printf(" %d\n",max);
	return 0;
}
