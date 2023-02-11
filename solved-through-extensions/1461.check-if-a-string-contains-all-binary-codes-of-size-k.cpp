/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        set<string> t;
        int n = s.length();

        for (int i = 0; i <= n - k; i++) {
            string temp = s.substr(i, k);    
            t.insert(temp);        
        }

        return t.size() == pow(2, k);

    }
};
// @lc code=end
