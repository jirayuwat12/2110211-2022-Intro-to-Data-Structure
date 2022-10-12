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
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m,a;
    cin>>n>>m>>a;
    vector<int> k(n);
    map<pair<int,int>,int> b;
    FOR(i,0,n) cin>>k[i];
    while(a--){
        char t;
        cin>>t;
        if(t=='B'){
            int u,i,v;
            cin>>u>>i>>v;
            b[{u,i}] = v;
        }else{
            int u,i;
            cin>>u>>i;
            b.erase({u,i});
        }
    }
    
    priority_queue<pair<int,int>> pq[n+1];
    for(auto i : b){
        pq[i.first.second].push({i.second,i.first.first});
    }
    vector<int> ret[m+1];
    FOR(i,1,n+1){
        FOR(j,0,k[i-1]){
            if(pq[i].empty()) break;
            ret[pq[i].top().second].push_back(i);
            pq[i].pop();
        }
    }
    FOR(i,1,m+1){
        if(ret[i].size()==0) cout<<"NONE";
        else{
            FOR(j,0,ret[i].size()) cout<<ret[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}