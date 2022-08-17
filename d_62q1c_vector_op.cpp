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
    int q;
    cin>>q;
    string a;
    int b;
    vi res;
    while(q--){
        cin>>a;
        if(a=="pb"){
            cin>>b;
            res.push_back(b);
        }if(a=="sa"){
            sort(res.begin(),res.end());
        }if(a=="sd"){
            sort(res.begin(),res.end(),greater<int>());
        }if(a=="r"){
            reverse(res.begin(),res.end());
        }if(a=="d"){
            cin>>b;
            res.erase(res.begin()+b);
        }
    }
    for(auto i : res){
        cout<<i<<' ';
    }
    return 0;
}