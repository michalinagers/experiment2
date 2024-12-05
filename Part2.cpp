#include <iostream>
#include <fstream>

using namespace std;

int addition(int op1, int op2) { return op1 + op2; }
int subtract(int op1, int op2) { return op1 - op2; }
int multiply(int op1, int op2) { return op1 * op2; }
int divide(int op1, int op2) { return (op2 != 0) ? op1 / op2 : 0; } //handle division by zero



int main()
{
	int (*operations[5])(int op1, int op2) = { nullptr, &addition, &subtract, &multiply, &divide };
	int (*operation)(int, int) = nullptr;
	cout << "Welcome";
	cout << "1:Addition\n2:Subtract\n3:Multiply\n4:Divide";
	int choice;
	cin >> choice;
	operation = operations[choice];
	cout << "Selected operation" << choice << "processing";

	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	if (inputFile.is_open() && outputFile.is_open())
	{
		int op1, op2;
		while (inputFile >> op1 >> op2) {
			{
				int result = operation(op1, op2);
				outputFile << "Result: " << result << "\n";
			}
		}
	}
	else {
		cout << "Error";
	}

	if (inputFile.is_open())
		inputFile.close();

}