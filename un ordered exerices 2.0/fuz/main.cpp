#include <iostream>

using namespace std;

int main()
{
    int i;
    for (int i=1; i<=20; i++){
         if (i%3==0 && i%5==0){
            cout << "Fuzz Buzz !!"<<endl;
        }else if (i%5==0){
            cout<< "Buzz !!"<<endl;
        }else if (i%3==0){
            cout << "Fuzz !!"<<endl;
        }else {
            cout<<i<<endl;
        }
    }
    return 0;
}
