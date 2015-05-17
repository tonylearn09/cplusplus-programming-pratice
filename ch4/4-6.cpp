#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::ostream;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::max;

struct Student_info {
    string name;
    double grade;
};


// compute the median of a `vector<double>'
// // note that calling this function copies the entire argument `vector'
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}


// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const vector<double>& hw) 
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");

    return grade(midterm, final, median(hw));
}

// for struct student
double grade(const Student_info& s)
{
    return s.grade;
}

// read homework grades from an input stream into a `vector<double>'
istream& read_hw(istream& in, vector<double>& hw) 
{
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

istream& read(istream& is, Student_info& s)
{
    // we define to store the input
    double midterm, final;

    is >> s.name >> midterm >> final;

    // we define to hole the homework
    vector<double> homework;
    read_hw(is, homework);

    // if current cin is not in the error state
    // since read_hw will in.clear() to clear error if it succeed 
    // reading homework
    // and leave error state if the beginning reading homework fail
    if (cin)
        s.grade = grade(midterm, final, homework);


    return is;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}


int main() 
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    try {
        // read and store the records, and find the max length name
        while (read(cin, record)) {
            maxlen = max(maxlen, record.name.size());
            students.push_back(record);
        }
    } catch (domain_error& e) {
        cout << e.what() << endl;
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        // write the name, padded on the right to maxlen+1 characters
        cout << students[i].name
            << string(maxlen + 1 - students[i].name.size(), ' ');

        // coompute and write the grade
        double final_grade = grade(students[i]);
        streamsize prec = cout.precision();
        cout << setprecision(3) << final_grade
            << setprecision(prec);

        cout << endl;
    }

    return 0;
}
