#include <iostream>

using namespace std;
void names(int num, string* ptr, char letter)
{
    for (int i=0; i < num; i++){
        char* ptr1 = &ptr[i][0];
        if (*ptr1 == letter){
            cout <<  *(ptr+i)<<endl;
        }
    }
}
int main()
{
int num;
cout << "Enter total number of student : ";
cin >> num;
cin.ignore();


string* ptr;
ptr = new string[num];
char letter;


cout << "Enter name of students. " << endl;
for (int i=0; i < num; ++i)
{
    cout << "student "<< i + 1 << ":";
    getline(cin, *(ptr+1));
}

cout << "Enter the letter that you want to display\n";
cin >> letter;

names(num, ptr, letter);

delete[ ] ptr;
    return 0;
}

