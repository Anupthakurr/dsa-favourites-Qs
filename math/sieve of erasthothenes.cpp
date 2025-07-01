qs link --->  https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/description/

application with some modification


class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int temp1=sqrt(r);
        int cnt=0;
        vector<bool>prime(temp1+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i<=temp1;i++){
            if(i*i<l || i*i>r){
                prime[i]=false;
            }
            if(prime[i]){
                cnt++;
            }
                for(int j=i*i;j<=temp1;j=j+i){
                    prime[j]=0;
                
            }
        }
        return((r-l+1)-cnt);
    }   
};
