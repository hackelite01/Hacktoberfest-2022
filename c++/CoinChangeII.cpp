#include<bits/stdc++.h>
using namespace std; 

 int no_of_ways_amount_to_zeroTopDown(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp){
         
      if(amount == 0) return 1;
      if(idx < 0) return 0;

      int ans = 0; 

      if(dp[idx][amount] != -1) return dp[idx][amount]; 

      for(int coin_amount = 0; coin_amount <= amount; coin_amount += coins[idx]){
          ans += no_of_ways_amount_to_zeroTopDown(coins, amount-coin_amount, idx-1, dp); 
      }

      return dp[idx][amount] = ans; 
  }

int change(int amount, vector<int>& coins) {

      int n = coins.size(); 
      vector<vector<int>> dp(n, vector<int>(amount+1, -1)); 
      return no_of_ways_amount_to_zeroTopDown(coins, amount, n-1, dp); 
  
 }

int main(){
  
  int n; 
  cin>>n;
  
  vector<int>coins(n); 
  for(int& x : coins) cin>>x; 
  
  int amount; 
  cin>> amount;
  
  cout << change(amount, coins) << endl;
  
  return 0; 
 
}
