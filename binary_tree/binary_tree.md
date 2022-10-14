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
    >my solution [code](huffman_code.cpp)

# Binary Search Tree (BST)

- must be *binary tree*
- value rules for node *x*
    1. data in left-subtree nust be **less than** the data in *x*
    1. data in right-subtree must be **more than** the data in *x*  

## `insert` element in BST

1. *case 1* e is in tree
    - do nothing
1. *case 2* e isnot in tree
    - insert e to a leave of the tree in correct branch ( *left* if e **less than** and *right* if e **more than** ) 

## `erase` element in BST

1. that node have 0,1 child
    - just delete it from tree and link their parent to `NULL` or its children ( in case 1 child ) 
1. that node have 2 children
    - need to think about value rules 
    
    choose the maximumm value node from L-subtree **(predecessor)** or minimum value node from R-subtree **(successor)** and erase that node from tree

    <u>note</u> either **predecessor** or **successor** always have at most 1 child 

## complexity analysis

- `insert`, `erase` depends on `find`, `find_min`, `find_max`
- `find` take O(h) that h = height of tree
- h in best case for BST is log2(n)
- h in worst case for BST is n

so `insert`, `erase` and all kind of `find` function takes **O(n)** ( like dymanic array )


code for [CP::map_bst](../map_bst/map_bst.h)
