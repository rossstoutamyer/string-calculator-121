#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
	string lhs = "";
	string operatorval = "";
	string rhs = "";
	string final_num = "0";
	string ans = "";
	string inserted = "";
	int lhs_idx = 0;
	int operatorval_idx = 0;
	
	cout << "String Calculator" << endl;
	cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
	
	while (lhs != "q" && lhs != "quit") {
		cout << ">> ";
		
		getline(cin, inserted);
		
		for (unsigned int i = 0; i < inserted.length(); i++) {
			if (inserted[i] == ' ') {
				lhs_idx = i;
				for (int j = 0; j < lhs_idx; i++) {
					lhs = lhs + inserted[j];
				}
				inserted = inserted.erase(0, lhs_idx);
				break;
			} else {
				lhs = inserted;
			}
		}
		
		for (unsigned int i = 0; i < inserted.length(); i++) {
			if (inserted[i] == ' ') {
				operatorval_idx = i;
				for (int j = 0; j < operatorval_idx; i++) {
					operatorval = operatorval + inserted[j];
				}
				inserted = inserted.erase(0, operatorval_idx);
				rhs = inserted;
				break;
			}
		}
		
		if (lhs == "q" || lhs == "quit") {
			break;
		}
		
		if (lhs == "ans") {
			lhs = ans;
		}
		if (rhs == "ans") {
			rhs = ans;
		}
		
		cout << endl;
		
		string final_num_multiply = multiply(lhs, rhs);
		string final_num_sum = add(lhs, rhs);
		string final_num_diff = subtract(lhs, rhs);
		
		if (operatorval == "+") {
			cout << "ans =" << endl;
			cout << endl;
			cout << "    " << final_num_sum << endl;
			ans = final_num_sum;
			cout << endl;
		} else if (operatorval == "-") {
			cout << "ans =" << endl;
			cout << endl;
			cout << "    " << final_num_diff << endl;
			ans = final_num_diff;
			cout << endl;
		} else if (operatorval == "*") {
			cout << "ans =" << endl;
			cout << endl;
			cout << "    " << final_num_multiply << endl;
			ans = final_num_multiply;
			cout << endl;
		} else {
			cout << "ans =" << endl;
			cout << endl;
			cout << "    " << lhs << endl;
			ans = lhs;
			cout << endl;
		}
	}
	cout << endl;
	cout << "farvel!" << endl;
	cout << endl;
    
    return 0;
}

