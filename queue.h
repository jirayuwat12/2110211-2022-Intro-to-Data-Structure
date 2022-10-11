#ifndef _CP_QUEUE_H
#define _CP_QUEUE_H

namespace CP
{
    //circular queue
    template <typename T>
    class queue{
        protected:
            size_t mFront;
            size_t mSize,mCap;
            T* mData;

        public:
            //construct and de construct
            queue(){
                mFront=-1;
                mSize=0;
                mCap=1;
                mData =  new T[mCap]();
            }
            queue(const queue<T> a) : mData(new T[a.mCap]()), mCap(a.mCap), mSize(a.mSize), mFront(a.mFront){
                for(size_t i=0;i<a.mCap;i++) mData[i] = a.mData[i];
            }
            ~queue(){
                delete [] mData;
            }
            //operator overload
            queue<T> & operator=(queue<T> other){
                std::swap(mFront,other.mFront);
                std::swap(mSize,other.mSize);
                std::swap(mCap,other.mCap);
                std::swap(mData,other.mData);
                return *this;
            }
            
            bool empty() const return mSize ==0;
            size_t size() const return mSize;
            T front() const return mData[mFront];
            T back() const return mData[(mFront + mSize -1) % mCap];

            void push(const T& element) {
                if(mSize >= mCap){
                    T* temp = new T[mCap*2]();
                    for(int i = 0;i<mSize;i++){
                        temp[i] = mData[(mFront+i)%mCap];
                    }
                    delete [] mData;
                    mData = temp;
                    mCap *=2;
                    mFront =0;
                }
                mData[(mFront + mSize)%mCap] = element;
                mSize ++;
            }
            T pop(){
                mFront = (mFront+1) % mCap;
                mSize -- ;
                return mData[(mFront-1+mCap)%mCap];
            }
    }
} // namespace CP


#endif