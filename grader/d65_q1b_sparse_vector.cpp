#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int,int> &v, int pos, int value) {
    //your code here
    if(v.find(pos) == v.end()) v[pos] = value;
    else if(v.find(pos+1) == v.end()){
        v[pos+1] = v[pos];
        v[pos] = value;
    }else{
        int temp = v[pos];
        v[pos] = value;
        while(v.find(pos+1) != v.end()){
            auto t = v[pos+1];
            v[pos+1] = temp;
            temp = t;
            pos++;
        }
        v[pos+1] = temp;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    map<int,int> v;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        insert_into_sv(v,a,b);
    }
    cout << v.size() << "\n";
    for (auto &x : v) {
        cout << x.first << ": " << x.second << "\n"; 
    }
}


//121