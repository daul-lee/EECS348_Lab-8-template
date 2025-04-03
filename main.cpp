#include "matrix.hpp"//headerfile 
#include <iostream>
#include <string> //strings for strings
#include <fstream> //include files

using namespace std;

int main(int argc, char *argv[]) {
    string filename; //file name
    string line; //lines of the file
    ifstream myfile; //read in the file
    int linecounter = 0;
    int size; 
    int i = 0;
    string number;
    int number_number; 
    std::cout << "Enter the file name: "; //input the file name
    std::cin >> filename; //input the file name from the interface  
    myfile.open(filename.c_str()); //  from stack overflow, this allows to read the inputted file name
    if (myfile.is_open()){ 
        while (getline (myfile,line)){ 
                if (linecounter == 0) {
                    size = std::stoi(line);
                }
                Matrix Entry1(size);
                Matrix Entry2(size);
                if (linecounter > 0) {
                    cout << line;
                }
            myfile.close();
            linecounter ++;
            }
    }
    else cout << "Unable to open file";
    return 0;
    }