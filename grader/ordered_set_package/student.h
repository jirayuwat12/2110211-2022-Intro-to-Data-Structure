#include <vector>
using namespace std;

#include<set>

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v = A;
    set<T> s;
    for(auto i : A) s.insert(i);
    for(auto i : B){
        if(!s.count(i)) v.push_back(i);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    for(auto i : B) s.insert(i);
    for(auto i : A){
        if(s.count(i)) v.push_back(i);
    }
    return v;
}
