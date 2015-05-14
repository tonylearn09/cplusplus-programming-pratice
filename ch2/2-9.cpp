#include <iostream>

using namespace std;

int main()
{
    cout << "Enter two numbers: ";
    int a, b;
    cin >> a >> b;

    if (a > b)
        cout << "First is greater" << endl;
    else if (b > a)
        cout << "Second is greater" << endl;
    else
        cout << "Equal!" << endl;

    return 0;
}
