#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <assert.h>

template <typename T,typename Comp>
void CP::priority_queue<T,Comp>::change_value(size_t pos,const T& value) {
  mData[pos] = value;
  // if(pos>=1 && mData[(pos-1)/2] <= value) fixUp(pos);
  // else fixDown(pos);
  fixDown(pos);
  fixUp(pos);
}

#endif