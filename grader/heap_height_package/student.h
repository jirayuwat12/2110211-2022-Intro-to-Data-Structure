#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
  int h = -1;
  int s = 1;
  if(this->size() == 0) return -1;
  while(s <= this->size()){
    h++;
    s *=2;
  }
  return h;
}

#endif

