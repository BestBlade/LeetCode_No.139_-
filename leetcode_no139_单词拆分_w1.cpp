/* ------------------------------------------------------------------|
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	dp
*
*	执行用时：20 ms, 在所有 C++ 提交中击败了63.37%的用户
*	内存消耗：12.9 MB, 在所有 C++ 提交中击败了60.32%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

bool wordBreak(string s, vector<string>& wordDict) {
    //学会使用set来节省空间
    set<string> set;
    for (string& str : wordDict) {
        set.insert(str);
    }
    //unordered_map<string, int> map;
    //for (string& str : wordDict) {
    //    map[str]++;
    //}
    vector<bool> dp(s.size() + 1);
    dp[0] = 1;
    //i循环为截至坐标
    for (int i = 1; i <= s.size(); i++) {
        //j循环为开始点坐标
        for (int j = 0; j < i; j++) {
            if (dp[j] && set.find(s.substr(j,i-j)) != set.end()) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[s.size()];
}