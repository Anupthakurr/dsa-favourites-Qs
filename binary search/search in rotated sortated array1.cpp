class Solution {
public:
int findpivot(vector<int>&nums,int n){
    int s = 0, e = n-1;
    while(s<e){
        int mid = s + (e-s)/2;
        if(nums[mid]>nums[n-1]){
            s = mid +1;
        }else{
            e = mid;
        }
    }
    return e;
}
int binarysearch(int s,int e,vector<int>&nums,int target){
    int ind = -1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(nums[mid]==target){
            ind = mid;
            break;
        }else if(nums[mid]<target){
            s = mid + 1;
    }else{
        e = mid -1;
    }
    }
    return ind;
}
    int search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot_index = findpivot(nums,n);
    int ind = binarysearch(0,pivot_index-1,nums,target);
    if(ind != -1)
    return ind;
    ind = binarysearch(pivot_index,n-1,nums,target);
    return ind;
    }    
};
