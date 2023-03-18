#include <iostream>

using namespace std;

int main()
{
/*float arr [5];

cout<< "enter 5 numbers: ";
for (int i = 0; i< 5; ++i)
{
    cin>> * (arr + i);
}
  cout << "displaying data:" <<endl;



  for (int i = 0 ; i< 5; ++i){
    cout << *(arr + i )<<endl;
}*/
/*int sum=0;
float arr[5];
float * ptr = arr;
cout<< "write the number you want to add "<< endl;
for (int i=0; i<5; i++){
    cin >> arr[i];
}
for (int i=0; i<5; i++){
    sum += *ptr+i;
}
cout << "here are the sums "<<sum<<endl;*/
int n;
string arr[n];
string cont;
cout  << "enter the amount of arr"<<endl;
cin>> n;
for (int i=0; i<n; i++){
    cin >> arr[i];
}
for (int i=0; i<n; i++){
    cont+=arr[i];
}
string* ptr= &cont;
int length= sizeof(*ptr)/sizeof(string);
cout << "the length of you word is :"<< length<<endl;
   return 0;
}
