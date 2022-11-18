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
set<int> s;
int n,a;
void foo(int a){
    if(a >= n) return ;
    s.insert(a);
    foo(2*a+1);
    foo(2*a+2);
    
}
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    cin>>n>>a;
    foo(a);
    cout<<s.size()<<'\n';;
    for(auto i : s) cout<<i<<' ';
    return 0;
}