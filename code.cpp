#include<bits/stdc++.h>
using namespace std;
 
#define speedup ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long
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

bool allUpper(string s) {
    for(char a : s) if(islower(a)) return 0;
    return 1;
}

int bin_arr[15] = {10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000};

bool is_binary(int n) {
    int x;
    while(n) {
        x=n%10;
        if(x!=1 && x!=0) {return false;}
        n/=10;
    }
    return true;
}

bool divided(int *n) {
    int m=(*n);
    For(i,15) {
        if(m%bin_arr[i]==0) {
            (*n)/=bin_arr[i];
            return true;
        }
    }
    return false;
}
int n;
void solve() {
    READ(n);
    while(!is_binary(n)) {
        if(!divided(&n)) break;
    }
    WRITE(is_binary(n) ? "YES" : "NO",'\n');
}

int main() {
    speedup;
    int T, i=1;
    READ(T);
    cin.ignore();
    while (T--){
        //WRITE("Case ",i,": ");
        solve();
        //i++;
    }
    return 0;
}