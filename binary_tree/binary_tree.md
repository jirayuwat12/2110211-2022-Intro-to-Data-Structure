# Binary tree
- a *rooted tree* where each node have at most 2 children
- tree node is very similar to a *linked list* node

using class node linke *linked list*
```C++
template<T>
class node{
protected:
    T value;
    node *left, *right, *parent;
public:
    node(): 
        value(T()),
        left(NULL),
        right(NULL),
        parent(NULL)
    {}
    node(T value,node *left,node *right,node * parent):
        value(value),
        left(left),
        right(right),
        parent(parent)
    {}
};
```
<u>note</u> we will use pointer and node instead using dynamic array

## Application

1. huffman coding

    *more often more less bit* 

    [video by A.nattee](https://www.youtube.com/watch?v=Vl1cvG4fpME&list=PLW3DcQsnGanPGhY2Y0A9hc45KnfS55RZI&index=72)
    
    >input : a string
    >
    >output : encodeing of each character in the string such that
    >   - total lenght of encodeing the tring is **minimum**
    >   - the encodeing of charactor isnot ambiguous ( we can say "no charactor that is a prefix of other charactor" )
    >
    ><u>solution from geek for geek</u>
    >[code](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)

