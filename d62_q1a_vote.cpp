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
    int n,k;
    cin>>n>>k;
    map<string,int> m;
    vi v;
    while(n--){
        string name;
        cin>>name;
        m[name] ++;
    }
    for(auto i : m){
        v.emplace_back(i.second);
    }
    sort(v.begin(),v.end(),greater<int>());
    k = min(k-1,(int)v.size()-1);
    if(v[k] ==0) {
        while(k && !v[k]) k--;
    }
    cout<<v[k];
    
    return 0;
}