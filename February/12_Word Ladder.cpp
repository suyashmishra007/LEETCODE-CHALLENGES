class Solution {
public:
	int ladderLength(string st, string ed, vector<string>& wordList) {

		unordered_set<string> us ;
		bool isEndWordPresent = false;
		for (auto word : wordList) {
			if (word == ed) {
				isEndWordPresent = 1 ;
			}
			us.insert(word);
		}
		if (!isEndWordPresent) {
			return 0 ;
		}
		queue<string> que ;
		que.push(st);
		int depth = 0 ;


		while (!que.empty()) {

			int size = que.size();
			depth++;

			while (size--) {


				string curr = que.front();
				que.pop();

				for (int i = 0 ; i < curr.length() ; i++) {

					string temp = curr ;

					
					for (char ch = 'a' ; ch <= 'z' ; ch++) {
						temp[i] = ch ;
						if (temp == curr) {
							continue ;
						}
						if (temp == ed) {
							return depth + 1 ;
						}
						if (us.find(temp) != us.end()) {
							que.push(temp);
							// erase element,1 element will be used only once.
							us.erase(temp);
						}
					}


				}
			}
		}
		return 0;
	}
};