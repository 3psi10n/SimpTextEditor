#include "cmp.h"

using namespace std;

map <string, int> mywordMap1;
map <string, int> mywordMap2;

// bool buildMap();
// void writeIndex();
// void AddWordtoMap(std::string);

// int main(int argc, char** argv) {

//     if (buildMap()){
//         cout<<"\n The map has "<< wordMap.size() << " elements";
//         writeIndex();
//     }
//     return 0;
// }

bool buildMap_cmp(){
    bool flag = true;
    string filename;
    cout<<"Enter file name 1 : ";
    cin>>filename;

    ifstream inputFile(filename.c_str());
    string line;

    if(inputFile.is_open()){
        // cout << "Word list: ";
        while(getline(inputFile, line)){
        std::size_t prev =0, pos;

        while((pos =  line.find_first_of("~`=!@#$%^&*)/\?-_|[,. }] (_-+{;'\'\":""></", prev)) != std::string::npos){
                if(pos>prev){
                AddWordtoMap1_cmp(line.substr(prev, pos-prev));
            }
            prev= pos+1;
        }
            if(prev< line.length()){
                AddWordtoMap1_cmp(line.substr(prev, std::string::npos));
            }
        }

        inputFile.close();
    }
    else
    {
        cout<<"\n___Unable to open file___\n"<<endl;
        flag = false;
    }
    

    string filename2;
    cout<<"Enter file name 2 : ";
    cin>>filename2;

    ifstream inputFile2(filename2.c_str());

    if(inputFile2.is_open()){
        // cout << "Word list: ";
        while(getline(inputFile2, line)){
        std::size_t prev =0, pos;

        while((pos =  line.find_first_of("~`=!@#$%^&*)/\?-_|[,. }] (_-+{;'\'\":""></", prev)) != std::string::npos){
                if(pos>prev){
                AddWordtoMap2_cmp(line.substr(prev, pos-prev));
            }
            prev= pos+1;
        }
            if(prev< line.length()){
                AddWordtoMap2_cmp(line.substr(prev, std::string::npos));
            }
        }

        inputFile2.close();
    }
    else
    {
        cout<<"\n___Unable to open file___\n"<<endl;
        flag = false;
    }
    return flag;
}

void AddWordtoMap1_cmp(std:: string str){
        
    map<string, int> ::iterator it = mywordMap1.find(str);

    if(it!=mywordMap1.end()){
        it->second = it->second + 1;
    }
    else{
        mywordMap1.insert(std::make_pair(str, 1));
    }
}

void AddWordtoMap2_cmp(std:: string str){
        
    map<string, int> ::iterator it = mywordMap2.find(str);

    if(it!=mywordMap2.end()){
        it->second = it->second + 1;
    }
    else{
        mywordMap2.insert(std::make_pair(str, 1));
    }
}


void compare(){
    if (buildMap_cmp()){
        auto it1 = mywordMap1.begin();
        auto it2 = mywordMap2.begin();
        while( true ) {
            bool end1 = it1 == mywordMap1.end();
            bool end2 = it2 == mywordMap2.end();
            if( end1 and end2 ) break;
            if( !end1 and ( end2 or it1->first < it2->first ) ) {
                std::cout << "\tkey: '" << it1->first << "' not found in map2" << std::endl;
                ++it1;
                continue;
            } 
            if( end1 or it2->first < it1->first ) {
                std::cout << "\tkey: '" << it2->first << "' not found in map1" << std::endl;
                ++it2;
                continue;
            } 
            if( it1->second != it2->second ) {
                std::cout << "\tkey: '" << it2->first << "' found both maps:" << std::endl;
                std::cout << "\t\tvalues for key: '" << it1->first << "' are different: "<<it1->second<< " vs " << it2->second << std::endl;
            }
            ++it1;
            ++it2;
        }
    }
    else{
        std::cout << "Cant compare !" << endl;}
    // cout << "Choose the operator you want to perform:";
    // string command;
    // getline(cin, command);
    // boost::algorithm::to_lower(command);
    // if (command == "")
    

    
    cout << "\n___Done___" << endl;
    cout << "Moving you back to the main menu..." << endl << "Choose what you want to do: ";
}