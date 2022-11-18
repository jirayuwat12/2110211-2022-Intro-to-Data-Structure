#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  int f = (mFront + pos ) % mCap;
  int l = (mFront + mSize-1) % mCap;
  T temp = mData[f];
  for(int i = f;i != (mFront+mSize-1)%mCap;i=(i+1)%mCap){
    mData[i] = mData[(i+1) % mCap];
  }
  mData[l]  = temp;
}

#endif
