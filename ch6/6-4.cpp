// this is the right version for 6-3.cpp
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));

    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << endl;

    return 0;
}
