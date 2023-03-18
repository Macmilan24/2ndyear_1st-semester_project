#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ofstream outfile("hello.txt", ios::out);

if(outfile.is_open()){
    outfile<<"Hello My Name Is Abebech"<<'\n';
    cout<<"The writing file pointer is at the following position : "<<outfile.tellp()<<endl;
    outfile<<"Hello My Name Is Kebedech"<<endl;
    outfile.close();}
    else
        cout<<"error opening file"<<endl;

    ifstream infile("hello.txt");
    string searchResult;
    infile.seekg(10,ios::beg);
    getline(infile, searchResult);
    cout << "10 from Beginning = "<<searchResult << endl;
    cout <<
}
    return 0;
}
