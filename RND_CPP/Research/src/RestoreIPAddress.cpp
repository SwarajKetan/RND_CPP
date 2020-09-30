#include "Runnable.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace RestoreIPAddress {

    struct Solution : public Runnable {
    private:
        vector<string> ans;
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> segs;
            backtrack(s, "", segs);
            return ans;
        }

        bool isvalidseg(string& s) {
            if (s == "") return true;

            long x = stoi(s);
            return (x >= 0 && x <= 255) && to_string(x).size() == s.size();
        }
        // s 
        void backtrack(string s, string seg, vector<string> segs) {
            std::cout << "s = " << s << " seg = " << seg << std::endl;

            if (!isvalidseg(seg)) {
                return;
            }

            if (seg != "") {
                segs.push_back(seg);
            }

            if (segs.size() == 4) {
                if (s.size() == 0) {
                    string tmp = segs[0];
                    for (int i = 1; i <= 3; i++) {
                        tmp = tmp + "." + segs[i];
                    }
                    ans.push_back(tmp);
                    return;
                }
            }

            for (int len = 1; len <= 3 && s.size() >= len; len++) {
                backtrack(s.substr(len), s.substr(0, len), segs);
            }
        }


        // Inherited via Runnable
        virtual void Run() override
        {
            string input = "25525511135";
            auto res = restoreIpAddresses(input);
        }

    };
}

