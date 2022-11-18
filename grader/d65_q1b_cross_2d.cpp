#include <iostream>
#include <vector>
using namespace std;
void cross_2d(vector<vector<int>> &m ,int r1, int r2, int c1, int c2) {
 //your code here
    vector<vector<int>> ret(m.size() - (r2-r1+1),vector<int>(m[0].size() - (c2-c1+1),0));
    int x = 0;
    int y = 0;
    for(int i = 0;i<m.size();i++){

        for(int j =0;j<m[0].size();j++){
            if((r1<= i && i <= r2) || (c1<= j && j <= c2)) {}
            else{
                ret[x][y] = m[i][j];
                y++;
            }
        }
        if(r1<= i && i <= r2) x--;
        x++;
        y=0;
    }
    m = ret;
}
int main() {
 ios_base::sync_with_stdio(false);cin.tie(0);
 vector<vector<int>> m;
 int r,c,r1,r2,c1,c2;
 cin>> r >> c;
 cin >> r1 >> r2 >> c1 >> c2;
 m.resize(r);
 for (int i =0;i < r;i++) {
 m[i].resize(c);
 for (int j = 0;j < c;j++) {
 cin >> m[i][j];
 }
 }
 cross_2d(m,r1,r2,c1,c2);
 for (int i =0;i < m.size();i++) {
 for (int j = 0;j < m[i].size();j++) {
 cout << m[i][j] << " ";
 }
 cout << "\n";
 }
 return 0;
}
// 3 3 1 1 1 1 1 2 3 4 5 6 7 8 9