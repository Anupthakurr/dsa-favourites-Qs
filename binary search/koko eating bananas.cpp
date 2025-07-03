qs link -----> https://leetcode.com/problems/koko-eating-bananas/

binary search on answer    


class Solution {
    bool check(int mid,vector<int>& piles, int h){
         long long sum = 0;
         for(int j = 0;j<piles.size();j++){
                sum += ceil((double)piles[j]/mid);
            }
        if(sum <= h){
           return true;
        }
        else{
            return false;
        }
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int end = *max_element(piles.begin(), piles.end());;
       int start = 1;
       int ans ;
       while(start<=end){
        int mid = (start + end)/2;
           if(check(mid,piles,h)){
            end = mid -1;
            ans = mid;
           } 
           else{
            start = mid+1;
           }
       }
       return ans;
    }
};
