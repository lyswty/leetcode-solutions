class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        string s=to_string(n);
        int total = 0;
		if (s[0] == '1') total += stoi(s.substr(1)) + 1;
		else total += pow(10, s.size() - 1);
		for (int i = 1; i < s.size(); i++) {
			switch (s[i]) {
			case '0': total += pow(10, s.size() - 1 - i) * stoi(s.substr(0, i)); break;
			case '1': total += pow(10, s.size() - 1 - i) * stoi(s.substr(0, i)); break;
			default: total += pow(10, s.size() - 1 - i) * (stoi(s.substr(0, i)) + 1);
			}
			if (s[i] == '1')
				if (i != s.size() - 1) total += stoi(s.substr(i + 1)) + 1;
				else total += 1;
		}
		return total;
    }
};
