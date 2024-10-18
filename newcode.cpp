#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,n) for(int i=0; i<n; i++)
#define FOr(i,v,n) for(int i=v; i<n; i++)
#define FoR(i,n,inc) for(int i=0; i<n; i+=inc)

int n, k, bc;
string grid[1005];
void solve() {
    cin>>n>>k;
    For(i,n) cin>>grid[i];
    FoR(i,n,k) {FoR(l,n,k) cout<<grid[i][l]; cout<<'\n';}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}