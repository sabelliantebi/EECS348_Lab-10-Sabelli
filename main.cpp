#include <iostream> //for input output
#include <fstream>  //for reading the file
#include <string>   //to work with string numbers
#include "calculator.hpp" //our header file

using namespace std;

int main(int argc, char* argv[]) {
    string filename;
    cout << "Enter the input file name: ";
    cin >> filename; //get file name from user

    ifstream file(filename); //open the file
    if (!file.is_open()) {
        cerr << "Could not open file." << endl;
        return 1; //stop the program
    }

    string line; //to store each line
    while (getline(file, line)) { //read each line of the file
        cout << "Read: " << line << endl;

        if (is_valid_double(line)) { //check if it's a valid double
            string result = add_doubles(line, "-123.456"); //add to -123.456
            cout << "Valid! Result of adding -123.456: " << result << endl;
        } else {
            cout << "Invalid double format!" << endl;
        }

        cout << "-----------------------------" << endl;
    }

    file.close(); //close the file
    return 0; //end program
}

