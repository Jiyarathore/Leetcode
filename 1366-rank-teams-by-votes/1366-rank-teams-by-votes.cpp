class Solution {
public:
     string rankTeams(vector<string>& votes) {
    	int n = votes.size(), m = votes[0].size();
    	string ans = "";
    	vector<vector<int>> v(26, vector<int>(m + 1, 0));
    	for (auto i = 0; i < 26; i++) {
    		v[i][m] = -(int('A') + i);
    	}
    	for (auto i = 0; i < n; i++) {
    		for (auto j = 0; j < m; j++) {
    			v[votes[i][j] - 'A'][j]++;
    		}
    	}
    	sort(v.begin(),v.end(),greater<>());
    	for (auto i = 0; i < m; i++) {
    		ans += char(-v[i][m]);
    	}
    	return ans;
    }
};