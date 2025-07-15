#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define oo LLONG_MAX
#define vll vector<ll>
#define range(i, x, n) for(i = x; i < n; i++)
using namespace std;
#define MAX 1'000'000

const double PI {acos(-1.0)};

ll dp(vector<pii>& a, ll i, ll hmax, ll hnow, vll& p, vll& drop_sum){
    ll jump = 0, next = 0, dx = (a[i].second - a[i].first), dpx = (a[p[i]].first - a[i].second); 
    if(hnow < hmax || i == a.size() - 1)
        return dx + hnow;
    if(i < a.size() - 1)
        next = dp(a, i + 1, hmax, hmax, p, drop_sum);
    if(p[i] == i)
        return max(dx + hmax, next);
    jump = dp(a, p[i], hmax, hmax - (drop_sum[i] - drop_sum[p[i]]), p, drop_sum) + dpx + dx;
    return max(jump, next);
}  

void solve(vector<pii>& a, ll n, ll h){
    ll i;
    vll drop(n);
    range(i, 0, n){
        if(i == n - 1)
            drop[i] = h;
        else
            drop[i] = min((a[i + 1].first - a[i].second), h);
    }
    vll drop_sum(n);
    drop_sum[n - 1] = 0;
    for(ll ii = n - 2; ii >= 0; ii--)
        drop_sum[ii] = drop_sum[ii + 1] + drop[ii];
    ll aux = 1;
    vll p(n);
    range(i, 0, n){
        while(drop_sum[i] - drop_sum[aux] < h && aux < n)
            aux++;
        p[i] = aux - 1;
    }
    
    cout << dp(a, 0, h, h, p, drop_sum) << '\n';
        
}

int main(){
    ios::sync_with_stdio(false);
    ll n, h;
    cin >> n >> h;
    vector<pii> a(n);
    ll i;
    range(i, 0, n)
        cin >> a[i].first >> a[i].second;
    solve(a, n, h);
    
	return 0;
}
