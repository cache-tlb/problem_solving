// notes: med, no trick

class Solution {
public:
	double angleClock(int hour, int minutes) {
		hour = hour % 12;
		minutes = minutes % 60;
		double angle1 = hour*30.0 + minutes*0.5;
		double angle2 = minutes*6.0;
		double d = abs(angle1 - angle2);
		return std::min(d, 360.0 - d);
	}
};