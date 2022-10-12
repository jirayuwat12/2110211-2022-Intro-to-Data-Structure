# Linked List

from vector to insert or erase takes **O(n)** but it's very fast to access i index with **O(1)**

but linked list is on other hand. it can access in **O(n)** and insert/erase in **O(1) with iterator to that position**

<u>note</u> insert/erase with index take **O(n)** 


|List   |Vector|
|-------|------|
|- allocate each data seperately| - allocate data as a consecutive block|
|1.each data points where is the next data|1.very fast to access any element|
|2.very fast insert/erase|2.very slow insert/erase requires every element after point of insertion|
|3.very slow access because we donot know where k-th element is| |
<br>

## Inner class node for SLL(Singly LL)
```C++
class node{
public:
    T data;
    node *next;
    node(): 
        data(T()), 
        next(NULL)
    {}

    node(const T & data,node * next):
        data(T(data)),
        next(next)
    {}
};
```
## Inner class node for DLL(Doubly LL)
```C++
class node{
public:
    T data;
    node *next,*prev;
    node(): 
        data(T()), 
        next(NULL),
        prev(NULL)
    {}

    node(const T & data,node * next,node * prev):
        data(T(data)),
        next(next),
        prev(prev)
    {}
};
```

## How to fix slow push_back and pop_back problem
solution is
### CLL(circular linked list) or CDLL(circular boubly linked list)

1. CLL : head point to last element and last element point to first element

1. CDLL : CLL and DLL assemble

### finally add header node to make code *more  cleaner*

## Final version of list CDLL with header

```C++
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
```

```
diagram for list
                      v---------------------------------------------------------
---------------     -----------------    ----------------   -----------------  |
|mSize  mFirst|     |   |       |   |--->|  |data   |   |-->|   |data   |   |---
|2            |---->| | |       |   |<---|  |4      |   |<--|   |32     |   |
---------------     --|--------------    ----------------   -----------------
                      |      ^                   ^                       ^
                      -------|-------------------|-----------------------|
                             |                   |
                      -----  |            -----  |
                      |ptr|---            |ptr|---
                      -----               -----
                      end()               begin()
```