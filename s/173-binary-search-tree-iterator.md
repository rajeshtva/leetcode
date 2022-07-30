# 173. Binary search tree iterator

[link](https://leetcode.com/problems/binary-search-tree-iterator/)

**Level**: Medium

**Memory Use**:  25.5 MB

**Time**: 44 ms

**Explanation**: 
- traverse in-order on the binary search tree and put all elements in the an array.
- main currentPosition to store the position of current accessed index.

**Space complexity**: $O(n)$
**time complexity**: $O(n)$, for storing the element
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    vector<TreeNode*>bucket;
    int currentPosition = 0;
public:
    BSTIterator(TreeNode* root) {
        inorderTraverse(root);
    }
    
    int next() {
        if(currentPosition < bucket.size()) {
            return bucket[currentPosition++]->val;
        }
        
        return -1;
    }
    
    bool hasNext() {
        return currentPosition < bucket.size();
    }
    
    void inorderTraverse(TreeNode* root){
      if (root == nullptr) {
            return;
        }

        inorderTraverse(root->left);

        bucket.push_back(root);
        
        inorderTraverse(root->right);
        
        return;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

```

## follow up question.
**reduce space complexity to O(h)**
- `h` is height of binary search tree.

**Explanation :**
- use stack to put all left elements of a root initially. 
- when visiting any subsequent root, again iterate all the left nodes.

```cpp

```


