#include <iostream>

using namespace std;

int main()
{
    int first;
    int second;
    char operation;

    cout << "------------------------------------\n" <<endl;
    cout << "Welcome To Calculator" <<endl;
    cout << "\n---------------------------------\n" << endl;
    cout << "Enter equation (2+3) : ";
    cin >> first >> operation >> second;
    
     switch (operation)
    {
        case '+' :
        cout << "\nAnswer : " << first + second;
        break;

        case '-' :
        cout << "\nAnswer : " << first - second;
        break;

        case '*' :
        cout << "\nAnswer : " << first * second;
        break;

        case '/' :
        cout << "\nAnswer : " << first / second;
        break;

        default :
        cout << "Invalid operator." << endl;
        cout << "Ending the program." <<endl;
        cout << "---------------------------" <<endl;
        break;
    }
}