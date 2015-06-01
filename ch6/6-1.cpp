#include <algorithm>
#include <string>
#include <vector>

#include "6-1.h"

using std::string;
using std::vector;

using std::max;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());

    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    ret.push_back(border);

    for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
        ret.push_back("* " + *i + 
                string(maxlen - i->size(), ' ') + " *");

    ret.push_back(border);

    return ret;
}

vector<string> vcat(const vector<string>& top,
        const vector<string>& bottom)
{
    vector<string> ret = top;

    for (vector<string>::const_iterator it = bottom.begin();
            it != bottom.end(); ++it)
        ret.push_back(*it);

    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    string::size_type width1 = width(left) + 1;

    vector<string>::const_iterator i = left.begin();
    vector<string>::const_iterator j = right.begin();

    while (i != left.end() || j != right.end()) {
        string s;
        
        if (i != left.end())
            s = *i++;

        s += string(width1 - s.size(), ' ');

        if (j != right.end())
            s += *j++;

        ret.push_back(s);
    }

    return ret;
}
