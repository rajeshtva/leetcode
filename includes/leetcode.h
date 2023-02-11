/**
 * This library is for handling
 * input output for leetcode questions, (mainly)
 * contains common practices for implementing certain algos.
 *
 **/

#pragma ONCE;

#include <bits/stdc++.h>
/** ListNode implementation for ListNode.
 **/

// All Typedef's are here.
// typedef long long ll;
// typedef std::vector<ll> vll;
// typedef std::vector<int> vi;
// typedef std::set<int> si;
// typedef std::set<ll> sll;
// typedef vi::iterator viI;
// typedef sll::iterator sllI;
// typedef std::vector<std::string> vs;
// typedef std::pair<int, int> pii;
// typedef std::map<int, int> mii;
// typedef unsigned long long ull;

static inline void ltrim(std::string& s);
static inline void rtrim(std::string& s);
static inline std::string ltrim_copy(std::string s);
static inline std::string rtrim_copy(std::string s);
static inline void trim(std::string& s);
static inline std::string trim_copy(std::string s);

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

/**
 * TreeNode implementation for binary tree
 **/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

/**
 *  Tree build binary tree from input similar from leetcode.
 */

TreeNode* buildBinaryTree(std::string& serialized)
{
    serialized = serialized.substr(1, serialized.size() - 2);
    std::istringstream iss(serialized);
    std::string s;
    std::vector<int> nums;

    while (getline(iss, s, ','))
        nums.push_back(s == "null" ? -1 : stoi(s));

    if (nums.empty())
        return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    std::queue<TreeNode*> q;

    q.push(root);
    int i = 0;
    int n = nums.size();

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (++i < n && nums[i] != -1) {
            cur->left = new TreeNode(nums[i]);
            q.push(cur->left);
        }
        if (++i < n && nums[i] != -1) {
            cur->right = new TreeNode(nums[i]);
            q.push(cur->right);
        }
    }
    return root;
}

// std::vector<std::vector<char>> deserialise2dMatrix(std::string serialised);
bool isRedundant(char ch)
{
    if (ch == '"' || ch == '[' || ch == ']' || ch == ',')
        return true;

    return false;
}

template <typename T>
std::vector<T>deserialize(std::string serialised)
{
    replace_if(serialised.begin(), serialised.end(), isRedundant, ' ');
    trim(serialised);

    std::istringstream iss(serialised);
    std::vector<T> input;
    T temp;

    while (iss.rdbuf()->in_avail()) {
        iss >> temp;
        input.push_back(temp);
    }

    return input;
}
/**
 * 2d matrix input only column size
 */
template <typename T>
std::vector<std::vector<T>> deserialize2dMatrix(std::string& serialised, int c)
{
    replace_if(serialised.begin(), serialised.end(), isRedundant, ' ');

    trim(serialised);

    std::istringstream iss(serialised);
    std::vector<std::vector<T>> input(0, std::vector<T>(c));
    int rowCount = 0;

    while (iss.rdbuf()->in_avail()) {
        input.push_back(std::vector<T>(c));

        for (int i = 0; i < c; i++) {
            iss >> input[rowCount][i];
        }

        rowCount++;
    }

    return input;
}

template <typename T>
std::vector<std::vector<T>> deserialize2d(std::string s)
{
    std::string t = s.substr(1, s.size() - 2);

    int rows = count(t.begin(), t.end(), '[');
    std::vector<std::vector<T>> output;

    int beg = -1;
    int end = 0;

    for (int i = 0; i < rows; i++) {
        beg = t.find('[', beg + 1);
        end = t.find(']', beg);

        std::string p = t.substr(beg, end - beg + 1);

        auto d = deserialize<T>(p);

        output.push_back(d);
    }

    return output;
}

/**
 * 2d matrix both required.
 */
template <typename T>
std::vector<std::vector<T>> deserialize2dMatrix(std::string& serialised, int c, int r)
{
    replace_if(serialised.begin(), serialised.end(), isRedundant, ' ');

    trim(serialised);
    std::istringstream iss(serialised);
    std::vector<std::vector<T>> input(r, std::vector<T>(c));
    while (iss.rdbuf()->in_avail()) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                iss >> input[i][j];
            }
        }
    }

    return input;
}

template <typename T>
void print(std::vector<std::vector<T>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void print(std::vector<T>& array)
{
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
}
template <typename T>
void print(T t)
{
    std::cout << t << ", ";
}

template <typename T>
T sanitize(std::string& input)
{
    replace_if(input.begin(), input.end(), isRedundant, ' ');
    trim(input);
    std::istringstream iss(input);
    T i;
    iss >> i;
    return i;
}

/**
 * trim a string code.
 **/
static inline void ltrim(std::string& s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(),
        s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s)
{
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s)
{
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s)
{
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s)
{
    trim(s);
    return s;
}
