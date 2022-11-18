#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    auto temp = mData[(mFront+pos) % mCap];
    for(int i = (mFront+pos)%mCap;i!=mFront;i=(i-1+mCap)%mCap){
        mData[i] = mData[(i-1+mCap)%mCap];
    }
    mData[mFront] = temp;

}

#endif
