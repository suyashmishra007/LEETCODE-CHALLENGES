class Solution {
private:
    int conversion(vector<int> tops, vector<int> bottoms , int value) {
        int topConversion = 0 , bottomConversion = 0 ;

        for (int i = 0; i < tops.size() ; i++) {
            if (tops[i] != value and bottoms[i] != value) return -1;
            else if (tops[i] != value and bottoms[i] == value)  topConversion++;
            else if (bottoms[i] != value and tops[i] == value)   bottomConversion++;
        }

        return min(topConversion, bottomConversion);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int ans1 = conversion(tops, bottoms, tops[0]);
        int ans2 = conversion(tops, bottoms, bottoms[0]);

        if (ans1 > 0 and ans2 > 0) return min(ans1, ans2);
        else if (ans1 > 0) return ans1;
        else return ans2;
    }
};