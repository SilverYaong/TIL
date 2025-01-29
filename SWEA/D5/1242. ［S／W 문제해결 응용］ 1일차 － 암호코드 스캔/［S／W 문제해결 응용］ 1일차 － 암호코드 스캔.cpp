#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>
#include <set>

using namespace std;

void string_extraction(string, int, int &, set<string> &);
bool check_code(string, int, int &, set<string> &);
string convert_code(string, int &);
string ratio_to_number(string);
string hex_to_binary(string);

map<string, string> passcode_convert{
    {"3211", "0"},
    {"2221", "1"},
    {"2122", "2"},
    {"1411", "3"},
    {"1132", "4"},
    {"1231", "5"},
    {"1114", "6"},
    {"1312", "7"},
    {"1213", "8"},
    {"3112", "9"},
};

int ans;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, n, m;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ans = 0;
        cin >> n >> m;
        string code;
        string previous_code;
        set<string> checked_number;

        for (int j = 0; j < n; j++)
        {
            int loop = 1;
            cin >> code;

            if (previous_code == code)
            {
                continue;
            }
            previous_code = code;
            string_extraction(code, m, loop, checked_number);
        }

        cout << "#" << i + 1 << " " << ans << endl;
    }
}

void string_extraction(string code, int m, int &loop, set<string> &checked_number)
{
    string tmp_code = hex_to_binary(code);
    // cout << "현재 탐색 문자열 : " << tmp_code << endl;

    for (int k = tmp_code.size() - 1; k >= 0; k--)
    {
        if (tmp_code[k] == '1')
        {
            string loop_code = tmp_code.substr(k - 56 * loop + 1, 56 * loop);
            bool _ = check_code(loop_code, m, loop, checked_number);
            if (!_)
            {
                // cout << "loop를 증가시킴" << endl;
                k++;
                loop++;
            }
            else
            {
                // cout << "계속 탐색" << endl;
                k = k - 56 * loop + 1;
                loop = 1;
                // cout << "다음 탐색 문자열 : " << tmp_code.substr(0, k) << endl;
            }
        }
    }
}

bool check_code(string code, int m, int &loop, set<string> &checked_number)
{
    string _;
    int odd = 0;
    int even = 0;
    _ = convert_code(code, loop);
    if (_ == "wrong")
    {
        return false;
    }
    if (checked_number.find(_) == checked_number.end())
    {
        checked_number.insert(_);
    }
    else
    {
        return true;
    }

    odd = _[0] + _[2] + _[4] + _[6] - '0' * 4;
    even = _[1] + _[3] + _[5] + _[7] - '0' * 4;

    if (((odd * 3) + even) % 10 == 0)
    {
        ans += odd + even;
        return true;
    }
    else
    {
        return true;
    }
}

string convert_code(string binary, int &loop)
{
    string tmp;
    string converted_code;
    for (int i = 0; i < 8; i++)
    {
        string ratio;
        int zero_count = 0;
        int one_count = 0;
        tmp = binary.substr(i * 7 * loop, 7 * loop);
        // cout << "convert target : " << tmp << endl;
        // cout << "몇배수인지 : " << loop << endl;
        for (int j = 0; j < loop * 7; j++)
        {
            if (tmp[j] == '0')
            {
                if (one_count)
                {
                    // cout << "1의 개수 : " << one_count << endl;
                    // cout << "1의 비율 : " << one_count / loop << endl;
                    ratio.append(to_string(one_count / loop));
                    one_count = 0;
                }
                zero_count++;
            }
            else
            {
                if (zero_count)
                {
                    // cout << "0의 개수 : " << zero_count << endl;
                    // cout << "0의 비율 : " << zero_count / loop << endl;
                    ratio.append(to_string(zero_count / loop));
                    zero_count = 0;
                }
                one_count++;
            }
        }
        // cout << "1의 개수 : " << one_count << endl;
        // cout << "1의 비율 : " << one_count / loop << endl;
        ratio.append(to_string(one_count / loop));
        // cout << "최종 비율 : " << ratio << endl;
        one_count = 0;
        string _ = ratio_to_number(ratio);
        if (_ == "wrong")
        {
            // cout << "잘못된 코드이므로 loop를 증가시킴" << endl;
            return "wrong";
        }
        else
        {
            converted_code.append(_);
        }
    }
    return converted_code;
}

string ratio_to_number(string ratio)
{
    string _;
    if (passcode_convert.find(ratio) == passcode_convert.end())
    {
        return "wrong";
    }
    else
    {
        _ = passcode_convert[ratio];
        return _;
    }
}

string hex_to_binary(string code)
{
    string binary;
    for (char ch : code)
    {
        int value;
        if (ch >= '0' && ch <= '9')
        {
            value = ch - '0';
        }
        else if (ch >= 'A' && ch <= 'F')
        {
            value = ch - 'A' + 10;
        }
        binary += bitset<4>(value).to_string();
    }
    return binary;
}
