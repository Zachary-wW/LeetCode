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

// 原数组不能使用排序后设置flag数组去重下 如何去重

class Solution {
public:

    void backTracking(vector<int>& nums, int index){
        //终止条件 子集问题需要将每个符合条件的节点都加入
        if(path.size() > 1){
            ans.emplace_back(path);
            //不用return
        }
        unordered_set<int> uset;
        for(int i = index; i < nums.size(); ++i){
            // 处理节点 不符合递增 & 本层重复元素 跳过
            if((!path.empty() && path.back() > nums[i]) || 
                (uset.find(nums[i]) != uset.end())){
                    continue;
                }// 第一部分条件 首先要保证递增 那就是path.back() <= nums[i] 不满足就跳过 但是别忘记要确保path.back不为空吧
            //
            uset.insert(nums[i]); // 不用erase 递归到下一层uset就清空了
            path.emplace_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTracking(nums, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> path;
};