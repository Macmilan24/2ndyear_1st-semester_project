#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Student{
string firstname;
string fathername;
string idno;
string section;
};
Student studentinfo;
void addstudent(Student studentinfo[],int& size)
{
    cout<<"Enter student name: ";
    cin>>studentinfo[size].firstname;
    cout<<"Enter father's name: ";
    cin>>studentinfo[size].fathername;
    cout<<"Enter ID number: ";
    cin>>studentinfo[size].idno;
    cout<<"Enter student's section: ";
    cin>>studentinfo[size].section;
    cout<<endl;
    size++;
    //system("CLS");
    ofstream stufile("studentfile.txt",ios::app);
for(int i = 0; i <= size; i++){
    stufile << studentinfo[i].firstname<<"\t"<<studentinfo[i].fathername<<"\t"<<studentinfo[i].idno<<"\t"<<studentinfo[i].section<<endl;
}
    system("cls");
    stufile.close();

}
void displaystudents(Student studentinfo[],const int size)
{
    string line;
    cout<<"Name\t\t\tIDNo\t\tSection\n";

    ifstream disfile("studentfile.txt");

    while (getline(disfile, line))
    {
        cout <<line<<endl;
    }
    disfile.close();
    cout<<endl;
}
void searchstudents(Student studentinfo[],const int size)
{
    string name;
    string* ptr;
    ptr=&name;
    cout<<"Enter name to search for: ";
    cin>>*ptr;
    for(int i=0;i<size;i++)
    {
        if(studentinfo[i].firstname==*ptr){
        cout<<"Name\t\t\tIDNo\t\tSection\n";
        cout<<studentinfo[i].firstname+" "+studentinfo[i].fathername<<"\t\t";
        cout<<studentinfo[i].idno<<"\t\t";
        cout<<studentinfo[i].section<<endl;
    }
    else
    {
        cout<<"Student not found.\n";
    }}
}
void modifystudent(Student studentinfo[],const int size)
{
    string name;
    string* ptr=&name;
    cout<<"Enter name to modify: ";
    cin>>*ptr;
    for(int i=0;i<size;i++)
    {
        if(studentinfo[i].firstname==*ptr){
        cout<<"Enter modified student name: ";
        cin>>studentinfo[i].firstname;
        cout<<"Enter modified father's name: ";
        cin>>studentinfo[i].fathername;
        cout<<"Enter modified IDNo: ";
        cin>>studentinfo[i].idno;
        cout<<"Enter modified section: ";
        cin>>studentinfo[i].section;
        cout<<endl;
    }
    else
    {
        cout<<"Student not found.\n";
    }}
}
void calculategpa(Student studentinfo[],const int size)
{
    system("CLS");
    float mark[100][100];
    int size2[100];
    string coursename[100][100];
    string grade[100][100];
    int crhr[100][100];
    for(int i=0;i<size;i++){
        cout<<"For student "<<i+1<<endl;
        cout<<"Enter number of course taken\n";
        cin>>size2[i];
    for(int j=0;j<*(size2+i);j++){
        cout<<"course "<<j+1<<" is: ";
        cin>>coursename[i][j];
        cout<<"Credit hours for the course is: ";
        cin>>crhr[i][j];
        cout<<"The grade for the course is: \n";
        cout<<"CAUTION: ENTER A CAPITAL LETTER\n";
        cin>>grade[i][j];}}
    for(int i=0;i<size;i++){
    for(int j=0;j<*(size2+i);j++){
    if(grade[i][j]=="A+")
    {
        mark[i][j]=4.0;
    }
    else if(grade[i][j]=="A")
    {
        mark[i][j]=4.0;
    }
    else if(grade[i][j]=="B+")
    {
        mark[i][j]=3.5;
    }
    else if(grade[i][j]=="B")
    {
        mark[i][j]=3.0;
    }
    else if(grade[i][j]=="C+")
    {
        mark[i][j]=2.5;
    }
    else if(grade[i][j]=="C")
    {
        mark[i][j]=2.0;
    }
    else if(grade[i][j]=="D")
    {
        mark[i][j]=1.0;
    }
    else
    {
        mark[i][j]=0.0;
    }}}
    float sum[100],sum2[100],gpa[100];
    for(int i=0;i<size;i++){
        for(int j=0;j<size2[i];j++){
        *(sum+i)+=mark[i][j]*crhr[i][j];
        *(sum2+i)+=crhr[i][j];
        }}
        cout<<"Name\t\t\tGPA\n";
        for(int i=0;i<size;i++){
        *(gpa+i)=*(sum+i)/ *(sum2+i);
        cout<<studentinfo[i].firstname+" "+studentinfo[i].fathername<<"\t\t"<<*(gpa+i)<<endl;
        }
        cout<<endl;
}
int main()
{
    Student studentinfo[100];
    int size=0;
    bool quit=false;
    cout<<"STUDENT MANAGEMENT SYSTEM\n\n";
    cout<<"Add student information\n";
    addstudent(studentinfo,size);
    while(!quit){
        cout<<"Select an option:\n";
        cout<<"1. Add student information\n";
        cout<<"2. Display all students\n";
        cout<<"3. Search for a student\n";
        cout<<"4. Modify student information\n";
        cout<<"5. Calculate GPA for each student\n";
        cout<<"6. Exit\n";
        int option;
        cout<<"Your option is: ";
        cin>>option;
        cout<<endl;
        switch(option){
    case 1:
        addstudent(studentinfo,size);
        break;
    case 2:
        displaystudents(studentinfo,size);
        break;
    case 3:
        searchstudents(studentinfo,size);
        break;
    case 4:
        modifystudent(studentinfo,size);
        break;
    case 5:
        calculategpa(studentinfo,size);
        break;
    case 6:
        quit=true;
        break;
    default:
        cout<<"Invalid option,\n";
        break;
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
