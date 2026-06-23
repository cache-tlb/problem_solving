// 2126. Destroying Asteroids
// no trick
class Solution {
public:
	bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
		std::sort(asteroids.begin(), asteroids.end());
		for (const auto & v : asteroids) {
			if (mass >= v) {
				mass += v;
				if (mass >= asteroids.back()) return true;
			}
			else {
				return false;
			}
		}
		return true;
	}
};
