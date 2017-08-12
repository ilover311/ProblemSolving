#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
int N;

void solve() {
  scanf("%d", &N);
  vector<pii> app(N);
  for(int i=0; i<N; i++)
    scanf("%d %d", &app[i].first, &app[i].second);

  sort(app.begin(), app.end());
  int ans(1);
  int min_b_score = app[0].second;
  for(int i=1; i<N; i++)
  {
    if (min_b_score > app[i].second)
    {
      ans++;
      min_b_score = app[i].second;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int TC;
  scanf("%d", &TC);
  while(TC-- > 0) 
  {
    solve();
  }
  return 0;
}
