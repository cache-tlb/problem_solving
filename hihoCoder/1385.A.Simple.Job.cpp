#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

int main() {
    // freopen("input.txt", "r", stdin);
    std::string line;
    std::map<std::string,int> word2id;
    std::vector<std::string> word_list;
    std::map<std::pair<int,int>,int> freq;
    while (getline(std::cin, line)) {
        if (line == "####") {
            int max_count = 0;
            for (auto it = freq.begin(); it != freq.end(); it++) {
                max_count = std::max(max_count, it->second);
            }
            std::string res;
            for (auto it = freq.begin(); it != freq.end(); it++) {
                if (max_count != it->second) continue;
                auto item = it->first;
                std::string tmp = word_list[item.first] + " " + word_list[item.second];
                if (res.empty() || tmp < res) res = tmp;
            }
            std::cout << res << ":" << max_count << std::endl;
            word2id.clear();
            freq.clear();
            word_list.clear();
        } else {
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ',') line[i] = '.';
            }
            std::istringstream iss(line);
            std::string token;
            while (getline(iss, token, '.')) {
                std::vector<std::string> words;
                std::string word;
                std::istringstream iss2(token);
                while (iss2 >> word) {words.push_back(word);}
                for (int i = 0; i < words.size(); i++) {
                    if (word2id.count(words[i]) == 0) {
                        word2id[words[i]] = word_list.size();
                        word_list.push_back(words[i]);
                    }
                    if (i > 0) {
                        freq[std::make_pair<>(word2id[words[i-1]], word2id[words[i]])]++;
                    }
                }
            }
        }
    }
    return 0;
}