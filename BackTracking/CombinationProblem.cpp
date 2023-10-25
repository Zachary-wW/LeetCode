#include <bits/stdc++.h>
using namespace std;

// 组合问题1 LeetCode 77
// Solution
class Solution {
public:
    void backtracking(int n, int k, int startInedx){
        if(k == vec.size()){
            ans.emplace_back(vec);
            return;
        }

        // for(int i = startInedx; i <= n; ++i){
        //     vec.emplace_back(i);
        //     backtracking(n, k, i+1);
        //     vec.pop_back();
        // }

        // 当前组合个数vec.size() 总共k 如果剩下的元素数量小于要求的个数就没必要遍历了
        // n - i >= k - vec.size() 则 i <= n - k + vec.size() + 1
        for(int i = startInedx; i <= n - k + vec.size() + 1; ++i){
            vec.emplace_back(i);
            backtracking(n, k, i+1);
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> vec;
};

// 时间复杂度: O(n * 2^n)  空间复杂度: O(n)