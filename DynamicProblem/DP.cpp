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
class LC62 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));// dp数组的含义就是走到第[i][j]个方格的路径数
        
        for(int i = 0; i < m; ++i){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; ++j){
            dp[0][j] = 1;
        }// 初始化dp数组 由于在边界处只有一种方法可以走
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; //向右或者向下
            }
        }
        return dp[m][n];

    }
};

class LC63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));// 注意需要将dp初始化为0 如果有障碍物就不能更新到dp

        for(int i = 0; i < m && obstacleGrid[i][0] == 0; ++i){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; ++j){
            dp[0][j] = 1;
        }// 初始化数组 如果按序遍历的过程中遇到障碍物 后面都不用赋值了 说明到达不了

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 0){// 没有障碍物时才赋值
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
