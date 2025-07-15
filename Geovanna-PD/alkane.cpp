#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long
#define edge tuple<int,int,int>
#define pii pair<int,int>
const int oo = 1e18, mod = 1e9+7; // 998'244'353;
const int MAX = 1.2e6+5;
constexpr array<pair<int, int>, 4> dxy = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};

void solve(){
  int n, ans=-1;
  cin >> n;
  vector<vector<int>> adj(n);
  for(int i=0; i<n-1; ++i){
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<int> qs;
  vector<vector<int>> memo(n,vector<int>(4,-1));
  auto dp = [&](auto &&self, int i, int p) -> void {
    vector<int> ps;
    for(auto &x : adj[i])
      if(x!=p)
        self(self,x,i);
    for(auto &x : adj[i]) if(x!=p) ps.push_back(max(memo[x][2],memo[x][0]));
    sort(ps.rbegin(),ps.rend());
    memo[i][0]=1;
    if(ps.size()) memo[i][1]=ps[0]+1;
    if(ps.size()>=3) memo[i][2]=ps[0]+ps[1]+ps[2]+1;
    if(ps.size()>=4) memo[i][3]=ps[0]+ps[1]+ps[2]+ps[3]+1;
    if(ps.size() && ps[0]>1) memo[i][3]=max(memo[i][3],ps[0]+1);
  };
  dp(dp,0,-1);
  for(int i=0; i<n; ++i) ans=max(ans, memo[i][3]);
  cout << ans << endl;
}


signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  // cin >> t;
  for(int i=1; i<=t; ++i)
    solve();
}
