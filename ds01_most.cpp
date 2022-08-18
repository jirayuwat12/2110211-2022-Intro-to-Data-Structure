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
    map<string,int> m;
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        m[a] ++;
    }
    int maxx = -1;
    string res;
    for(auto i : m){
        if(i.second >= maxx){
            maxx = i.second;
            res  =i.first;
        }
    }
    cout<<res<<' '<<maxx;
    return 0;
}