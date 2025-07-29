qs link ----->   https://leetcode.com/problems/count-mentions-per-user/


class Solution {
public:
    static bool cmp(const vector<string> &a,const vector<string>&b){
        int val1 = stoi(a[1]);
        int val2 = stoi(b[1]);
        if(val1!=val2) return val1<val2;
        else if(a[0]=="OFFLINE" && b[0]!="OFFLINE") return true;
        else return false;
    }

    vector<int> countMentions(int nu, vector<vector<string>>& events) {
        int n = events.size();
        vector<int> ans(nu);
        vector<int> v(nu,-1);
        sort(events.begin(),events.end(),cmp);
        long long currt;
        for(auto j: events){
            int currt = stoi(j[1]);
            for(int i = 0;i<=nu-1;i++){
                if(v[i]!=-1){
                    if(v[i]+60<=currt){
                        v[i] = -1;
                    }
                }
            }
            if(j[0]=="MESSAGE"){
                if(j[2]=="ALL")
                {
                    for(int i = 0;i<=nu-1;i++) ans[i]++;
                }
                else if(j[2]=="HERE"){
                    for(int i= 0;i<=nu-1;i++) if(v[i]==-1) ans[i]++;
                }
                else {
                    string ss = "";
                    for(auto k: j[2]){
                        if(k==' '){
                            ss.erase(ss.begin());
                            ss.erase(ss.begin());
                            int val = stoi(ss);
                            ans[val]++;
                            ss = "";
                        }
                        else{
                            ss.push_back(k);
                        }
                    }

                    ss.erase(ss.begin());
                    ss.erase(ss.begin());
                    int val = stoi(ss);
                    ans[val]++; 
                }
            }
            else{
                int id = stoi(j[2]);
                v[id] = stoi(j[1]);
            }
        }

        return ans;
        
        
    }
};
