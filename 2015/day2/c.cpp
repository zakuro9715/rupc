#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) (c).begin(),(c).end()

using namespace std;

const int INF=1e9;
typedef pair<int,int> P;
int n,x;
int d[20],c[20];
int f[200010];
const int offset=100005;

int bfs() {
  f[offset]=0;
  priority_queue<P,vector<P>,greater<P> > que;
  que.push(P(0,offset));

  while(que.size()) {
    P p=que.top(); que.pop();
    int pos=p.second;
    int cost=p.first;
    if(cost>f[pos]) continue;
     // printf("%d %d\n",pos,cost);
    rep(i,n) {
      int t=pos+d[i];
      if(0<=t&&t<200010&&f[t]>cost+c[i]) {
        f[t]=cost+c[i];
        que.push(P(cost+c[i],t));
      }
      t-=d[i]*2;
      if(0<=t&&t<200010&&f[t]>cost+c[i]) {
        f[t]=cost+c[i];
        que.push(P(cost+c[i],t));
      }
    }
  }
  return -1;
}

int main()
{
  rep(i,200010) f[i]=INF;
  cin>>n>>x;
  rep(i,n) cin>>d[i]>>c[i];
  bfs();
  if(f[offset+x]==INF) f[offset+x]=-1;
  cout<<f[offset+x]<<endl;
}
