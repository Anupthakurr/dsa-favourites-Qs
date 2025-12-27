qs link ------>> https://leetcode.com/problems/corporate-flight-bookings/description/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int N=bookings.size();
        vector<int>diff(n+1,0);
        for(auto &vec:bookings){
            int l=vec[0];
            int r=vec[1];
            int seats=vec[2];

            diff[l-1]+=seats;
            diff[r]-=seats;
        }
        vector<int>ans(n);
        ans[0]=diff[0];
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+diff[i];
        }
        return ans;
    }
};
