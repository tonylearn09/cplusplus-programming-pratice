#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    typedef string::size_type str_sz;

    string longest;
    str_sz longest_size = 0;
    string shortest;
    str_sz shortest_size = 0;

    cout << "Words: ";
    string s;

    while (cin >> s) {
        // need to take care of the initial one
        if (s.size() > longest_size || longest_size == 0) {
            longest = s;
            longest_size = s.size();
        }

        // can't use else if, since the initial one 
        // need both condition
        if (s.size() < shortest_size || shortest_size == 0) {
            shortest = s;
            shortest_size = s.size();
        }
    }

    cout << "Longest: " << longest << endl;
    cout << "Shortest: " << shortest << endl;

    return 0;
}
