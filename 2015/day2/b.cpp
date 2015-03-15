#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) (c).begin(),(c).end()

using namespace std;

int a[100001], ans[5];

int main()
{
  int N;
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> a[i];
  int b = -1;
  bool end = false;
  int i = 0;
  while(a[i] == a[i + 1] && i < N)
    i++;
  for(i++; i < N - 1; i++)
  {
    b = a[i - 1];
    int now = a[i], c = a[i] /* 基準高 */;
    bool f = false; // 立ってたら平地あり(高原or盆地or山腹)
    // 平地の間
    while(now == a[i + 1])
    {
      now = a[++i];
      f = true;
      if(i == N - 1)
      {
        end = true;
        break;
      }
    }
    if(end)
      break;
    int next = a[i + 1];
    if(!f && b < c && c < next)
      continue;
    if(f) // 平地あり
    {
      if(b < c && c > next) // 高原
        ans[0]++;
      else if(b > c && c < next) // 盆地
        ans[1]++;
      else if(b < c && c < next) // 山腹1
        ans[2]++;
      else if(b > c && c > next) // 山腹2
        ans[2]++;
    }
    else // 平地なし
    {
      if(b < c && c > next) // 峰
        ans[3]++;
      else if(b > c && c < next) // 窪地
        ans[4]++;
    }
  }
  for(int i = 0; i < 4; i++)
    cout << ans[i] << " ";
  cout << ans[4] << endl;
}
