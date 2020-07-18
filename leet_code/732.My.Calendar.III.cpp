class MyCalendarThree {
public:
	MyCalendarThree() {

	}

	struct Segment {
		Segment(int a, int b) : start(a), end(b) {}
		int start, end;
	};
	struct Event {
		Event(int type, int time, int index) : type(type), time(time), index(index) {}
		int type, time, index;
		bool operator < (const Event &b) const {
			return (time < b.time) || (time == b.time && type > b.type) || (time == b.time && type == b.type && index < b.index);
		}
	};
	std::vector<Segment> segments;
	std::map<Event,int> events;

	int Compute() {
		int max_count = 0, current_count = 0;
		for (std::map<Event, int>::iterator it = events.begin(); it != events.end(); it++) {
			if (it->first.type == 0) current_count++;
			else current_count--;
			max_count = std::max(max_count, current_count);
		}

		return max_count;
	}

	int book(int start, int end) {
		events[Event(0, start, segments.size())] = 1;
		events[Event(1, end, segments.size())] = 1;
		segments.push_back(Segment(start, end));
		return Compute();
	}
};
