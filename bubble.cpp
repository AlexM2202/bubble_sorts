#include <iostream>
#include <fstream>
#include <vector>

#define MAX_COUNT 100000

using namespace std;

int main(int argc, char* argv[]){
    string fname;
    cout << "Enter file - ";
    cin >> fname;
    fstream ifile(fname);
    if(!ifile){
        cerr << "ERROR: " <<fname<<" does not exist!" << endl;
        return 1;
    }
    int count;
    ifile >> count;
    // cout << count << endl;
    int curr;
    vector<int> vect;
    for(int x=0; x<count; x++){
        ifile >> curr;
        // cout << "read - " << curr << endl;
        vect.push_back(curr);
    }
    bool swapped=true;
    int temp;
    cout << "Sort Started on " << count << " items" << endl;
    while(swapped){//while we have made a swap
        swapped=false;
        for(int x = 0; x < vect.size()-1; x++){
            if (vect[x] > vect[x+1]){//is our current string bigger then the next?
                temp = vect[x];//swap them
                vect[x] = vect[x+1];
                vect[x+1] = temp;
                swapped=true;
            }
        }
    }
    cout << "Done, writing now" << endl;
    fstream ofile("outpu_cpp.txt", ios::out);
    if(!ofile)
        cout << "ERROR: no output!" << endl;
    for(int x = 0; x < vect.size(); x++){
        ofile << vect[x] << endl;
    }
    return 0;
}