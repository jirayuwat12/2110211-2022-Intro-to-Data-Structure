#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::find(T k) const {
  //your code here
  for(int i =0;i<mSize;i++){
    if(mLess(mData[i],k)) return false;
    if(mLess(mData[i],k) ==mLess(k,mData[i])) return true;
  }
  return false;
}

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::find_level(T k) const {
  //your code here
  if(!this->find(k)) return -1;
  int x;
  for(int i =mSize-1;i>=0;i--){
    if(mLess(mData[i],k) ==mLess(k,mData[i])) {
      x = i;
      break;
    }
  }
  int h=0;
  while(x>0) x = (x-1)/2,h++;
  return h;
}

#endif

