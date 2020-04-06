class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> s;
        for(int i = 0; i < strs.size(); ++i) {
            s.emplace_back(strs[i], i);
            sort(s[i].first.begin(), s[i].first.end());
        }
        sort(s.begin(), s.end());
        vector<vector<string>> res;
        for(int i = 0; i < strs.size(); ++i) {
            res.emplace_back();
            string chk = s[i].first;
            while(i < s.size()) {
                string curr = s[i].first;
                if(curr == chk) {
                    res[res.size() - 1].push_back(strs[s[i].second]);
                    i++;
                } else {
                    i--;
                    break;
                }
            }
        }
        return res;
    }
};
