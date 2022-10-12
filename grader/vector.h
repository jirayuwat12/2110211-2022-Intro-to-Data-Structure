#ifndef _CP_VECTOR_H
#define _CP_VECTOR_H

namespace CP
{
    template <typename T>
    class vector{
      protected:
        size_t mSize,mCap;
        T * mData;

        void rangeCheck(int index){
            if( n<0 || (size_t)n >= mSize) throw std::out_of_range("index out of range");
        }
        void ensureCapacity(int size){
            if(size >= mCap){
                size_t s = (size > 2*mCap)? size:2*mCap;
                expand(s);
            }
        }
        void expand(int s){
            mCap =s;
            T * temp = new T[mCap]();
            for(int i =0;i<mSize;i++){
                temp[i] = mData[i];
            }
            delete [] mData;
            mData = temp;
        }

      public:  
        typedef T* iterator;
        //constructor and deconstructor
        vector(){
            mSize=0;
            mCap=1;
            mData = new T[mCap]();
        }
        vector(size_t mCap){
            this->mCap = mCap;
            mSize = mCap;
            mData = new T[mCap]();
        }
        vector(size_t mCap,const T& value){
            this->mCap = mCap;
            mSize = mCap;
            mData = new T[mCap]();
            for(int i =0;i<mSize;i++) mData[i] = value;
        }
        ~vector(){
            delete [] mData;
        }
        vector(vector<T> other){
            this->mSize = other.size();
            this->mCap = other.capacity();
            this->mData = new T[mCap]();
            for(int i =0;i<mSize;i++) mData[i] = other[i];
        }
        //utilities
        bool empty() const{
            return mSize == 0;
        }
        size_t size() const{
            return this->mSize;
        }
        size_t capacity() const{
            return this->mCap;
        }
        iterator insert(iterator it,const T& element){
            size_t pos = it-begin();
            ensureCapacity(mSize+1);
            for(size_t i = mSize;i>pos;i--) mData[i] = mData[i-1];
            mData[pos] = element;
            mSize++;
            return begin()+pos;
        }
        void erase(iterator it){
            while((it+1)!= end()) *it = *(it++ +1);
            mSize--;
        }
        void push_back(const T& element){
            insert(end(),element);
        }
        void pop_back(){
            mSize --;
        }
        void operator=( vector<T> other){
            std::swap(this->mSize,other.mSize);
            std::swap(this->mCap,other.mCap);
            std::swap(this->mData,other.mData);
        } 
        // access
        T& at(int index){
            rangeCheck(index);
            return mData[index];
        }
        T& operator[](int index){
            return mData[index];
        }
        T& back(){
            return mData[mSize-1];
        }
        // iterator
        iterator begin(){
            return &mData[0];
        }
        iterator end(){
            return begin() + mSize;
        }
    };
} // namespace CP


#endif