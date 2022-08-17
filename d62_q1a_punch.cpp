#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
    int i = it-v.begin();
    for(int j = ((i+k>=v.size())?v.size()-1:i+k);j>=((i-k<0)?0:i-k);j--){
        v.erase(v.begin()+j);
    }
    return v;
}
int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result) {
        cout << x << endl;
    }
}