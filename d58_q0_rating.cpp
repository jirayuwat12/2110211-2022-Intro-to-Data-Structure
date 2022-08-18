#include<bits/stdc++.h>
#define FOR(i,s,n) for(int i = s;i<n;i++)
#define FORR(i,s,n) for(int i = s;i>=n;i++)
#define ShowMatrix(m) for(auto i : m) { for(auto j : i) cout<<j<<' '; cout<<'\n'; }
#define vi vector<int>
#define vii vector<vector<int>>
typedef long long ll;
using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin>>n;
    map<string,pair<float,int>> m1,m2;
    cout<<fixed<<setprecision(2);
    while(n--){
        string a,b;
        int c;
        cin>>a>>b>>c;
        m1[a] = {m1[a].first+c,m1[a].second+1};
        m2[b] = {m2[b].first+c,m2[b].second+1};
    }
    for(auto i : m1){
        cout<<i.first<<' '<<i.second.first/i.second.second<<'\n';
    }
    for(auto i : m2){
        cout<<i.first<<' '<<i.second.first/i.second.second<<'\n';
    }
    
    return 0;
}