#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Collatz_Number {

public:
	long long num;

	Collatz_Number(long long entered_number) {
		num = entered_number;
	}

	int seq_length() {
		int sequence_length = 0;
		while (num != 1) {
			sequence_length += 1;
			if (num % 2 == 0) {
				num = num / 2;
			}
			else {
				num = (num * 3) + 1;
			}
		}
		return sequence_length;
	}

	int seq_max() {
		long long temp = num;
		long long max = temp;
		while (temp != 1) {
			if (temp % 2 == 0) {
				temp = temp / 2;
			}
			else {
				temp = (temp * 3) + 1;
				if (temp > max) {
					max = temp;
				}
			}
		}
		return max;
	}


	//nearly obselete and could be combined with seq_length() however having seperate functions for seperate operations is nicer
};


void display_seq(int max_num) {
	int count = 2;
	int temp = 2;
	while (count < max_num) {
		count += 1;
		cout << "\n\nNumber: " << temp << "\n";
		while (temp != 1) {
			if (temp % 2 == 0) {
				temp = temp / 2;
				cout << temp << " ";
			}
			else {
				temp = (temp * 3) + 1;
				cout << temp << " ";
			}
		}
		temp = count;
	}
}

bool is_valid_number(long long number_input) {
	if (number_input == abs(number_input) && (number_input != 0) && number_input < 9223372036854775807) {
		return true;
	}
	else {
		cout << "Enter Positive Numbers Only Letters Will Be Ignored" << endl;
		return false;
	}
}

int main()
{
	string menu_input;
	long long number_input;
	int max_num;
	cout << "==========  Collatz Number Calculator  ==========\n\n";
	while (true) {
		menu_input = "";
		cout << "          MENU == MENU  == MENU == MENU\n\nSelect Operation to Complete\n1. Compute Sequence Length\n2. Compute Highest Value Reached in Sequence\n3. Display Full Sequence (Limited Range)\n4. Quit\n";
		cin >> menu_input;
		if (menu_input == "1") {
			cout << "\nEnter Number To Perform Operation On: ";
			cin >> number_input;
			if (is_valid_number(number_input)) {
				Collatz_Number number(number_input);
				cout << "Sequence Length: " << number.seq_length() << endl;
			}
			else {
				cin.clear();
			}


		}
		else if (menu_input == "2") {
			cout << "\nEnter Number To Perform Operation On: ";
			cin >> number_input;
			if (is_valid_number(number_input)){
				Collatz_Number number(number_input);
				cout << "\nHighest Value Reached: " << number.seq_max() << endl;
				cout << "Difference of Entered Number and Max Value: " << abs(number.seq_max() - number_input) << endl;
			}
			else {
				cin.clear();
			}
		}
		else if (menu_input == "3") {
			while (true) {
				cout << "Enter Number to Generate Sequence Up to: ";
				cin >> max_num;
				if (cin.fail() || max_num != abs(max_num)) {
					cout << "Enter Positive Numbers Only\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				else {
					display_seq(max_num);
					break;
				}
			}

		}
		else if (menu_input == "4") {
			exit(0);
		}
		system("pause");
		system("cls");
	}
}


/*
Bibliography:
https://www.w3schools.com/cpp/cpp_classes.asp Classes
https://www.w3schools.com/cpp/cpp_class_methods.asp Methods
https://www.w3schools.com/cpp/cpp_constructors.asp Constructors
https://pvs-studio.com/en/blog/terms/0079/#:~:text=Use%20of%20uninitialized%20memory%20means,a%20so%20called%20%22heisenbug%22. Error with uninitialised memory
https://www.dcode.fr/collatz-conjecture Testing if progam matches with actual values
https://www.w3schools.blog/clear-screen-in-c-2 Clearing screen in console
https://www.youtube.com/watch?v=XRLLk7HyR3s cin.clear(), cin.ignore()
https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected cin.ignore()
*/
