class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string temp ;
        stack<string> stk;

        while (getline(ss, temp, '/')) {
            if (temp.size() == 0 or temp == ".") {
                continue;
            } else if (temp == "..") {
                if (stk.size() != 0) {
                    stk.pop();
                }
            } else {
                stk.push(temp);
            }
        }

        string ans = "";
        while (!stk.empty()) {
            ans = stk.top() + "/" + ans ;
            stk.pop();
        }

        if (ans.size() == 0) return "/";

        return "/" + string(&ans[0], &ans[ans.size() - 1]);
    }
};