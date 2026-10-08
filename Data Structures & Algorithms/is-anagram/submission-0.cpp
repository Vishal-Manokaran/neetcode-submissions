#include <string>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> d1, d2;
        for (char i : s) {
            if (d1.contains(i))
                d1[i]++;
            else
                d1[i] = 1;
        }
        for (char i : t) {
            if (d2.contains(i))
                d2[i]++;
            else
                d2[i] = 1;
        }
        if (d1 == d2) return true;
        return false;
    }
};
