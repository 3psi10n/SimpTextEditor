#include "edit.h"

using namespace std;


int content::edit(){
    int line = 1;
    string text, buffer;
    char filename[50];

    ofstream editfile;
    

    cout << "Enter name of the file to edit (or create): ";
    cin.getline(filename, 50);

    ifstream readfile(filename);

    editfile.open(filename, std::ofstream::out | std::ofstream::app);
    // readfile.open(filename, std::ofstream::in);
    // cout << "Okay, now type something: " << endl;
    while (std::getline(readfile, text)){
        buffer += text + "\n";
        cout << setw(3) << line++ << "> " << text << endl;
    }

    while (1){
        cout << std::setw(3) <<  line << "> ";
        getline(cin, text);
        line++;
        char ch;
        if (text == "exit()"){
            editfile.close();
            cout << "Moving you back to the main menu..." << endl << "Choose what you want to do: ";
            return false;
        }
        else if (text == "find()"){

        }

        else if (text == "list()"){

        }

        else
        editfile << text << endl;
        buffer += text + "\n";
    }
}


