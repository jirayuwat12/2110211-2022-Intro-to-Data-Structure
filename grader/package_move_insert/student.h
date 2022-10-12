#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  if(k> this->mSize) k = this->mSize;
  if(m>=s2.size()) m = s2.size();
  auto t = this->mData;
  auto t_size = mSize;
  this->mData = new T[this->mSize + m](); 
  this->mCap = this->mSize +m;
  this->mSize = this->mCap;
  for(int i =0;i<t_size - k;i++){
    mData[i] = t[i];
  }
  for(int i = t_size-k;i<t_size;i++){
    mData[i+m] = t[i];
  }
  for(int i = m-1;i>=0;i--){
    mData[t_size-k+i] = s2.top();
    s2.pop();
  }
  
}
#endif
