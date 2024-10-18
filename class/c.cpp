#include<bits/stdc++.h>
using namespace std;
 
#define speedup ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define undefined -1
#define pie 3.141592653589793
#define For(i,n) for(int i=0;i<n;i++)
#define For_(i,v,n) for(int i=v;i<n;i++)
#define vfind(v,i) find(v.begin(), v.end(), i);
#define viint vector<int>::iterator
#define vii2int(v,i) i - v.begin()
#define sz(x) x.size()
#define isz(x) (int)x.size()
#define full(x) x.begin(),x.end()
#define FINAL(x) WRITE(x,'\n'); return
#define sayYES cout<<"YES\n"; return
#define sayNO cout<<"NO\n"; return 
#define sayYes cout<<"Yes\n"; return
#define sayNo cout<<"No\n"; return 
#define say_1 cout<<-1<<'\n'; return
#define DBG(x) cout<<"ok "<<x;
 
string ctos(char c) {string a="";a+=c; return a;}

template<typename datatype>
void SHOW(datatype arr[],int n){
	For(i,n) cout<<arr[i]<<' ';
	cout<<'\n';
}

template<typename datatype>
void READ(datatype arr[],int n){
	For(i,n) cin>>arr[i];
}
template<typename datatype>
void READ(vector<datatype> &arr){
	For(i,arr.size()) cin>>arr[i];
}
void READ() {}
template<typename datatype, typename... Args>
void READ(datatype& data, Args&... rest) {
    cin >> data;
    READ(rest...);
}
 
void WRITE(){}//cout<<"";}
template<typename datatype, typename... Args>
void WRITE(datatype variable, Args... rest){
	cout<<variable;
	WRITE(rest...);
}

int n,k,ans;
void solve() {
    READ(n,k);
    ans=0;
    vector<int> d;
    int sz = floor(sqrt(n));
    For(i,sz) if(n%(i+1)==0) {d.push_back(i+1); if(i+1 != n/(i+1)) d.push_back(n/(i+1));}
    for(auto x : d) if(x%k) ans+=x;
    WRITE(ans,'\n');
}

int main() {
    speedup;
    int T, i=1;
    READ(T);
    while(T--) {
        //WRITE("Case ",i,": ");
        solve();
        //i++;
    }
    return 0;
}