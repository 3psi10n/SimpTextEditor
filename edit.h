#ifndef EDIT
#define EDIT

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h> 

# define NO_OF_CHARS 256 

using namespace std;

class content {
    private:
        int line = 1;
        char file_name[50];
        string text, buffer ;
    public:
        int edit();
};



// int content::edit();

#endif /*EDIT*/