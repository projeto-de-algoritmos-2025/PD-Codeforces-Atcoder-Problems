#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define oo LLONG_MAX
#define vll vector<ll>
#define range(i, x, n) for(i = x; i < n; i++)
using namespace std;
#define MAX 100'010

const double PI {acos(-1.0)};

vll coins = {1, 6, 36, 216, 1296, 7776, 46656, 9, 81, 729, 6561, 59049};

vll mem(MAX, -1);

ll solve(ll n){
    if(mem[n] != -1)
        return mem[n];
    
    ll min_coins = oo;
    for(ll c: coins)
        if(c <= n)
            min_coins = min(1 + solve(n - c), min_coins);

    return (mem[n] = min_coins);

}

int main(){
    ios::sync_with_stdio(false);
    ll n;
    mem[0] = 0;
    cin >> n;
    sort(coins.begin(), coins.end());
    cout << solve(n) << "\n";
	return 0;
}
