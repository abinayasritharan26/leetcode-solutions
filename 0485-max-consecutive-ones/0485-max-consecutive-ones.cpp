class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int i, maxc=0, currc=0;
       for(i=0; i<nums.size(); i++){
           if(nums[i]==1){
               currc=currc+1;
               if(maxc<currc){
                  maxc=currc;
               }
           }
           else{
                currc=0;
           }
       }return maxc; 
    }
};