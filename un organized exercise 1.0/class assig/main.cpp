#include <iostream>

using namespace std;
void  PrintDate(int, int, int);
int main()
{
    int num1, num2, num3;
    cout<< "enter month number"<<endl;
    cin>>num1;
    cout<<"enter day number"<<endl;
    cin >>num2;
    cout << "enter year"<<endl;
    cin >> num3;

    PrintDate(num1, num2, num3);

    return 0;
}
void  PrintDate(int x,int y, int z){

switch(x){
case 1:
    cout <<"jan"<<","<<y<<","<<z;
    break;
case 2:
    cout<<"Feb"<<","<<y<<","<<z;
     break;
case 3:
    cout<<"mar"<<","<<y<<","<<z;
     break;
    case 4:
        cout<<"apr"<<","<<y<<","<<z;
         break;
    case 5:
        cout<<"may"<<","<<y<<","<<z;
         break;
    case 6:
        cout<<"jun"<<","<<y<<","<<z;
         break;
    case 7:
        cout<<"july"<<","<<y<<","<<z;
         break;
    case 8:
        cout<<"aug"<<","<<y<<","<<z;
         break;
    case 9:
        cout<<"sept"<<","<<y<<","<<z;
             break;
    case 10:
        cout<<"oct"<<","<<y<<","<<z;
         break;
    case 11:
        cout<<"nov"<<","<<y<<","<<z;
         break;
    case 12:
        cout<<"dec"<<","<<y<<","<<z;
         break;
    default:
        cout << "invalid number";

}
}
