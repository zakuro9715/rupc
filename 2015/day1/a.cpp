#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int f, a, t, x, y;
  int ff, aa, tt, xx, yy;
  int ansl[2] = {-1, -1}, ansf[2] = {100000000, 100000000};
  cin >> f >> a >> t >> x >> y;
  for(int i = 1; i < N; i++)
  {
    cin >> ff >> aa >> tt >> xx >> yy;
    if(t == tt && a != aa)
    {
      int dx = xx - x, dy = yy - y;
      int v = dx * dx + dy * dy; 
      if(v > ansl[tt] || v == ansl[tt] && ff - f < ansf[tt])
      {
        ansl[tt] = v;
        ansf[tt] = ff - f ;
      }
    }
    f = ff;
    a = aa;
    t = tt;
    x = xx;
    y = yy;
  }
  for(int i = 0; i < 2; i++)
  {
    if(ansl[i] == -1)
      printf("-1 -1\n");
    else
      printf("%.10f %.10f\n", sqrt(ansl[i]), ansf[i] / 60.0);
  }
}
