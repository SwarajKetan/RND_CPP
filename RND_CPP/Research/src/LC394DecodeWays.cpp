#include "Runnable.h"
#include <stack>
#include <string>

using namespace std;
class Solution {

    //struct Char {
    //    Char(char c, int index) :_c(c),_index(index) {}

    //   inline bool isdigit() const {
    //        return std::isdigit(_c);
    //    }

    //private:
    //    char _c;
    //    int _index;
    //};

public:
    string decodeString(string s) {
        stack<int> nums;
        stack<char> braces;
        stack<int> starts;
        std::string dec;

        std::string part;
        int i = 0;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                nums.push(s[i++] - 48);
                continue;
            }

            if (s[i] == '[') {
                braces.push('[');
                starts.push(i++);
                continue;
            }

            if (s[i] == ']') {
                int c = nums.top(); nums.pop();
                for (int j = 0; j < c; j++) {
                    dec += part;
                }
                i++;
                part = "";
                continue;
            }
            std::string k(1, s[i++]);
            part += k;

        }
        return dec;
    }
};