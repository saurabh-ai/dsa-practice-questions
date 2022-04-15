/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/

https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock.cpp

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different 
day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

6
7 1 5 4 6 4
Input: prices = [7,1,5,3,6,4] 
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

mi = 7, 1,  ,  ,  ,  
mp =  ,  , 4, 2, 5, 3

Ar = 7, 1, 5, 3, 6, 4

*/

#include <bits/stdc++.h>

using namespace std;

    int maxProfit(vector<int>& prices) {
        int valley = INT_MAX;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < valley){
                valley = prices[i];
            }else if(prices[i] - valley > ans){
                ans = prices[i] - valley;
            }
        }
        return ans;
    }

int main(){
    int n, input;
    cin>>n;
    
    vector<int> vect;

    for(int i=0;i<n;i++){
        cin>>input; 
        vect.push_back(input);
    }

    cout<< maxProfit(vect);

    return 0;
}