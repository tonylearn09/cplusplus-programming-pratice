#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cin;     using std::cout;
using std::endl;    using std::setprecision;
using std::string;
using std::vector;  using std::sort;
using std::streamsize;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for midterm and final
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for and read the homework grades
    cout << "Enter all your homework grades, "
        "followed by end-of-file(ctrl-d): ";
    vector<double> homework;

    double x;
    // invariant: homework contains all the homework grades
    while (cin >> x)
        homework.push_back(x);

    // we need size in two place, so need to create local variable
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    // check if it is empty
    if (size == 0) {
        cout << endl << "You must enter your grades. "
            "Please try again." << endl;

        return 1;
    }
    
    // sort the grade
    sort(homework.begin(), homework.end());

    // compute the mdeian
    double median;
    vec_sz mid = size / 2;
    median = (mid % 2 == 0) ? (homework[mid] + homework[mid - 1]) / 2
        : homework[mid];


    // compute and write the final grade
    streamsize prec = cout.precision();
    cout << "your final grade is " << setprecision(3)
        << 0.2 * midterm + 0.4 * final + 0.4 * median
        << setprecision(prec) << endl;

    return 0;

    
}
