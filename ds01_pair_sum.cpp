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
    int N,M;
    cin>>N>>M;
    multiset<int> s;
    FOR(i,0,N){
        int j;
        cin>>j;
        s.insert(j);
    }
    while(M--){
        int t;
        cin>>t;
        bool ck = false;
        auto it = s.begin();
        while(it != s.end()){
            int cnt = s.count(t-*it);
            if((cnt==1 && (t/2!=*it)) || (cnt>=2 && (t/2==*it))){
                ck=true;
                break;
            }
            it++;
        }
        if(ck){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<'\n';
    }
    return 0;
}