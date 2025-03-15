#include <bits/stdc++.h>
#include "242.cpp"

using namespace std;

int main() {
    Solution* sol = new Solution();
    string s = "anagram";
    string t = "nagaram";

    bool result = sol->isAnagram(s, t);
    cout << (result ? "True" : "False") << endl;
}