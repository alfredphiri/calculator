#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

double getNumber(const string &prompt) {
    double x;
    while (true) {
        cout << prompt;
        if (cin >> x) return x;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number — please try again.\n";
    }
}

long long getInteger(const string &prompt) {
    long long n;
    while (true) {
        cout << prompt;
        if (cin >> n) return n;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid integer — please try again.\n";
    }
}

unsigned long long factorial(unsigned int n) {
    unsigned long long r = 1;
    for (unsigned int i = 2; i <= n; ++i) r *= i;
    return r;
}

void printHeader() {
    cout << "========================================\n";
    cout << "         Simple Nice Calculator         \n";
    cout << "========================================\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    printHeader();

    while (true) {
        cout << "\nMenu:\n"
             << " 1) Add (+)\n"
             << " 2) Subtract (-)\n"
             << " 3) Multiply (*)\n"
             << " 4) Divide (/)\n"
             << " 5) Power (x^y)\n"
             << " 6) Square root (√x)\n"
             << " 7) Modulo (x % y) [integers]\n"
             << " 8) Factorial (n!) [non-negative integer]\n"
             << " 9) Clear screen\n"
             << " 0) Exit\n";

        cout << "Choose an option: ";
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        cout << fixed << setprecision(6);

        switch (choice) {
            case 1: {
                double a = getNumber("A = ");
                double b = getNumber("B = ");
                cout << "Result: " << (a + b) << "\n";
                break;
            }
            case 2: {
                double a = getNumber("A = ");
                double b = getNumber("B = ");
                cout << "Result: " << (a - b) << "\n";
                break;
            }
            case 3: {
                double a = getNumber("A = ");
                double b = getNumber("B = ");
                cout << "Result: " << (a * b) << "\n";
                break;
            }
            case 4: {
                double a = getNumber("A = ");
                double b = getNumber("B = ");
                if (b == 0.0) {
                    cout << "Error: Division by zero.\n";
                } else {
                    cout << "Result: " << (a / b) << "\n";
                }
                break;
            }
            case 5: {
                double a = getNumber("Base = ");
                double b = getNumber("Exponent = ");
                cout << "Result: " << pow(a, b) << "\n";
                break;
            }
            case 6: {
                double a = getNumber("x = ");
                if (a < 0.0) {
                    cout << "Error: Negative number has no real square root.\n";
                } else {
                    cout << "Result: " << sqrt(a) << "\n";
                }
                break;
            }
            case 7: {
                long long a = getInteger("A (int) = ");
                long long b = getInteger("B (int) = ");
                if (b == 0) {
                    cout << "Error: Modulo by zero.\n";
                } else {
                    cout << "Result: " << (a % b) << "\n";
                }
                break;
            }
            case 8: {
                long long n = getInteger("n (non-negative) = ");
                if (n < 0) {
                    cout << "Error: negative integer.\n";
                } else if (n > 20) {
                    cout << "Warning: results may overflow for n > 20; limiting to 20.\n";
                    cout << "Result: " << factorial(20) << "\n";
                } else {
                    cout << "Result: " << factorial(static_cast<unsigned int>(n)) << "\n";
                }
                break;
            }
            case 9: {
                // Clear screen (Windows)
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                printHeader();
                break;
            }
            default:
                cout << "Unknown option.\n";
        }
    }

    return 0;
}