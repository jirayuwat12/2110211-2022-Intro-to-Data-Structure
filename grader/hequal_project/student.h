#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
  if(this->size() != other.size()) return false;
  auto t1 = *this;
  auto t2 = other;
  while(!t1.empty()){
    if(t1.top() != t2.top() ) return false;
    t1.pop();
    t2.pop();
  }
  return true;
}

#endif
