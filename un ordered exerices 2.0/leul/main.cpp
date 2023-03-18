#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student {
        string name;
        int age;
        string address;
        int grade;
    };
vector<Student> students;
void registerStudent() {
    Student student;
        cout << "Enter student name: ";
        cin >> student.name;
        cout << "Enter student age: ";
        cin >> student.age;
        cout << "Enter student address: ";
        cin >> student.address;
        cout << "Enter student grade: ";
        cin >> student.grade;
        students.push_back(student);
        cout << "Student registered successfully!" << endl;
                         }
void printRegisteredStudents() {
            if (students.size() == 0) {
                cout << "No one is registered." << endl;
        } else {
                cout << "Registered students:" << endl;
                }
       for (Student student : students) {
                cout << student.name << ", " << student.age << ", " << student.address << ", " << student.grade<<endl;
    }
}
int main (){
    int input;
    int option;
    returnto:
          cout << "To register enter 1"<<endl;
          cout<< "To see registered student enter  2"<<endl;
          cin>> input;
          system("cls");
          if (input== 1){
             registerStudent();
             cout <<"Do you want to go to the main menu if so press 1"<<endl;
             cout << "If not press 2"<<endl;
             cin >> option;
             if (option == 1){
              system("cls");
             goto returnto;
             }else if (option == 2){
             return 0;
             }else{
             cout << "invalid input terminating now"<<endl;
             return 0;
             }
          } else if(input == 2){
          printRegisteredStudents();
           cout <<"Do you wnat to go to the main menu if so press 1"<<endl;
           cout<<"If not press 2"<<endl;
             cin >> option;
             if (option == 1){
             system("cls");
             goto returnto;
             }else if (option == 2){
             return 0;
             }else{
             cout << "invalid input terminating now"<<endl;
             return 0;
             }
          }else {
          cout << "you have entered an invalid input"<<endl;
          }

}
