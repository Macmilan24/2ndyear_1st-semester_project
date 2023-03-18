#include <iostream>

using namespace std;

int main()
{

   int balance=10;
   int option;
   cout<<"1. 1000 birr : 10 GB"<<endl;
   cout<<"2. 7 birr : 3 Mb " <<endl;
   cin>>option;
   switch (option){
   case 1:
       cout<<"you can not afford"<<endl;
       break;
   case 2:
    cout<< "purchase successful "<<endl;
    cout << balance-7<<" birr remaining"<<endl;
    break;
   default:
    cout<<"invalid input"<<endl;
   }
    return 0;

}
