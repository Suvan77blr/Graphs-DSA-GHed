
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(void) {
    
    std :: ifstream fin("input.txt");
    std :: ofstream fout("output.txt");

    if(!fin) {
        cout << "Unable to open file for INPUT.";
        return 1;
    }
    if(!fout) {
        cout << "Unable to open file for OUTPUT.";
        return 1;
    }

    string name;
    int num;
    double db;

    getline(fin, name);
    fin >> num >> db;

    vector<int> v(num);
    for(int i=0; i<num; i++) {
        fin >> v[i];
    }

    cout << "Read from file : " << name << " " << num << " " << " " << db << endl;
    fout << "Hi " << name << "!" << endl;
    fout << "Integer : " << num << endl;
    fout << "Double : " << db << endl;

    fout << "Vector : [ ";
    for(const int& ele : v){
        fout << ele << " ";
    }fout << "]\n";

    fin.close();
    fout.close();

    return 0;
}


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
