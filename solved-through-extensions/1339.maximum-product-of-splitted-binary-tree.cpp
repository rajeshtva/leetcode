/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 */
#include "includes/leetcode.h"
using namespace std;
// @lc code=start
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
    int maxProduct(TreeNode* root)
    {
        typedef long long ll;
        ll sum = 0, maxValue = 0;
        int M = 1e9+7;
        function<void(TreeNode*)> findSum = [&](TreeNode* r) {
            if (r == nullptr)
                return;

            sum += r->val;

            findSum(r->left);
            findSum(r->right);
        };

        function<ll(TreeNode * r)> calculate = [&](TreeNode* r) -> int {
            if (r == nullptr)
                return 0;

            ll left = 0;
            ll right = 0;
            ll o, m;

            left = calculate(r->left);
            right = calculate(r->right);

            o = sum - left;
            m = sum - right;
            maxValue = max(maxValue, o * left);
            maxValue = max(maxValue, m * right);

            return r->val + left + right;
        };

        findSum(root);
        calculate(root);

        return maxValue % M;
    }
};
// @lc code=end
