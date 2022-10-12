#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
      // mCap
      // mSize
      // mData
      T * tempData = mData;
      mData = new T [mCap*2]();
      for(int i = 0;i<mSize;i++){
        mData[i] = tempData[i];
      }
      for(int i = 0;i<mSize;i++){
        mData[mSize+i] = tempData[mSize-i-1];
      }
      mCap *=2;
      mSize *= 2;
      delete [] tempData;

}

#endif