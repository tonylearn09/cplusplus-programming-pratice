#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "character_picture.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> v;
    // empty vector with frame
    vector<string> f = frame(v);

    for (vector<string>::const_iterator i = f.begin(); i != f.end(); ++i)
        cout << *i << endl;

    return 0;
}
