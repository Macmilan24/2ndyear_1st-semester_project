#include<iostream>
using namespace std;
double pi=3.14;
void computeCircle (double r,double&  x, double&  y){
y= 2*pi*r;

x = r*r*pi;
};
int main(){
    double radius, area, circumference;
    cout << "enter radius of a circle"<<endl;
    cin>> radius;
computeCircle(radius, area, circumference) ;
cout << "The area is : "<<area<<endl;
cout << "The circmference is : "<<circumference<<endl;
return 0;
}
