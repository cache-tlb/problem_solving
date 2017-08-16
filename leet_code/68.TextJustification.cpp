class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::vector<std::string> > line_words(1);
        int cur_width = 0;
        for (int i = 0; i < words.size();) {
            std::vector<std::string> &cur_line = line_words.back();
            if (cur_line.size() == 0 || cur_width + 1 + words[i].length() <= maxWidth) {
                cur_line.push_back(words[i]);
                cur_width += words[i].length();
                if (cur_line.size() > 1) cur_width++;
                i++;
            } else {
                line_words.resize(line_words.size() + 1);
                cur_width = 0;
            }
        }
        std::vector<std::string> ret;
        for (int i = 0; i < line_words.size(); i++) {
            int num_space = maxWidth;
            for (int j = 0; j < line_words[i].size(); j++) {
                num_space -= line_words[i][j].length();
            }
            std::string line;
            if (i + 1 == line_words.size()) {
                for (int j = 0; j < line_words[i].size(); j++) {
                    line = line + line_words[i][j];
                    line.push_back(' ');
                }
                line.pop_back();
                while (line.length() < maxWidth) {
                    line.push_back(' ');
                }
            } else if (line_words[i].size() == 1) {
                line = line_words[i][0];
                while (line.length() < maxWidth) {
                    line.push_back(' ');
                }
            } else {
                int pad_len = num_space / (line_words[i].size() - 1);
                std::string space_str(pad_len, ' ');
                int extra_slot = num_space - (line_words[i].size() - 1)*pad_len;
                for (int j = 0; j < line_words[i].size(); j++) {
                    line = line + line_words[i][j];
                    if (j + 1 < line_words[i].size()) line = line + space_str;
                    if (j < extra_slot) line.push_back(' ');
                }
            }
            ret.push_back(line);
        }
        return ret;
    }
};