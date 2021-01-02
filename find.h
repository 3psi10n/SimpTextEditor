#ifndef _FIND_
#define _FIND_

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <bits/stdc++.h> 

#define NO_OF_CHARS 256 

using namespace std;

void badCharHeuristic( string str, int size, int badchar[NO_OF_CHARS]) ;

void search_moore(string txt, string pat) ;


#endif /*_FIND_*/