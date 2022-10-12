#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

namespace CP{    

    template<typename T>
    class list{
    protected:
        class node{
        friend class list;
        public:
            T data;
            node *next, *prev;
            node(): 
                data(T()), 
                next(this),
                prev(this)
            {}

            node(const T & data,node * prev,node * next):
                data(T(data)),
                next(next),
                prev(prev)
            {}
        };
        class list_iterator{
        friend class list;
        protected:
            node *ptr;
        public:
            list_iterator() : ptr(NULL) {}
            list_iterator(node * a) : ptr(a){}

            list_iterator& operator++(){
                ptr = ptr->next;
                return *this;
            }
            list_iterator& operator--(){
                ptr = ptr->prev;
                return *this;
            }
            list_iterator& operator++(int){
                list_iterator tmp(*this);
                operator++();
                return tmp;
            }
            list_iterator& operator--(int){
                list_iterator tmp(*this);
                operator--();
                return tmp;
            }
            list_iterator& operator*() return ptr->data;
            list_iterator& operator->() return &(ptr->data);
            bool operator==(const list_iterator& other) return other.ptr == ptr;
            bool operator!=(const list_iterator& other) return other.ptr != ptr;
            
        };
    protected:
        node *mHeader;
        size_t mSize;
    public:
        typedef list_iterator iterator;
    public:
        //constructor

        list() :
            mHeader(new node()),
            mSize(0)
        {}
        list(list<T>& a) : mHeader(new node()),mSize(0) {
            for(iterator it = a.begin();it != a.end();it++){
                push_back(*it);
            }
        }
        ~list() {
            clear();
            delete mHeader;
        }

        //operator =
        list<T>& operator= (list<T> other){
            using std::swap;
            swap(this->mHeader,other.mHeader);
            swap(this->mSize,other.mSize);
            return *this;
        } 
        
        //capacity
        bool empty() const return mSize ==0;
        size_t size() const return mSize;

        //access
        T& front(){
            return mHeader->next->data;
        }
        T& back(){
            return mHeader->prev->data;
        }

        //modifier
        void push_back(const T& element){
            insert(end(),element);
        }
        void push_front(const T& element){
            insert(begin(),element);
        }
        void pop_back(){
            erase(iterator(mHeader->prev));
        }
        void pop_front(){
            erase(begin());
        }
        void clear(){
            while(mSize >0) erase(begin());
        }
        iterator insert(iterator it,const T& element){
            node *n = new node(element,it.ptr->prev,it.ptr->next);
            it.ptr->prev->next = n;
            it.ptr->prev = n;
            mSize ++;
            return iterator(n);
        }
        iterator erase(iterator it){
            iterator tmp(it.ptr->next);
            it.ptr->prev->next = it.ptr->next;
            it.ptr->next->prev = it.ptr->prev;
            delete it.ptr;
            mSize --;
            return tmp;
        }

        //iterator
        iterator begin(){
            return iterator(mHeader->next);
        }
        iterator end(){
            return iterator(mHeader);
        }
    }
}
#endif