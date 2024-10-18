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
#define full(x) x.begin(),x.end()
#define FINAL(x) WRITE(x,'\n'); return
#define sayYes cout<<"YES\n"; return
#define sayNo cout<<"NO\n"; return 
#define say_1 cout<<-1<<'\n'; return
#define RI(X) int x;cin>>x
 
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

int n, r; ll arr[105];
void solve() {
	READ(n,arr,n);
	r=0;
	For(i,n) {
		r++;
		r+=(r==arr[i]);
	}
	WRITE(r,'\n');
}
 
int main() {
    speedup;
	int T;
	READ(T);
	while(T--)
	solve();
	return 0;
}