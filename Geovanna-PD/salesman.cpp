#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pii pair<int,int>
const int MAX = 2'000'05, oo=2e18;
const int mod = 998244353;

void solve(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dist(n, vector<int>(n,oo));
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    dist[u][v]=min(dist[u][v],w);
  }
  for(int i1=0; i1<n; ++i1)
    for(int i0=0; i0<n; ++i0)
      for(int i2=0; i2<n; ++i2)
        if(dist[i0][i1]!=oo && dist[i1][i2]!=oo)
          dist[i0][i2] = min(dist[i0][i2], dist[i0][i1]+dist[i1][i2]);
  vector<vector<int>> dp(n, vector<int> ((1<<n), oo));
  for(int i=0; i<n; ++i)
    dp[i][(1<<i)]=0;
  for(int mask=0; mask<(1<<n); ++mask){
    for(int i=0; i<n; ++i){
      if(dp[i][mask]==oo) continue;
      for(int j=0; j<n; ++j){
        if(i==j || dist[i][j]==oo) continue;
        dp[j][mask|(1<<j)]=min(dp[j][mask|(1<<j)], dp[i][mask]+dist[i][j]);
      }
    }
  }
  int ans=oo;
  for(int i=0; i<n; ++i) ans=min(ans, dp[i][(1<<n)-1]);
  if(ans==oo) cout << "No\n";
  else cout << ans << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
	int t=1;
  // cin >> t;
	while(t--) solve();
}


