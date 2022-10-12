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
    int n,m;
    cin>>n>>m;
    vi v1(n),v2(m);
    while(n--)  cin>>v1[n];
    while(m--)  cin>>v2[m];
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i1=0,i2=0;
    int maxx = -1;
    while(i1<v1.size() &&i2 < v2.size()){
        if(v1[i1]==v2[i2] && v1[i1] > maxx) {
            cout<<v1[i1]<<' ';
            maxx = v1[i1];
            i1++;
            i2++;
        }else if(v1[i1]==v2[i2] ) i1++,i2++;
        else if(v1[i1] < v2[i2]) i1++;
        else if(v1[i1] > v2[i2]) i2++;
    }
    return 0;
}