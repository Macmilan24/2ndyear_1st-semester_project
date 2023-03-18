#include <iostream>

using namespace std;
int factorial(int );
int main()
{
    int x;
    cout <<"Enter the number that you want factorial of "<<endl;
    cin >> x;
   cout<< factorial(x);
    return 0;
}
int factorial (int k){
if (k>0){
    return k * factorial(k-1);
}
else{
    return 1;
}
}
