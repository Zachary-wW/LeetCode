#include <bits/stdc++.h>
using namespace std;


// 由于题目要求时间复杂度为线性 空间复杂度为常量
// 使用异或运算的特殊性质解决
// a ^ a = 0    a ^ 0 = a
class LC136 {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(auto i : nums){
            ans ^= i;
        }

        return ans;
    }
};

// 排序求多数
// hashmap也可以

class LC169 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


// 双指针 也可以使用覆盖的方法
class LC75 {
public:
    void sortColors(vector<int>& nums) {
       int size = nums.size();
       int p0 = 0, p2 = size - 1;

       for(int i = 0; i <= p2; ++i){
           while(i <= p2 && nums[i] == 2){
               swap(nums[i], nums[p2]);
               --p2;
           }
           if(nums[i] == 0){
               swap(nums[i], nums[p0]);
               ++p0;
           }
       } 
    }
};

// 这道题有点绕 首先要从右向左找到一个紧邻的pair 且前者i小于后者i+1
// 之后从右向左寻找i 到末尾之间的第一个大于i的数 之后交换
// 交换后将i + 1到末尾的元素倒置

class LC31 {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;

        while(i >= 0 && nums[i] >= nums[i + 1]){
            --i;
        }

        if(i >= 0){
            int j = nums.size() - 1;
            while(j > i && nums[i] >= nums[j]){
                --j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};