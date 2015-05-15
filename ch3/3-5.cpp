#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int homework_num = 2;

int main()
{
    vector<string> names;
    vector<int> final_grades;

    char choice;
    do {
        // ask for name
        cout << "Please enter your first name: ";
        string name;
        cin >> name;
        cout << "Hello, " << name << "!" << endl;
        names.push_back(name);

        // ask for midterm and final
        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;

        // ask for homework
        cout << "Enter both your homework grade, "
            "followed by ctrl-d: ";

        // the number and sum of grades read so far
        int count = 0;
        double sum = 0;

        // variable to read in
        double x;
        while (count < homework_num) {
            ++count;
            cin >> x;
            sum += x;
        }

        double final_grade =  0.2 * midterm + 0.4 * final + 0.4 * sum / count;
        final_grades.push_back(final_grade);

        cout << "More student?(Y/N) ";
        cin >> choice;

    } while (toupper(choice) == 'Y');

    for (vector<string>::size_type i = 0; i < names.size(); ++i) {
        streamsize prec = cout.precision();
        cout << names[i] << "'s final grade is " << setprecision(3)
            << final_grades[i]
            << setprecision(prec) << endl;
    }

    return 0;
}
