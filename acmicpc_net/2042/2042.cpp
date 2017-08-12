#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>

typedef long long LL;
using namespace std;

int N, M, K;
LL BIT[1000001];
LL ary[1000001];

void update(int i, LL v) {
  while(i <= N) {
    BIT[i] += v;
    i += i & -i;
  }
}

LL getSum(int i) {
  LL sum = 0;
  while(i > 0) {
    sum += BIT[i];
    i -= i & -i;
  }
  return sum;
}

void solve() {
  scanf("%d %d %d", &N, &M, &K);
  for(int i=0; i<N; i++){
    scanf("%lld", &ary[i+1]);
    update(i+1, ary[i+1]); 
  }

  for(int i=0; i<M+K; i++)
  {
    LL a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    if(a == 1) {
      update(b, c - ary[b]);
      ary[b] = c;
    } else {
      printf("%lld\n", getSum(c) - getSum(b-1)); 
    }
  }
}

int main() {
  solve();
  return 0;
}
