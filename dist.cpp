#include "dist.h"

using namespace std;

map <string, int> mywordMap;

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

bool buildMap(){
        
    string filename;
    cout<<"Enter file name : ";
    cin>>filename;

    ifstream inputFile(filename.c_str());
    string line;

    if(inputFile.is_open()){
        cout << "Word list: ";
        while(getline(inputFile, line)){
        std::size_t prev =0, pos;

        while((pos =  line.find_first_of("~`=!@#$%^&*)/\?-_|[,. }] (_-+{;'\'\":""></", prev)) != std::string::npos){
                if(pos>prev){
                AddWordtoMap(line.substr(prev, pos-prev));
            }
            prev= pos+1;
        }
            if(prev< line.length()){
                AddWordtoMap(line.substr(prev, std::string::npos));
            }
        }

        inputFile.close();
    }
    else
    {
        cout<<"\n___Unable to open file___\n"<<endl;
        return false;
    }

    return true;
}

void AddWordtoMap(std:: string str){
        
    map<string, int> ::iterator it = mywordMap.find(str);

    if(it!=mywordMap.end()){
        it->second = it->second + 1;
    }
    else{
        mywordMap.insert(std::make_pair(str, 1));
    }
}

void writeIndex(){
    for(map<string, int> ::iterator itr = mywordMap.begin(); itr!=mywordMap.end(); ++itr){
        std::cout<<"\n"<< setw(20) <<itr->first<<":"<< setw(4)<<itr->second;
    }	
}
