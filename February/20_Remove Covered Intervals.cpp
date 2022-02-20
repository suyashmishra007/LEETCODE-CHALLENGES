class Solution {
private:
    static bool comparator(vector<int> &a , vector<int> &b){
        if(a[0] < b[0])
            return true;
        else if(a[0] > b[0])
            return false;
        else
            return a[1] > b[1];
        
    }    
public:
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
            
        int n = intervals.size();
        if(n == 0) 
            return 0 ;
        
        sort(intervals.begin(),intervals.end(),comparator);
        
        int minIntervalToRemove = 0 ;
        
        vector<int> lastInterval ;
        
        for(auto &timePar : intervals){
            
            if(lastInterval.size() == 0){
                lastInterval = timePar;
            }else{
                
                int currStart = timePar[0] , currEnd = timePar[1];
                int lastStart = lastInterval[0] , lastEnd = lastInterval[1];
                
                if(lastStart <= currStart and currEnd <= lastEnd){
                    minIntervalToRemove++;
                }else{
                      lastInterval = timePar;
                }
            }
        }
        return n - minIntervalToRemove;
    }
};