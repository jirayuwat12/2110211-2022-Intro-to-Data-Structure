#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    auto temp  =mData[idx];
    while(idx>0){
        size_t p = (idx-1) / 4;
        if(mLess(mData[p],temp)) {
            mData[idx] = mData[p];
            idx = p;
        }else break;
    }
    mData[idx] = temp;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    auto temp = mData[idx];
    while(idx*4 + 1 < mSize ){
        size_t c = idx * 4 + 1;
        if(idx*4 + 2 < mSize && mLess(mData[c],mData[idx*4 + 2])){
            c = idx * 4 +2; 
        } if(idx*4 + 3 < mSize && mLess(mData[c],mData[idx*4 + 3])){
            c = idx * 4 +3; 
        } if(idx*4 + 4 < mSize && mLess(mData[c],mData[idx*4 + 4])){
            c = idx * 4 +4; 
        }
        
        if(mLess(temp,mData[c])){
            mData[idx] = mData[c];
            idx = c;
        }else break;
    }
    mData[idx] = temp;
}

#endif

