#include <bits/stdc++.h>
using namespace std;

class LC46 {
public:

    void backTracking(vector<int>& nums, vector<bool>& flag){
        // 终止条件
        if(path.size() == nums.size()){ // 长度一样说明找完了
            ans.emplace_back(path); 
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            // 判断是否使用过
            if(flag[i] == true){
                continue;
            }
            // 处理节点
            flag[i] = true;
            path.emplace_back(nums[i]);
            backTracking(nums, flag);
            path.pop_back();
            flag[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size(), false);
        backTracking(nums, flag);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> path;
};

class Solution {
public:

    void backTracking(vector<int>& nums, vector<bool>& flag){
        // 终止
        if(path.size() == nums.size()){
            ans.emplace_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            // 去重
            if(i > 0 && nums[i - 1] == nums[i] && flag[i - 1] == false){
                continue;
            }
            // 对节点进行处理
            if(flag[i] == false){ // true说明已经选取了
                path.emplace_back(nums[i]);
                flag[i] = true;
                backTracking(nums, flag);
                path.pop_back();
                flag[i] = false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> flag(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTracking(nums, flag);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> path;
};