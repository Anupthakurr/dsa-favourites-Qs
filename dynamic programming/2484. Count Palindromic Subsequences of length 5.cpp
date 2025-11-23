qs link -------->> https://leetcode.com/problems/count-palindromic-subsequences/description/


class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        // left2[a][b] = number of subsequences of form ab in prefix
        vector<vector<long long>> left2(n, vector<long long>(100, 0));
        // right2[a][b] = number of subsequences of form ab in suffix
        vector<vector<long long>> right2(n, vector<long long>(100, 0));

        // prefix counts of single digits
        vector<long long> freq(10, 0);
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            if (i > 0) left2[i] = left2[i - 1];
            for (int a = 0; a < 10; a++) {
                left2[i][a * 10 + d] += freq[a];
            }
            freq[d]++;
        }

        // suffix counts of single digits
        fill(freq.begin(), freq.end(), 0);
        for (int i = n - 1; i >= 0; i--) {
            int d = s[i] - '0';
            if (i < n - 1) right2[i] = right2[i + 1];
            for (int a = 0; a < 10; a++) {
                right2[i][d * 10 + a] += freq[a];
            }
            freq[d]++;
        }

        // now try each middle character (c)
        long long ans = 0;
        for (int mid = 2; mid <= n - 3; mid++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    long long leftCount = left2[mid - 1][a * 10 + b];
                    long long rightCount = right2[mid + 1][b * 10 + a];
                    ans = (ans + (leftCount % MOD) * (rightCount % MOD)) % MOD;
                }
            }
        }

        return (int)ans;
    }
};
//  dp solution

class Solution {
public:
	int dp[10001][5];
	string digit;
	string s;
	int mod = 1e9+7;
	//Get a palindrome string when first two digit equals to x
	string getDigit(int x){
		string s = to_string(x);
		if(s.size()==1)s = '0'+s; // if x<10 we add a 0 in front of it.
		string t = s;
		s+='.';
		reverse(t.begin(),t.end());
		s+=t;
		return s;
	}
	int call(int pos,int id){
		if(id==5) return 1;
		if(pos==s.size()) return 0;
		if(dp[pos][id]+1) return dp[pos][id];

		long long take = call(pos+1,id);
		//if id==2 we can take any digit.
        long long nottake = 0;
		if(id==2 || s[pos] == digit[id] ) nottake = call(pos+1,id+1)%mod;
        long long ans = (take + nottake) % mod;
		return dp[pos][id] = ans;
	}
	int countPalindromes(string t) {
		s = t;
		long long ans = 0;
		for(int i=0;i<100;i++){
			memset(dp,-1,sizeof dp);
			digit = getDigit(i);
			ans = ans+call(0,0);
			ans = (ans%mod);
		}
		return ans;
	}
};

