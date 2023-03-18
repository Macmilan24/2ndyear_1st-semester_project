#include <iostream>

using namespace std;

int main()
{
int num;
cout << "Enter total number of student : ";
cin >> num;
string name;
string* ptr;

ptr = new string[num];

cout << "Enter name of students. " << endl;
for (int i=0; i < num; ++i)
{
    cout << "student "<< i + 1 << ":";
    cin >> *(ptr +i);
}
cout << "\n Displaying the name of the student"<< endl;
for (int i= 0; i < num; ++i){
    cout << "student" << i + 1 << " :"<< *(ptr + i) << endl;
}
delete[ ] ptr;
    return 0;
}

