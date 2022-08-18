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
    int n,m;
    cin>>n>>m;
    map<ll,vector<ll>> g;
    map<pair<ll,ll>,bool> res;
    while(n--){
        ll f,s;
        cin>>f>>s;
        g[f].emplace_back(s);
    }

    for(pair<ll,vector<ll>> i : g){
        vector<ll> s;
        for(ll j:i.second) {
            for(ll k : g[j]){
                s.push_back(k);
            }
        }
        FOR(i,0,s.size()){
            FOR(j,i+1,s.size()){
                res[{s[i],s[j]}] = true;
                res[{s[j],s[i]}] = true;
                
            }
        }
    }
    while(m--){
        ll a,b;
        cin>>a>>b;
        if(res[{a,b}]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}