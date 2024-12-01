#include <iostream>

using namespace std;

int main () {
    
    int Balance;
    int Withdraw;

    cout << "Enter your Current Account Balance: ";
    cin >> Balance;
    cout << "Enter the amount to Withdraw: ";
    cin >> Withdraw;

    while (true) {
        if (Withdraw >  Balance ){
            cout << "Insufficient Amount. Enter another Amount: ";
            cin >> Withdraw;

        }
        else if (Withdraw % 100 != 0)
    {
           cout << "Please enter amount: ";
           cin >> Withdraw;
           }
        else {
            Balance -= Withdraw;
            cout << "Succesful. Your Remaining Balance: " << Balance << endl;
            break;

        }

    }
cout << "Final Balance: " << Balance << endl;
    
return 0;

}
