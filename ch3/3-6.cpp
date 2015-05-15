#include <iomanip>
#include <iostream>
#include <string>

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::streamsize;  using std::setprecision;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterma and final exam grades: ";
    double midterm, final;
    cin >> midterm, final;

    cout << "Enter all your homework, "
        "followed by end-of-file: ";

    // the number and sum of grades read so far
    int count = 0;
    double sum = 0;

    // a variable into which to read
    double x;
    // invariant:
    // we have read 'count' grade so far, and
    // 'sum' is the sum of the first 'count' grade
    while (cin >> x) {
        ++count;
        sum += x;
    }

    // check for whether it divide by zero
    double homework_grade = (count > 0) ? sum / count : 0;

    streamsize prec = cout.precision();
    cout << "Your final grades is " << setprecision(3)
        << 0.2 * midterm + 0.4 * final + 0.4 * homework_grade
        << setprecision(prec) << endl;

    return 0;
}
