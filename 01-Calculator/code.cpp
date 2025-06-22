#include <iostream>
#include <cmath>
using namespace std;


float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float power(float a, float b);
float modulus(float a, float b); 

int main() {
    float num1, num2, result;
    int choice;
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        cout << "\n===== Simple Calculator =====" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Power (a^b)" << endl;
        cout << "6. Modulus (a % b)" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose operation (1-7): ";
        cin >> choice;

        if (choice == 7) {
            cout << "Exiting calculator.\n";
            break;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                break;
            case 2:
                result = subtract(num1, num2);
                break;
            case 3:
                result = multiply(num1, num2);
                break;
            case 4:
                if (num2 == 0) {
                    cout << "Error: Division by zero!" << endl;
                    continue;
                }
                result = divide(num1, num2);
                break;
            case 5:
                result = power(num1, num2);
                break;
            case 6:
                if (num2 == 0) {
                    cout << "Error: Modulus by zero!" << endl;
                    continue;
                }
                result = modulus(num1, num2);
                break;
            default:
                cout << "Invalid choice!" << endl;
                continue;
        }

        cout << "Result = " << result << endl;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> again;
    }

    return 0;
}


float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

float power(float a, float b) {
    return pow(a, b);
}

float modulus(float a, float b) {
    return fmod(a, b);
}
