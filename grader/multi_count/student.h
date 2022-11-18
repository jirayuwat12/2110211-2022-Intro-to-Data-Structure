#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>
template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    std::map<T,int> m; 
    std::vector<std::pair<T,size_t>> ret;
    for(auto i : k) m[i] = 0;
    for(int i =mFront;i!=(mFront+mSize)% mCap;i=(i+1) % mCap){
        if(m.find(mData[i]) != m.end()) m[mData[i]] ++;
    }
    for(auto i : k) ret.push_back({i,m[i]});
    return ret;
}

#endif
