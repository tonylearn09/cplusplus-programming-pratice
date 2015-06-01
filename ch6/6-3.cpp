// this program is wrong
// since copy should make sure that v has enough space
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), v);

    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << endl;

    return 0;
}
