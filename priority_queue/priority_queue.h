#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

namespace CP{
    
    template<typename T, typename Comp = std::less<T>>
    class priority_queue{
    protected:
        /*
            -root at index 0
            -for all node that index i their children must be index (2*i)+1 and (2*i)+2
                                             parent   must be index (i-1)/2
        */
        T * mData;
        size_t mCap;
        size_t mSize;
        Comp mLess;
        void expand(size_t capacity){
            auto temp = mData;
            mData = new T[capacity]();
            for(size_t i = 0;i< mSize;i++) mData[i] =temp[i];
            mCap = capacity;
            delete [] temp;
        }
        void fixUp(size_t index){
            T temp = mData[index];
            while(index > 0){
                size_t p = (index-1)/2;
                if(mLess(mData[p],mData[index])){
                    mData[index] = mData[p];
                    index = p;
                }else break;
            }
            mData[index] = temp;
        }
        void fixDown(size_t index){
            T temp = mData[index];
            size_t c;
            while((c = 2*index + 1) < mSize){
                if(c+1 < mSize && mLess(mData[c],mData[c+1])) c++;
                if(mLess(temp,mData[c])){
                    mData[index] = mdata[c];
                    index = c;
                }else break;
            }
            mData[index] = temp;
        }

    public:
    // constructor
        priority_queue(const Comp & c = Comp()) :
            mData(new T[1]()),
            mSize(0),
            mCap(1),
            mLess(c)
        {}
        priority_queue(priority_queue<T,Comp>& a) :
            mData(new T[a.mCap]()),
            mSize(a.mSize),
            mCap(a.mCap),
            mLess(a.mLess)
        {
            for(size_t i = 0;i<mSize;i++) mData[i] = a.mData[i];
        }
        priority_queue<T,Comp>& operator=(priority_queue<T,Comp> other){
            using std::swap;
            swap(mSize,other.mSize);
            swap(mCap,other.mCap);
            swap(mData,other.mData);
            swap(mLess,other.mLess);
            return *this;
        }
        ~priority_queue(){
            delete [] mData;
        }

    // capacity function
        bool emplty() const{
            return mSize == 0;
        }
        bool size() const{
            return mSize;
        }
    
    // access
        T top();

    // modifier
        void push(const T &element){
            if(mSize + 1 > mCap) expand(mCap * 2);
            mData[mSize++] = element;
            fixUp(mSize-1);
        }
        void pop(){
            mData[0] = mData[mSize-1];
            mSize--;
            fixDown(0);
        }

    }
}

#endif