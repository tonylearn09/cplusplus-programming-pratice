#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using std::cin;
using std::endl;
using std::string;
using std::cout;
using std::equal;


bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}


int main()
{
    string s;
    while (cin >> s) {
        if (is_palindrome(s))
            cout << s << " is a plindrome" << endl;
        else
            cout << s << " is not a palindrome" << endl;
    }

    return 0;
}
