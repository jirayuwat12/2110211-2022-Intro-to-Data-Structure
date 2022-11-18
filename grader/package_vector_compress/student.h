#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    auto temp = new T[size()] ();
    mCap = size();
    for(int i = 0;i<size();i++){
        temp[i] = mData[i];
    }
    auto x = mData;
    mData = temp;
    delete [] x;
}

#endif
