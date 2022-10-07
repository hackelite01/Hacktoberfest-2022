// Contributed by : RajatRathore123-github
// Date : 7-10-2022

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target .

// This is an optimised approach for this problem in which we use hashmap.
// Timecomplexity : O(n)
// Spacecomplexity : O(n)

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums,int target){
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i = 0; i < nums.size(); i++){
        if(mp.find(target - nums[i]) != mp.end()){
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[nums[i]] = i;     
    }
    return ans;
}