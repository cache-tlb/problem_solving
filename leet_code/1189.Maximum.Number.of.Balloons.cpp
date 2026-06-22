// 1189. Maximum Number of Balloons
// no magic

class Solution {
public:
	int maxNumberOfBalloons(string text) {
		// balloon
		int a = 0, b = 0, l = 0, o = 0, n = 0;
		for (const auto &c : text) {
			switch(c){
			case 'a': a++; break;
			case 'b': b++; break;
			case 'l': l++; break;
			case 'o': o++; break;
			case 'n': n++; break;
			default: break;
			}
		}
		int ret = a;
		ret = std::min(ret, b);
		ret = std::min(ret, l / 2);
		ret = std::min(ret, o / 2);
		ret = std::min(ret, n);
		return ret;
	}
};
