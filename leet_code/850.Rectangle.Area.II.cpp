class Solution {
public:
	struct Event {
		Event(int index, int type, int y) : index(index), type(type), y(y) {}
		int index;
		int type;       // 0 : add to line, 1: remove
		int y;
	};
	struct Segment {
		Segment(int a, int b) : start(a), end(b) {}
		int start, end;
	};

	struct Rect {
		Rect(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1), status(0) {}
		int x0, x1, y0, y1;
		int status; // 0 : not in sweep line; 1 : in sweep line
	};

	std::vector<Rect> rects;
	std::vector<Event> events;

	int ComputeSweep() {
		std::vector<Segment> segments;;
		for (int i = 0; i < rects.size(); i++) {
			if (rects[i].status == 1) {
				segments.push_back(Segment(rects[i].x0, rects[i].x1));
			}
		}
		std::sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) {
			return (a.start < b.start) || (a.start == b.start && a.end < b.end);
		});

		for (int i = 0; i + 1 < segments.size(); i++) {
			if (segments[i + 1].start < segments[i].end) {
				segments[i + 1].start = segments[i].end;
			}
			if (segments[i + 1].end < segments[i].end) {
				segments[i + 1].end = segments[i].end;
			}
		}
		int s = 0;
		for (int i = 0; i < segments.size(); i++) {
			s += (segments[i].end - segments[i].start);
		}
		return s;
	}

	int rectangleArea(vector<vector<int> >& rectangles) {
		if (rectangles.empty()) return 0;
		for (int i = 0; i < rectangles.size(); i++) {
			rects.push_back(Rect(rectangles[i][0], rectangles[i][1], rectangles[i][2], rectangles[i][3]));
			events.push_back(Event(i, 0, rectangles[i][1]));
			events.push_back(Event(i, 1, rectangles[i][3]));
		}
		std::sort(events.begin(), events.end(), [](const Event &a, const Event &b) {
			return (a.y < b.y) || (a.y == b.y && a.type < b.type) || (a.y == b.y && a.type == b.type && a.index < b.index);
		});

		int sweep_line = -1;
		int event_idx = 0;
		int s = 0;
		while (event_idx < events.size()) {
			int current_y = events[event_idx].y;
			std::vector<int> rm_idx;
			std::vector<int> add_idx;
			while (event_idx < events.size() && events[event_idx].y == current_y) {
				int rect_idx = events[event_idx].index;
				if (events[event_idx].type == 0) add_idx.push_back(rect_idx);
				else rm_idx.push_back(rect_idx);
				event_idx++;
			}
			long long dy = current_y - sweep_line;
			long long dx = ComputeSweep();
			long long mod = (1000000000 + 7);
			long long ss = (dx*dy + s) % mod;
			s = int(ss);
			sweep_line = current_y;
			for (int k = 0; k < rm_idx.size(); k++)
				rects[rm_idx[k]].status = 0;
			for (int k = 0; k < add_idx.size(); k++)
				rects[add_idx[k]].status = 1;
		}
		return s;
	}
};
