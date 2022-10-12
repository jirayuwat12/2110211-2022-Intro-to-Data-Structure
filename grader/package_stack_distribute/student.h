#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  CP::stack<T> s(*this);
  std::vector<std::vector<T>> ret(k);
  int n = s.size()/k;
  int q = s.size() - n*k;
  int ind = 0;
  int num = 0;
  while(!s.empty()){
    ret[ind].push_back(s.top());
    s.pop();
    num ++;
    if(num == n) {
      num = 0;
      if(q && !s.empty()){
        ret[ind].push_back(s.top());
        s.pop();
        q--;
      }
      ind ++;
    }
  }
  return ret;
}
#endif
