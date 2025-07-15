#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define oo LLONG_MAX
#define vll vector<ll>
#define range(i, x, n) for(i = x; i < n; i++)
#define MAX 100'010
using namespace std;

const double PI {acos(-1.0)};

int main(){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll n, i;
    cin >> n;
    vll mem(s.length(), 0);
    range(i, 1, s.length()){
        mem[i] = mem[i - 1];
        if(s[i] == s[i - 1])
            mem[i]++;
    }
    range(i, 0, n){
        ll l, r;
        cin >> l >> r;
        cout << mem[r - 1] - mem[l - 1] << '\n';
    }

	return 0;
}
