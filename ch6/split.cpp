#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

#include "split.h"

using std::vector;
using std::find_if;
using std::string;

using std::isspace;


// true if it is whitespace
bool space(char c)
{
    return isspace(c);
}

// false if is whitespace
bool not_space(char c)
{
    return !isspace(c);
}

// another version of split
vector<string> split(const string& s)
{
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = s.begin();
    while (i != str.end()) {

        // ignore leading whitespace
        i = find_if(i, s.end(), not_space);

        // we don't need to test for i == s.end()
        //library will handle empty range for us
        // find end of next word
        iter j = find_if(i, s.end(), space);

        // copy the chars in [i, j)
        if (i != s.end())
            ret.push_back(string(i, j));

        i = j;

    }
    return ret;
}
