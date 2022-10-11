# Priority queue by *binary heap*
## basic knowledge

### Graph and Tree

1. tree
    - \# of node = n
    - \# of edge = n-1
1. rooted tree
    - must have one node that be **root**
    - distance from root to leave is **depth**
1. Complete binary tree
    - every node must have at most **2 children**
    - every level must full ( *n level have 2^(n-1) node* )
    - **from that 2 properties make max depth is log2(n)**
1. Binary heap
    - be *complete binary tree*
    - every node must have greater( or equal ) value than thier children

## priority queue idea
```
start Binary heap 
                75
             /       \
           50          65
        /     \       /   \
     40         3    4     10
   /   \      / 
35      36   2    
```
- add node

then add 1 node value = 60
```
add 60 
                75
             /       \
           50          65
        /     \       /   \
     40         3    4     10
   /   \      /   \
35      36  2     *60*
```
*but it make wrong value property of binary heap* then swap parent and child

```
fix node step 1
                75
             /       \
           50          65
        /     \       /   \
     40       *60*   4     10
   /   \      /   \
35      36  2      3
```
```
fix node step 2
                75
             /        \
          *60*         65
        /     \       /   \
     40        50   4     10
   /   \      /   \
35      36  2      3
```
<u>note</u> \# of fixing step at most log2(n) which n = \# node

 - delete max node

```
                75
             /       \
           50          65
        /     \       /   \
     40         3    4     10
   /   \      / 
35      36   2    
```
set value of root node as most-right leave and delete most-right leave
```
                *2*
             /       \
           50          65
        /     \       /   \
     40         3    4     10
   /   \       
35      36     
```

then compare value to ther children

1. case 1 : have 2 children
    - swap value with max value children if that value more than parent node
1. case 2 : have 1 child
    - swap calue with child if that value more than parent node

```
step 1
                65
             /       \
           50          *2*
        /     \       /   \
     40         3    4     10
   /   \       
35      36     
```
```
step 2
                65
             /       \
           50          10
        /     \       /   \
     40         3    4     *2*
   /   \       
35      36     
```
<u>note</u>  \# of fixing step at most log2(n) which n = \# node

## Analysis
number of node is n

so depth = log2(n)

- **push  and pop function**

    can run within O(log(n)) 
    
    because number of depth is the maximum path to fix all node with *right algorithm* as we show 
- **top function**

    can run wothin Θ(1) 

    as we know all parent *must have* value more or equal than their children so **the maximum value is *root node***
