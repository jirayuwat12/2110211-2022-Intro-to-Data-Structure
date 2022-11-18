#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  if(this->size() != other.size()) return false;
  int ind1 = this->mFront;
  int ind2 = other.mFront;
  for(int i = 0;i<this->size();i++){
    if(mData[ind1] != other.mData[ind2]) return false;
    ind1 = (ind1+1) % mCap;
    ind2 = (ind2+1) % other.mCap;
  }
  return true;
}

#endif
