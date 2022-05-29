# inorder traversal

**Recursive Approach:**

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> output;
        TreeNode* node = root;
        stack<TreeNode*> bucket;

        if (root == nullptr)
            return {};

        while (true) {
            if (node != nullptr) {
                bucket.push(node);
                node = node->left;
            } else {
                if (bucket.empty())
                    break;

                node = bucket.top();
                bucket.pop();

                output.push_back(node->val);
                node = node->right;
            }
        }

        return output;
    }
};
```
