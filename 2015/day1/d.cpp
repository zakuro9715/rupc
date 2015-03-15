#include<cstdio>
#include<iostream>
using namespace std;

int N, L, x[5000], a[5000];

int f(int h,int now) {
	if(h==0)return 1;
	cout<<h<<" "<<now<<endl;
	int ret=0;

	ret+=f(h-1,x[h]);
	for(int i=0;;i++){
	if(x[h]+i*a[i]>L)break;
	ret+=f(h-1,x[h]+i*a[i]);
	}
	return ret;
	
}

int main() {

	scanf("%d%d", &N, &L);

	for(int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}
	for(int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	
	cout<< f(N-1,x[N-1]) <<endl;
	
	return 0;
}
