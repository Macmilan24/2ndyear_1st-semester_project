#include <iostream>

using namespace std;
int Max (int , int  );
int main()
{
    int num1, num2;
    cout<< "enter a number"<<endl;
    cin>> num1;
    cout<<"enter another number"<<endl;
    cin>> num2;
    cout<< "the largest number is "<< Max (num1,num2);
    return 0;
}
int Max (int x , int y)
{
    int Max =(x>y) ? x : y;
   return Max;
     }


