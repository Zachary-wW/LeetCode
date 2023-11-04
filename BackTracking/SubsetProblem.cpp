#include <bits/stdc++.h>

using namespace std;

// 子集问题需要遍历整个树 

class LC78 {
public:

    void backTracking(vector<int>& nums, int index){// 无序所以不能重复 加入index
        
        ans.emplace_back(path); // 把每一个节点都加入到ans中
        
        if(index >= nums.size()){// 当数组中为空的时候返回
            return;
        }

        // 遍历数中的每一个节点
        for(int i = index; i < nums.size(); ++i){
            path.emplace_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backTracking(nums, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> path;
};

//

class Solution {
public:

    void backTracking(vector<int>& nums, int index, vector<bool>& flag){
        
        ans.emplace_back(path);

        for(int i = index; i < nums.size(); ++i){

            if(i > 0 && nums[i] == nums[i - 1] && flag[i - 1] == false){
                continue; // 去重 同一层不能出现相同的 e.g. 122 第一层1 往下 2 & 2 如果2为false说明已经回溯出来了再取2就重复了 
            }

            path.emplace_back(nums[i]);
            flag[i] = true;
            backTracking(nums, i + 1, flag);
            path.pop_back();
            flag[i] = false; // 出来记得置为false
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> flag(nums.size(), false);
        sort(nums.begin(), nums.end()); // 去重前排序
        backTracking(nums, 0, flag);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> path;
};