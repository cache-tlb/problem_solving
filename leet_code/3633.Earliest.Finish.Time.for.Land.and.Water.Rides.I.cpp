// 3633. Earliest Finish Time for Land and Water Rides I
// same to 3635

class Solution {
public:
	int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
		int idx = 0;
		int min_t1 = landStartTime[0] + landDuration[0];
		// first land then water
		for (int i = 0; i < landDuration.size(); i++) {
			min_t1 = std::min(min_t1, landStartTime[i] + landDuration[i]);
		}
		int min_t2 = std::max(min_t1, waterStartTime[0]) + waterDuration[0];
		for (int i = 0; i < waterDuration.size(); i++) {
			min_t2 = std::min(min_t2, std::max(min_t1, waterStartTime[i]) + waterDuration[i]);
		}

		// first water then land
		int min_t3 = waterStartTime[0] + waterDuration[0];
		for (int i = 0; i < waterDuration.size(); i++) {
			min_t3 = std::min(min_t3, waterStartTime[i] + waterDuration[i]);
		}
		int min_t4 = std::max(min_t3, landStartTime[0]) + landDuration[0];
		for (int i = 0; i < landDuration.size(); i++) {
			min_t4 = std::min(min_t4, std::max(min_t3, landStartTime[i]) + landDuration[i]);
		}
		return std::min(min_t2, min_t4);
	}
};