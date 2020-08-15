#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        if (m > n) { swap(str1, str2); swap(m, n); }
        if (n % m == 0) {
            string temp="";
            for (int i = 1; i <= n / m; i++)
                temp += str1;
            if (temp == str2)return str1;
        }
        for (int i = m / 2; i >= 1; i--) {
            if (m % i != 0 || n % i != 0)continue;
            string temp1 = "";
            string substr1 = str1.substr(0,  i);
            string substr2 = str2.substr(0,  i);
            if (substr1 != substr2)continue;
            for (int j = 1; j <= m / i; j++)                 
                temp1 += substr1;
            if (temp1 != str1)continue;
            string temp2 = "";
            for (int j = 1; j <= n / i; j++)
                temp2 += substr2;
            if (temp2 != str2)continue;
            return substr1;
        }
        return "";
    }
};

int main() {
    Solution sol;
    string s1 = "ababab";
    string s2 = "abab";
    cout << sol.gcdOfStrings(s1, s2);

    return 0;
}