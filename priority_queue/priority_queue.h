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
        priority_queue(std::vector<T> &v,const Comp& c = Comp()) :
            mData(new T[v.size()]()),
            mCap(v.size()),
            mSize(v.size()),
            mLess(c)
        {
            for(size_t i = 0;i<mSize;i++) mData[i] = v[i];
            for(int i = mSize/2-1;i>0;i--) fixDown(i); 
        }
        /*
            common sence 
                >>O(nlog(n))
                every step i  <= log2(i)
                so total <= log2(1) + log2(2) + ... + log2(n)
                total <= log2(1 x 2 x ...  x n)
                total <= log2(n!) which <= n x log(n)
                hence, O(nlog(n))
            with fixDown
                >>O()
                for tree depth = 4
                -----------------------------------------
                |depth   |# nodes     |#max fix per node|
                |--------|------------|-----------------|
                |0       |1           |4                |    
                |1       |2           |3                |    
                |2       |4           |2                |    
                |3       |8           |1                |    
                |4       |16          |0                | 
                |...     |...         |...              |    
                -----------------------------------------
                so for tree depth = k
                k        2^k           h-k which h = level
                total = sum of k*2^(h-k) from h = 0 to k
                total = 2^h * sum(k*2^(-k))
                total < 2^h * 2
                total < 2^(h+1) which h = log2(n)
                total < 2^(log2(n) +1)
                total < 2*n
                hence, O(n)
        */
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