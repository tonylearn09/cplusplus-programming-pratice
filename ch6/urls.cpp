#include <algorithm>
#include <cctype>
#include <vector>
#include <string>

#include "urls.h"

using std::find;
using std::find_if;

using std::string;
using std::vector;
using std::search;

bool not_url_char(char c);

string::const_iterator url_end(string::const_iterator, string::const_iterator);

string::const_iterator url_beg(string::const_iterator, string::const_iterator);


vector<string> find_urls(const string& s)
{
    vector<string> ret;

    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    // look through the entire input
    while (b != e) {
        // look for one or more letters followed by `://'
        b = url_beg(b, e);

        if (b != e) {
            iter after = url_end(b, e);

            // advance `b' and check for more \s-1URL\s0s on this line
            ret.push_back(string(b, after));

            // advance `b' and check for more \s-1URL\s0s on this line
            b = after;
        }
    }

    return ret;

}

bool not_url_char(char c)
{
    // characters, in addition to alphanumerics, that can appear in a \s-1URL\s0
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    return !(isalnum(c) ||
            find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}


string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";

    typedef string::const_iterator iter;

    // i marks the seperator was found
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        // make sure the separator isn't at the beginning or end of the line
        if (i != b && i + sep.size() != e) {

            // `beg' marks the beginning of the protocol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            // is there at least one appropriate character before and after the separator?
            if (beg != i && i + sep.size() != e && 
                    !not_url_char(i[sep.size()]))
                return beg;
        }
        // the separator we found wasn't part of a \s-1URL\s0; advance `i' past this separator
        if (i != e)
            i += sep.size();
    }
    return e;
}
