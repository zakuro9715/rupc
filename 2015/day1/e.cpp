#include<iostream>
#include<map>
#include<vector>
#define NN 100

using namespace std;

int N, M, E, S, T, R;

vector<int> depends[8];
int events[NN];
pair<int, int> ev_edges[NN];
vector<int> edges[NN];

bool ddone[NN];
void dfs1(int n, int ev)
{
  ddone[n] = true;
  int nev = events[ev] != -1 ? events[ev] : ev;
  for(int i = 0; i < edges[n].size(); i++)
  {
    int to = edges[n][i];
    depends[events[to]].push_back(ev);
    if(!ddone[to])
      dfs1(to, nev);
  }
}

int main()
{
  cin >> N >> M >> E >> S >> T >> R;
  for(int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 0; i < E; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    ev_edges[i] = make_pair(a, b);
    events[c] = i;
  }
  dfs1(S, -1);
  for(int i = 0; i < E; i++)
  {
    for(int j = 0; j < depends[i].size(); j++)
      cout << depends[i][j] << " ";
    cout << endl;
  }
}
