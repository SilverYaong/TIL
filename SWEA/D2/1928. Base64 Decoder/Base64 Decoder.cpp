#include <iostream>
#include <string>
#include <bitset>
#include <map>

using namespace std;

map<char, int> table = {
    {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24}, {'Z', 25}, {'a', 26}, {'b', 27}, {'c', 28}, {'d', 29}, {'e', 30}, {'f', 31}, {'g', 32}, {'h', 33}, {'i', 34}, {'j', 35}, {'k', 36}, {'l', 37}, {'m', 38}, {'n', 39}, {'o', 40}, {'p', 41}, {'q', 42}, {'r', 43}, {'s', 44}, {'t', 45}, {'u', 46}, {'v', 47}, {'w', 48}, {'x', 49}, {'y', 50}, {'z', 51}, {'0', 52}, {'1', 53}, {'2', 54}, {'3', 55}, {'4', 56}, {'5', 57}, {'6', 58}, {'7', 59}, {'8', 60}, {'9', 61}, {'+', 62}, {'/', 63}};

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s, ans;
        int bit;
        string buffer;
        string to8bit;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            bit = table[s[j]];
            buffer.append(bitset<6>(bit).to_string());
            if (buffer.size() >= 24)
            {
                for (int k = 0; k < 3; k++)
                {
                    string tmp;
                    to8bit = buffer.substr(k * 8, 8);
                    ans += bitset<8>(to8bit).to_ulong();
                }
                buffer.clear();
            }
        }
        cout << "#" << i + 1 << " " << ans << endl;
    }
}