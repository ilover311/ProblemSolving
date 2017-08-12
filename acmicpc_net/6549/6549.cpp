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

typedef long long LL;
typedef pair<int, int> pii;

int N;

void solve() {
  LL ans = 0;

  vector<LL> cols(N);
  vector<LL> R(N), L(N);
  vector<int> seq;
  
  for(int i=0; i<N; i++) {
    scanf("%lld", &cols[i]);
  }

  for(int i=0; i<N; i++) {
    while(seq.size() > 0 && cols[i] <= cols[seq.back()]){
      seq.pop_back();
    }
    if(seq.size() == 0)
      L[i] = 0;
    else
      L[i] = seq.back() + 1;
    seq.push_back(i);
  }

  while(seq.size() > 0)
    seq.pop_back();

  for(int i=N-1; i>=0; i--) {
    while(seq.size() > 0 && cols[i] <= cols[seq.back()]){
      seq.pop_back();
    }
    if(seq.size() == 0)
      R[i] = N;
    else
      R[i] = seq.back();
    seq.push_back(i);
  }

  for(int i=0; i<N; i++){
    ans = max(ans, cols[i] * (R[i] - L[i]));  
  }

  printf("%lld\n", ans);
}

int main() { 
  while(scanf("%d", &N) > 0 && N != 0){
    solve();
  }
  return 0;
}
