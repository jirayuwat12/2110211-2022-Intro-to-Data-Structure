#include<bits/stdc++.h>
#include "pair.h"
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

template<typename T1,typename T2>
void printPair(CP::pair<T1,T2> p){
    cout<<p.first<<","<<p.second<<' ';
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    CP::pair<int,int> p1,p2;
    printPair(p1);
    cout<<'\n';
    printPair(p2);
    cout<<'\n';
    cout<<(p1==p2)<<'\n';
    CP::pair<int,int> p3(1,2);
    printPair(p3);
    cout<<'\n';
    cout<<(p1<p3)<<'\n';
    vector<CP::pair<int,int>> v;
    FOR(i,0,5){
        v.PB({5-i,i+2});
    }
    sort(v.begin(),v.end());
    FOR(i,0,5) printPair(v[i]);
    return 0;
}