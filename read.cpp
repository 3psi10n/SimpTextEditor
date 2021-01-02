#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
int read ()
{
    using namespace std;
    int line = 1;
    int line_num = 24;
    string input;
    string sentence;
    char filename[50];
    ifstream readfile;
    cout << "Enter file name: ";
    cin.getline(filename, 50);
    
    readfile.open(filename);
    while (line <= line_num){
        getline(readfile, sentence);
        cout << line << "\t> " << sentence << endl;
        line++;
            if (line >= line_num){
                cout << "Do you want to see more ? [y/n]: ";
                cin >> setw(1) >> input;
                cin.ignore(999*999, '\n');
                    if (input == "y" || input == "Y")
                    {
                        line_num = line_num + 24;
                    }
                    else
                    {
                        cout << "Moving you back to the main menu..." << endl << "Choose what you want to do: ";
                        return false;
                    }
            }
    }
}
