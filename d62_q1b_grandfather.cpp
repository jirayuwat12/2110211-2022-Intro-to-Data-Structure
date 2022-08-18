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
    vector<set<ll>> res;
    while(n--){
        ll f,s;
        cin>>f>>s;
        g[f].emplace_back(s);
    }

    for(pair<ll,vector<ll>> i : g){
        set<ll> s;
        for(ll j:i.second) {
            for(ll k : g[j]){
                s.insert(k);
            }
        }
        res.push_back(s);
    }
    while(m--){
        ll a,b;
        cin>>a>>b;
        bool ck = false;
        for (set<ll> s: res){
            if(s.count(a) && s.count(b) && a!= b){
                ck = true;
                break;
            }
        }
        if(ck) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}