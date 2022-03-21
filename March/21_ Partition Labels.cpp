class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int n = s.size();

        unordered_map<char, int> lastIndex ;
        for (int i = 0 ; i < n ; i++) {
            lastIndex[s[i]] = i ;
        }

        vector<int> ans ;

        int prev = -1 , maxIndex = 0 ;

        for (int i = 0 ; i < n ; i++) {
            auto currentChar = s[i];
            maxIndex = max(maxIndex, lastIndex[currentChar]);

            if (maxIndex == i) {
                int partition = i - prev;
                ans.push_back(partition);
                prev = i ;
            }
        }

        return ans ;
    }
};s