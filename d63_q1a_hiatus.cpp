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
    int n,m;
    cin>>n>>m;
    vector<int> v;
    while(n--){
        int a,b;
        cin>>a>>b;
        v.emplace_back(a*100+b);
    }
    sort(v.begin(),v.end());
    while(m--){
        int a,b;
        cin>>a>>b;
        a = a*100+b;
        auto it = lower_bound(v.begin(),v.end(),a);
        if(*it == a) cout<<"0 0 ";
        else if (it != v.begin()){
            it--;
            cout<<(*it/100)<<' '<<(*it%100)<<' ';
        }else{
            cout<<"-1 -1 ";
        }
    }
    return 0;
}