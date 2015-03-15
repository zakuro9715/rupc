#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) (c).begin(),(c).end()

#define MAX_N 100

using namespace std;

int main(){
	int N, M, a, L;
	cin >> N >> M;
	bool field[MAX_N + 1] = {};
	for(int i = 0; i < M; i++){
		cin >> a >> L;
		for(int j = a; j < a + L; j++){
			field[j % N] = true;
		}
	}
/*
for(int j = 0; j < M; j++){
	cout << j << ": " << field[j] << endl;
}
*/

	int i = 0;
  int cnt_num[MAX_N + 1] = {};
  if(field[N - 1])
	  for(; field[i] && i < N; i++);
  if(i == N)
    cnt_num[N]++;
  while(i < N)
  {
    int j = i;
    for(; field[j % N]; j++);
    if(j - i)
      cnt_num[j - i]++;
    i = j + 1;
  }

	for(int k = MAX_N; k >= 0; k--){
		if(cnt_num[k] != 0){
			cout << k << " " << cnt_num[k] << endl;
		}
	}
}
