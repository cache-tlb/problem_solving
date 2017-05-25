class Solution {
public:
    string minWindow(string s, string t) {
        bool is_t[256] = {};
        int count[256] = {};
        int target[256] = {};
        std::map<int,int> todo_list;
        for (int i = 0; i < t.length(); i++) {
            is_t[t[i]] = true;
            todo_list[t[i]]++;
            target[t[i]]++;
        }
        std::vector<int> check_list;
        for (int i = 0; i < 256; i++) {
            if (is_t[i]) {
                check_list.push_back(i);
            }
        }

        int head = 0;
        while (head < s.length() && !is_t[s[head]]) head++;
        if (head == s.length()) return "";
        int tail = head;
        for (; tail < s.length(); tail++) {
            count[s[tail]]++;
            if (todo_list.count(s[tail])) {
                todo_list[s[tail]]--;
                if (todo_list[s[tail]]==0) todo_list.erase(s[tail]);
            }
            if (todo_list.empty()) break;
        }
        if (!todo_list.empty()) return "";
        while (head < tail) {
            if (is_t[s[head]] && count[s[head]] == target[s[head]]) break;
            count[s[head]]--;
            head++;
        }
        string best_str = string(s, head, tail-head+1);
        int best_len = tail-head+1;
        while (tail < s.length()) {
            tail++;
            while (tail < s.length()) {
                count[s[tail]]++;
                if (s[tail] == s[head]) break;
                tail++;
            }
            if (tail == s.length()) break;
            while (head < tail) {
                if (is_t[s[head]] && count[s[head]] == target[s[head]]) break;
                count[s[head]]--;
                head++;
            }
            string cur_str = string(s, head, tail-head+1);
            if (cur_str.length() < best_len) {
                best_len = cur_str.length();
                best_str = cur_str;
            }
        }
        return best_str;
    }
};

// 1. find the first appeared substring that contain t
// 2. maintain 2 pointers head/tail, initially points to the head/tail of the substring in step 1
// the str between the two pointers always contain t
// 3. move the tail pointer until tail is the same as head, then we can move head
// 4. keep move head and stop when the count of any char will otherwise be less than desaired.
// here we find another substring that contain t
// back to step 3 until reach the end of string