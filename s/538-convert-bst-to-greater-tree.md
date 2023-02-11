```cpp

class Solution {

public:
    TreeNode* increasingBST(TreeNode* root)
    {
        // do something ehre.

        if (root == nullptr)
            return root;

        root->left = increasingBST(root->left);
        root->right = increasingBST(root->right);

        if (root->left != nullptr) {
            TreeNode* newRoot = root->left;

            TreeNode* temp = root->left;
            while (temp->right != nullptr)
                temp = temp->right;
            temp->right = root;
            root->left = nullptr;

            root = newRoot;
        }

        return root;
    }
};
```
