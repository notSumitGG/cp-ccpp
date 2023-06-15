#include<stdio.h>
#include<string.h>
#define d 256
#define q 1000000007

void rabinkarp(char pat[], char txt[]){
	int m = strlen(pat);
	int n = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for text
	int h = 1;

	for(i = 0; i < m-1; i++)   // pow(d, M-1)%q = coefficient of first 
		h = (h*d)%q;

	for(i = 0; i < m; i++){
		p = (d*p + pat[i])%q; // Hash value of pattern
		t = (d*t + txt[i])%q; // Hash value of text at 0 of length m
	}

	for(i = 0; i <= n-m; i++){
		if(p == t){
			for(j = 0; j < m; j++){  // When hash values match
				if(txt[i+j] != pat[j])
					break;
			}
			if(j == m)
				printf("Pattern found at index %d \n", i);
		}
		if(i < n-m){
			t = (d*(t - txt[i]*h) + txt[i+m])%q; // Actual rehashing technique
			if(t < 0)   t += q;  // We might get negative value of t, converting it to positive
		}
	}
}
