#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  CP:: vector<T> temp;
  int ind = 0;
  for(int i = 0;i<size();i++){
    if(ind < pos.size() && i==pos[ind]) ind++;
    else{
      temp.push_back(mData[i]);
    }
  }
  *this = temp;
}

#endif
