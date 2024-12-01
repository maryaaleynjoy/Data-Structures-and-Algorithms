#include <iostream>
using namespace std;

int main()
{
    float celsius, fahrenheit;
    char option; 
     
    cout<<"Enter a Temperature(C, F) ";
    cin >> option;

    if (option == 'F') {
    cout << "Enter the Temperature; ";
    cin >> fahrenheit;
    celsius = (fahrenheit - 32) * 5 / 9;




    } else (option == 'C') {
    cout << "Enter the Temperature: ";
    cin >> celsius;
    fahrenheit = (celsius 9 /5 ) + 32;

    }

    return 0;
}