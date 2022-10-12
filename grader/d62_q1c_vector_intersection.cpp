#include<bits/stdc++.h>
#define FOR(i,s,n) for(int i = s;i<n;i++)
#define FORR(i,s,n) for(int i = s;i>=n;i++)
#define ShowMatrix(m) for(auto i : m) { for(auto j : i) cout<<j<<' '; cout<<'\n'; }
#define vi vector<int>
#define vii vector<vector<int>>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    set<ll> s, ret;
    while(m--){
        int t;
        cin>>t;
        s.insert(t);
    }
    while(n--){
        int t;
        cin>>t;
        if(s.count(t)) ret.insert(t);
    }
    for(auto i : ret){
        cout<<i<<' ';
    }
    return 0;
}