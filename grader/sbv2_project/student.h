#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>

template <typename T>
size_t CP::stack<T>::size() const {
  //write your code here
  return v.size();
}

template <typename T>
const T& CP::stack<T>::top() const {
  //write your code here
  return v.back();
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  //write your code here
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  //write your code here
  v.pop_back();
}

template <typename T>
void CP::stack<T>::deep_push(const T& element, int depth) {
  //write your code here
  int pos = v.size() -1 -depth;
  pos = pos<0?0:pos;
  v.insert(v.begin() +pos,element);
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w) {
  //write your code here
  for(T i : w) v.push_back(i);
}

template <typename T>
void CP::stack<T>::pop_until(const T& e) {
  //write your code here
  while(v.size() != 0 && v.back() != e){
    v.pop_back();
  }
}

#endif

