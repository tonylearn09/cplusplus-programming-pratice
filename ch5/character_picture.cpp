#include <algorithm>
#include <string>
#include <vector>

#include "character_picture.h"

using std::string;
using std::vector;
using std::max;

// find the maxlen for all the string
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;

    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }

    return maxlen;
}

// frame the whole picture with *
vector<string> frame(const vector<string>& v)
{
    vector<string> result;
    string::size_type maxlen = width(v);
    
    string border(maxlen + 4, '*');

    // write the top border
    result.push_back(border);

    // write each interior row, bordered by an * and a space
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        result.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }

    // write the bottom border
    result.push_back(border);

    return result;
}

// vertical concatinate
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    // copy the top picture
    vector<string> ret = top;

    // copy the bottom picture
    for (vector<string>::const_iterator it = bottom.begin();
            it != bottom.end(); ++it)
        ret.push_back(*it);

    return ret;
}


// horizontal concatinate
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;

    // add one to leave a space betwween pictures
    string::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;

    // continue until we seen all rows from both pictures
    while (i != left.size() || j != right.size()) {
        // construct new string to hold chars from both pictures
        string s;

        // copy from the left, if there is one
        if (i != left.size())
            s = left[i++];

        // pad to full width
        s += string(width1 - s.size(), ' ');

        // copy from the right, if there is one
        if (j != right.size())
            s += right[j++];

        // don't nee to pad

        ret.push_back(s);
    }

    return ret;

}
