#include<bits/stdc++.h>
using namespace std; 

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if(m==0||n==0) return 0;
    int dp[m][n];
        memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
    {   if(obstacleGrid[i][0]!=1) dp[i][0]=1;
        else break;
    }
    for(int j=0;j<n;j++)
    {   if(obstacleGrid[0][j]!=1) dp[0][j]=1;
        else break;
    }
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            if(obstacleGrid[i][j]!=1)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
    return dp[m-1][n-1];
}

    
int main(){
   int m,n; 
   cin>>m>>n; 

   vector<vector<int>> obstacleGrid(m, vector<int>(n)); 
   for(int i=0; i<m; i++){
     for(int j=0; j<n; j++){
        cin>>obstacleGrid[i][j]; 
     }
   } 

   cout << uniquePathsWithObstacles(obstacleGrid) << endl;  

}
