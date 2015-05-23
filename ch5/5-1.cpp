#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

#include "split.h"

using namespace std;

struct Rotation {
	vector<string> words;
	vector<string>::size_type first;
};

vector<string> read_lines()
{
	vector<string> lines;
	string line;

	while (getline(cin, line))
		lines.push_back(line);

	return lines;
}

vector<Rotation> rotate_line(string line)
{
	vector<Rotation> rotations;
	vector<string> words = split(line);

	for (vector<string>::size_type i = 0; i < words.size(); ++i) {
		Rotation new_rot = { words, words.size() - i };
		rotations.push_back(new_rot);
		rotate(words.begin(), words.begin() + 1, words.end());
	}

	return rotations;
}

vector<Rotation> rotate_lines(vector<string>& lines)
{
	vector<Rotation> rotations;

	for (vector<string>::iterator it = lines.begin();
	        it != lines.end(); ++it) {
		vector<Rotation> new_rotations = rotate_line(*it);
		rotations.insert(rotations.end(),
		                 new_rotations.begin(), new_rotations.end());
	}
	return rotations;
}

bool compare(const Rotation& x, const Rotation& y)
{
	// Compares the contents of lhs and rhs lexicographically
	// it is vector relational operator overload
	return x.words < y.words;
}

void print_rotations(vector<Rotation> rotations)
{
	vector<string> left;
	vector<string> right;
	string::size_type max_left_width = 0;

	for (vector<Rotation>::size_type i = 0; i < rotations.size(); ++i) {
		Rotation rot = rotations[i];
		string left_hand_side, right_hand_side;

		for (vector<string>::size_type j = rot.first; j < rot.words.size(); ++j) {
			left_hand_side += rot.words[j] + " ";
		}

		left.push_back(left_hand_side);

		if (left_hand_side.size() > max_left_width)
			max_left_width = left_hand_side.size();

		for (vector<string>::size_type j = 0; j < rot.first; ++j)
			right_hand_side += rot.words[j] + " ";

		right.push_back(right_hand_side);
	}

	for (vector<string>::size_type i = 0; i < left.size(); ++i) {
		cout << setw(max_left_width)
		     << left[i]
		     << "\t"
		     << right[i]
		     << endl;
	}
}

int main()
{
	vector<string> lines = read_lines();
	vector<Rotation> rotations = rotate_lines(lines);
	sort(rotations.begin(), rotations.end(), compare);
	print_rotations(rotations);

	return 0;
}