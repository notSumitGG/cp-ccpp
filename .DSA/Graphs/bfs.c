#include<stdio.h>

int a[21][21], q[21], visited[21];
int n, i, j, f=0, r=-1;

void bfs_(int v) {
	for(i=1; i<=n; i++)
	  if(a[v][i] && !visited[i])
	   q[++r] = i;
	if(f<=r) {
		visited[q[f]]=1;
		bfs_(q[f++]);
	}
}
void bfs(int v) {
    q[++r] = v;
    bfs_(v);
}

int main() {
	scanf("%d", &n);
	for (i=0; i<=n; i++) {
		q[i]=0;
		visited[i]=0;
	}

	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
    
    int v;
	scanf("%d",&v);

	bfs(v);

	printf("\n The node which are reachable are:\n");
	for (i=1;i<=n;i++)
	  if(visited[i])
	   printf("%d\t",i); else
	   printf("\n Bfs is not possible");
    
    return 0;
}
/*
5
0 1 1 0 0 
1 0 0 1 0
1 0 0 1 1
0 1 1 0 1
0 0 1 1 0
1
*/