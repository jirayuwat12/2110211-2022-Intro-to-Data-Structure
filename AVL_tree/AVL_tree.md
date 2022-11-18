# AVL tree

![AVL tree](https://upload.wikimedia.org/wikipedia/commons/f/fd/AVL_Tree_Example.gif)

[<u> note</u> video by A.nattee](https://www.youtube.com/watch?v=XyI9bcQxE7Q&list=PLW3DcQsnGanPGhY2Y0A9hc45KnfS55RZI&index=82)

**self - balanced tree**

AVL = BST + height rules

- height rules
    - `| hl - hr | <= 1` ; h = height of sub-tree

hence, height of AVL tree is <= 1.44 log2(n)

## AVL Rotation

### insert/ erase

1. insert/ erase like BST
1. fix the tree to follow height rules( *look in code* )

[code here](../map_avl/map_avl.h)

### rotation

1. rotate left at node r ( as root )
    1. `root = r->left`
    1. `r->left = r->left->right`
    1. `root->right = r`
1. rotate right at node r ( as root )
    1. `root = r->right`
    1. `r->right = r->right->left`
    1. `root->left = r`