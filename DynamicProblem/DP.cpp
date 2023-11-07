#include <bits/stdc++.h>
using namespace std;


// 使用dp(n + 1)堆内存会溢出
class LC509 {
public:
    int fib(int n) {
        if(n < 2) return n; // 注意这里 判断初始情况
        vector<int> dp(2);// dp数组含义就是值
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

class LC70 {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2;// 注意在爬楼梯这道题中 dp[0]没有意义
        for(int i = 3; i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        if(cost.size() < 2) return 0;

        vector<int> dp(cost.size() + 1);// dp数组的含义就是爬到每一层消耗的最少值
        dp[0] = 0, dp[1] = 0; // 初始化 从一步或者0步开始

        for(int i = 2; i <= cost.size(); ++i){
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[cost.size()];
    }
};

//
