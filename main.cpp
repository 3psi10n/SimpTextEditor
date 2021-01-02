#include <iostream>
#include <string>
#include <string.h>
#include "edit.h"
#include "find.h"
#include "dist.h"
#include "cmp.h"
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h> 

using namespace std;

void init(){
    cout << "Type 'edit' to edit a text file" << endl;
    cout << "Type 'exit' to exit from the text editor" << endl;
    cout << "Type 'find' to find pattern from file" << endl;
    cout << "Type 'list' to get list and and distribution of words from file" << endl;
    cout << "Type 'cmp' to compare 2 files" << endl;
    cout << "Choose what you want to do: ";
}


int main ()
{
    
    string command;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "      Welcome to the most awesome text editor!      " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    init();

    while (1)
    {
        getline(cin, command);
        boost::algorithm::to_lower(command);

        if (command == "edit" || command == "^e" || command == "^E"){
            content contents;
            contents.edit();
        }
        
        
        else if (command == "exit" ||command == "^e" || command == "^x" || command == "^q" || command == "^c" || command == "^d" || command == "^E" || command == "^X"  || command == "^Q" || command == "^C" || command == "^D")
        {
            cout << "Bye! See you soon!" << endl;
            return false;
        }

        else if (command == "list" )
        {
            //list function
            if (buildMap()){
                writeIndex();
            }
            cout << "\n___Done___" << endl;
            cout << "Moving you back to the main menu..." << endl << "Choose what you want to do: ";
            getline(cin, command);
            boost::algorithm::to_lower(command);
            continue;
        }

        else if (command == "help" )
        {
            init();
        }

        else if (command == "find" )
        {
            //find function
            string txt;
            string pat;
            cout << "Enter file name: "; getline(cin,txt);
            cout << "Enter regex you want to find: "; getline(cin,pat);
            cout << "Searched for \'" << pat << "\' in \'" << txt <<"\':\n" ;
            search_moore(txt, pat);         
        }

        else if (command == "cmp" )
        {
            compare();
            getline(cin, command);
            boost::algorithm::to_lower(command);
            continue;
        }

        else
        {
            cout << "Wrong command!" << endl << "Try again or use 'help': ";
        }
    }
}
