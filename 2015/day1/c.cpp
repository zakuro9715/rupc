#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

map<string, vector<string>> tb;
map<string, int> cost;
map<string, bool> done;
int N, M;

int search(string s)
{
  int ans = cost[s];
  done[s] = true;
  for(int i = 0; i < tb[s].size(); i++)
    if(done.find(tb[s][i]) == done.end())
      ans = min(ans, search(tb[s][i]));
  return ans;
}

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    string a;
    int x;
    cin >> a >> x;
    cost[a] = x;
  }
  cin >> M;
  for(int i = 0; i < M; i++)
  {
    string s1, s2;
    cin >> s1 >> s2;
    tb[s1].push_back(s2);
    tb[s2].push_back(s1);
  }
  int ans = 0;
  for(auto it = cost.begin(); it != cost.end(); ++it)
  {
    done.clear();
    ans += search(it->first);
  }
  cout << ans << endl;
}
