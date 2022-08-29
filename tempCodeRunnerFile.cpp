#include<bits/stdc++.h>
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define FORR(i,s,n) for(int i=n-1;i>=s;i--)
#define REP(i,n) FOR(i,0,n)
#define FOREACH(i,t) for(__typeof(t.begin()) i=t.begin();i!=t.end();i++)
#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define sqr(x) ((x)*(x))
#define ll long long
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLL vector<long long>
#define SII set<int>
#define MII map<int,int>
#define SI2 set<pair<int,int> >
#define SI3 set<tuple<int,int,int> >
#define MII map<int,int>
#define MIII map<int,map<int,int> >
#define MSS map<string,string>
#define MIS map<int,string>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v;
    int minn,maxx;
    FOR(i,0,n){
        int t;
        cin>>t;
        v.emplace_back(t);
    }
    sort(v.begin(),v.end());
    while(m--){
        int p;
        cin>>p;
        auto lit = lower_bound(v.begin(),v.end(),p-k);
        auto rit = upper_bound(v.begin(),v.end(),p+k);
        cout<<rit-lit<<' ';
    }
    return 0;
}