class Solution {
public:
	string removeKdigits(string num, int k) {

		stack<char> stk ;
		for (auto &ch : num) {
			// if k > 0 and ch < st.top() => pop
			while (!stk.empty() and k > 0 and ch < stk.top()) {
				stk.pop();
				k--;
			}
			// if ch != 0 => push(ch)
			if (!stk.empty() or ch != '0') {
				stk.push(ch);
			}
		}

		while (!stk.empty() and k-- > 0 ) {
			stk.pop();
		}

		if (stk.empty()) {
			return "0";
		}

		string ans = "";
		while (!stk.empty()) {
			ans += stk.top();
			stk.pop();
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};