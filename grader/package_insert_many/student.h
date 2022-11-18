#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<algorithm>
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  CP::vector<T> temp(size() + data.size());
  sort(data.begin(),data.end());
  int ind1 = 0;
  int ind2 = 0;
  for(int i = 0;i<size() + data.size();i++){
    if(ind1 >= data.size()) {
      temp[i] =mData[ind2++];
    }else if(ind2 >= size()){
      temp[i] =data[ind1++].second;
    }else if(data[ind1].first == ind2 ){
      temp[i++] = data[ind1++].second;
      temp[i] = mData[ind2++];
    }else{
      temp[i] = mData[ind2++];
    }
  }
  *this = temp;
}

#endif
