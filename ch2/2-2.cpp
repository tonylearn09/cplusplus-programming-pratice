#include <iostream>
#include <string>

using std::cin;
using std::endl;
using std::cout;
using std::string;

int main()
{
    cout << "Please enter your first name: ";

    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    // the number of blanks surrounding the greeting
    const int h_pad = 1;
    const int v_pad = 2;

    // the number of rows and cols to write
    const int rows = v_pad * 2 + 3;
    const string::size_type cols = greeting.size() + h_pad * 2 + 2;

    // a blank line to seperate the output from input
    cout << endl;

    // write 'rows' rows of output
    // invariant: we have written 'r' rows so far
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;

        // invariant: we have written 'c' chars so far
        while (c != cols) {
            // is it the time to write greeting
            if (r == v_pad + 1 && c == h_pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                // are we on the border
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";

                ++c;
            }
        }

        cout << endl;
    }

    return 0;
}
