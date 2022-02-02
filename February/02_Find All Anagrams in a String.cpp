class Solution {
	unordered_map<char , int > Smap , Pmap;
public:
	bool compareFreq() {
		// Smap, Pmap
		for (auto ch_freq_Pmap : Pmap) {
			int freq = ch_freq_Pmap.second ;
			char ch = ch_freq_Pmap.first ;

			if (Smap[ch] != freq) {
				return false;
			}
		}

		return true;
	}
	vector<int> findAnagrams(string s, string p) {

		int sLen = s.length() , pLen  = p.length() ;
		for (auto ch : p)
		{
			Pmap[ch]++;
		}

		for (int i = 0; i < pLen ; i++) {
			Smap[s[i]]++;
		}

		int right = pLen , left = 0 ;
		vector<int> indexs ;
		while (right < sLen ) {

			left = right - pLen;

			if (compareFreq() == true) {
				indexs.emplace_back(left);
			}

			// take the char on the right index
			char chR = s[right];
			Smap[chR]++;

			// release the char on the left index
			char chL = s[left];
			if (Smap[chL] == 1) {
				Smap.erase(chL);
			} else {
				Smap[chL]--;
			}

			right++;
		}

		left = right - pLen;

		if (compareFreq() == true) {
			indexs.emplace_back(left);
		}

		return indexs;
	}
};