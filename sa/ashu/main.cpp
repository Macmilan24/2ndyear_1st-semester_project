#include <iostream>
using namespace std;
struct test{
string question;
string answer;
string studentanswer;
};
void addquestion(test test1[],int& size)
{
    cout<<"Enter question:\n ";
    cout<<"   Terminate with '0'\n";
    cout<<size+1<<". ";
    getline(cin,test1[size].question,'0');
    cout<<"Enter answer:\n ";
    cout<<size+1<<". ";
    cin>>test1[size].answer;
     size++;
    system("CLS");
}
void displayquestions(test test1[],int* size)
{
    cout<<"Answer the following questions\n";
    for(int i=0;i<*size;i++)
    {
        cout<<i+1<<". "<<test1[i].question<<endl;
    }
    cout<<endl;
}
void exam(test test1[],const int* size)
{
    cout<<"Enter answer:\n";
    for(int i=0;i<*size;i++){
        cout<<i+1<<". ";
        cin>>test1[i].studentanswer;
    }
}
void result(test test1[],const int size,int result)
{
    for(int i=0;i<size;i++){
            if(test1[i].studentanswer==test1[i].answer){
            result++;
        }}
          cout<<"Your result is "<<result<<" out of "<<size;
            cout<<endl;
}
int main()
{
    int mark=0;
    test test1[100];
     int size=0,sum=0;
    bool quit=false;
    cout<<"Enter question and answer\n";
    addquestion(test1,size);
    while(!quit){
            cout<<"For the teacher\n";
        cout<<"Select an option:\n";
        cout<<"1. Add question and answer\n";
        cout<<"2. Finished\n";
        int option;
        cout<<"Your option is: ";
        cin>>option;
        cout<<endl;

        switch(option){
    case 1:
        addquestion(test1,size);
        break;
    case 2:
        quit=true;
        break;
    default:
        cout<<"Invalid option,\n";
        break;
        }
        cout<<endl;
    }
    cout<<endl;
    system("CLS");
            cout<<"For the student\n";
        nextstudent:
        displayquestions(test1,&size);
        cout<<endl;
        exam(test1,&size);
        cout<<endl;
        bool done=false;
        while(!done){
        cout<<"Select an option\n";
        cout<<"1. Check result\n";
        cout<<"2. For the next student\n";
        cout<<"3. Done\n";
        int option;
        cout<<"Your option is: ";
        cin>>option;
        switch(option)
        {
        case 1:
            result(test1,size,mark);
            break;
        case 2:
            system("CLS");
            goto nextstudent;
            break;
        case 3:
           done=true;
           break;
        }}

    cout<<endl;

    return 0;
}
