#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Please enter the height of the picture: ";
    int height;
    cin >> height;

    cout << "Please enter the length for rectangle: ";
    int length;
    cin >> length;

    cout << endl;
    // for square
    for (int i = 0; i != height; ++i) {
        for (int j = 0; j != height; ++j)
            cout << "*";
        cout << endl;
    }

    cout << endl;

    // for triangle
    for (int i = 0; i != height; ++i) {
        // because need to have one * at the first line
        for (int j = 0; j != i + 1; ++j)
            cout << "*";
        cout << endl;
    }

    cout << endl;

    // for rectangle
    for (int i = 0; i != height; ++i) {
        for (int j = 0; j != length; ++j)
            cout << "*";
        cout << endl;
    } 
    
    return 0;
}
