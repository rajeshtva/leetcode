# Construct Binary Tree from Inorder and Postorder Traversal

[link](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal)
**Level**: Easy

**Explanation**:

- the last node of the postorder vector is the root node of entire tree.
- the inorder array will give the length of the left subtree.
- first store position of all elements of inorder tree in a hashtable for future reference. 

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        map<int, int> table;

        for (int i = 0; i < inorder.size(); i++) {
            table[inorder[i]] = i;
        }

        TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, table);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
        vector<int>& postorder, int postStart, int postEnd,
        map<int, int>& table)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = table[root->val];

        int count = inRoot - inStart;

        root->left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + count - 1, table);
        root->right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + count, postEnd - 1, table);

        return root;
    }
};


```
