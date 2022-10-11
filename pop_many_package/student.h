#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  if(K > mSize) K = mSize;
  while(K--){
    this->pop();
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  //
  //don't forget to return an std::stack
  std::stack<T> t,t2;
  if(K > mSize) K = mSize;
  while(K--){
    t.push(this->top());
    this->pop();
  }
  while(!t.empty()){
    t2.push(t.top());
    t.pop();
  }
  return t2
}

#endif
