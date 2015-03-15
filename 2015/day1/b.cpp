#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

long long SUM[1000001];
long long N, M, a[300000], b[300000];
int main() {
	long long c;

	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a+N);

	SUM[0] = 0;
	int ai = 0;
	for(int i = 0; i < 1000001; i++) {
		if(i > 0) SUM[i] = SUM[i - 1];
		while(ai < N && i == a[ai])
		{
			SUM[i] += a[ai];
			ai++;
		}
	}

/*
	for(int i = 0; i < 10; i++) {
		printf("%lld ", SUM[i]);
	}
	printf("\n");
*/
	scanf("%d", &M);

	for(int i = 0; i < M; i++) {
		scanf("%d",&b[i]);
	}
	
	for(int i = 0; i < M; i++) {
		cin >> c;
		printf(SUM[b[i]]>=c?"Yes\n":"No\n");
	}

	return 0;
}
