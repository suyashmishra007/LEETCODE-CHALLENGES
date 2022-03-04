class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int row = query_row , col = query_glass;

        vector<vector<double>> quantity(101, std::vector<double>(101, 0));
        quantity[0][0] = poured;

        for (int i = 0 ; i  < row ; i++) {
            for (int j = 0 ; j <= col ; j++) {
                double remaining = max(quantity[i][j] - 1.0 ,  (double)0);
                quantity[i + 1][j] += remaining / 2.0;
                quantity[i + 1][j + 1] += remaining / 2.0;
            } 
        }

        return min(quantity[row][col] , 1.0);
    }
};