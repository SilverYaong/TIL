#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

struct word_list
{
    string word;
    int start_idx;
    int end_idx;
};

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int ans = 0;
    vector<word_list> words;
    set<string> discovered;
    set<string> normal_words;
    int len = message.length();
    
    int start = 0;
    string tmp_str = "";
    for (int i = 0; i <= len; ++i)
    {
        if (i == len || message[i] == ' ')
        {
            if (!tmp_str.empty())
            {
                words.push_back({tmp_str, start, i - 1});
                tmp_str = "";
            }
            start = i + 1;
        }
        else
        {
            tmp_str += message[i];
        }
    }
    
    for (const auto& w: words)
    {
        bool flag = 0;
        for (const auto& range: spoiler_ranges)
        {
            if (w.start_idx <= range[1] && w.end_idx >= range[0])
            {
                flag = 1;
                break;
            }
        }
        if (!flag) normal_words.insert(w.word);
    }
    for (const auto& range: spoiler_ranges)
    {
        for (const auto& w: words)
        {
            if (w.start_idx <= range[1] && w.end_idx >= range[0])
            {
                if (normal_words.find(w.word) != normal_words.end()) continue;
                if (discovered.find(w.word) != discovered.end()) continue;
                
                ans++;
                discovered.insert(w.word);
            }
        }
    }
    return ans;
}