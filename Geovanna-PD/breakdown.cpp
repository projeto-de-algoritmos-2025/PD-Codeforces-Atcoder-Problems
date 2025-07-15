#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pii pair<int,int>
const int MAX = 5'001, oo=2e9;
const int mod = 998244353;

vector<vector<int>> dp(MAX, vector<int>(MAX,-oo));
vector<vector<pii>> pred(MAX, vector<pii>(MAX,{-1,-1}));

void solve(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  while(m--){
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> ps(n), w(n), a(n);
  for(auto &x : w) cin >> x;
  for(auto &x : a) cin >> x;
  iota(ps.begin(),ps.end(), 0);
  sort(ps.begin(),ps.end(), [&](auto x, auto y){
    return w[x]<w[y];
  });
  vector<pii> best(n); // idx, value
  for(int i=0; i<n; ++i){
    int x = ps[i];
    dp[x][0]=0;
    for(auto &y : adj[x]){
      for(int j=w[x]-w[y]-1; j>=0 ; --j){
        if(dp[x][j+w[y]]<dp[x][j]+best[y].second+1){
          pred[x][j+w[y]] = {j, y}; // pred = weight, idx
          dp[x][j+w[y]] = dp[x][j]+best[y].second+1;
          if(best[x].second < dp[x][j+w[y]])
            best[x] = {j+w[y], dp[x][j+w[y]]};
        }
      }
    }
  }
  int ans=0;
  for(int i=n-1; i>=0; --i){
    int x = ps[i];
    ans+=(best[x].second+1)*a[x];
  }
  cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--) solve();
}

