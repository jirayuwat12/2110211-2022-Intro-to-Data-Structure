#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  CP::stack<T> s;
  while(first != last){
    s.push(*(first++));
  }
  mCap = s.size();
  mSize = s.size();
  mData = new T[mCap]();
  for(int i = 0;i<mSize;i++){
    mData[i] = s.top();
    s.pop();
  }
}

#endif
