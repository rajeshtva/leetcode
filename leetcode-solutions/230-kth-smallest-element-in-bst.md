# 

[link](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
**Level**: medium 

**Memory Use**:  24.2 MB

**Time**: 25ms

**Explanation**:
- preorder traverse the array. since all smaller elements must be on the left.
- return only when `k_count` is 0. 

**Space complexity**: $O(n)$
**time complexity**: $O(n)$


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
class Solution {
public:
    int kthsmallest = 0;
    int k_count;
    int kthSmallest(TreeNode* root, int k)
    {
        if (root == nullptr) {
            return 0;
        }
        k_count = k;

        TreeNode* element = findIt(root);

        if (element != nullptr) {
            root = element;
        }

        return root->val;
    }

    TreeNode* findIt(TreeNode* root)
    {
        if(root == nullptr){
            return root;
        }
        TreeNode* temp = nullptr;
        temp = findIt(root->left);

        if(temp != nullptr){
            return temp;
        } 

        k_count-- ;
        if(k_count == 0) {
            return root;
        }
        
        return findIt(root->right);
    }
};

```
