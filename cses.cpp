#include<bits/stdc++.h>
using namespace std;
 
#define speedup ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define undefined -1
#define pie 3.141592653589793
#define For(i,n) for(int i=0; i<n; i++)
#define FOr(i,v,n) for(int i=v; i<n; i++)
#define FoR(i,n,inc) for(int i=0; i<n; i+=inc)
#define vfind(v,i) find(v.begin(), v.end(), i);
#define viint vector<int>::iterator
#define vii2int(v,i) i - v.begin()
#define sz(x) x.size()
#define full(x) x.begin(),x.end()
#define FINAL(x) WRITE(x,'\n'); return
#define sayYes cout<<"Yes\n"; return
#define sayNo cout<<"No\n"; return 
#define say_1 cout<<-1<<'\n'; return
 
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

int n;
void solve(){
	READ(n);
	n+=1;
    for(unsigned ll i=1;i<n; i++) {
        unsigned ll tot = i*i*(i*i-1)*0.5 - 4*(i-2)*(i-1);
        cout<<tot<<'\n';
        WRITE(tot,'\n');
    }
}
 
int main() {
    speedup;
	solve();
	return 0;
}