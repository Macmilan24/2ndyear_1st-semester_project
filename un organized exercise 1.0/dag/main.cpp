#include <iostream>

using namespace std;


int main()
{
struct logIn{
string user;
string password;

};
  string name;
  string pass;
   logIn user1;
   user1.user;
   user1.password;
cout<<"to register please enter your username and password"<<endl;
cin>>user1.user;
cin>>user1.password;
cout<<"you have registers succesfully"<<endl;
system("CLS");

 int r=3;

   cout << "to sign in please enter a user name"<<endl;
   failusername:
   cin>>  name;
   if(name==user1.user){
    cout<<"enter a password"<<endl;
    failpassword:
    cin >> pass;
    if(pass==user1.password){
        cout <<"Welcome user";
    }
    else{
            r--;

        cout<<"wrong password"<<endl;
        cout<<"TRY AGAIN!! "<<endl;

        if(r==0)
        {
            cout<<"too many retries";
            exit(1);
        }
        goto failpassword;
    }
   }
   else{
    cout<<"wrong username "<<endl;
    cout<<"TRY AGAIN!! "<<endl;
    goto failusername;
   }


cout<<"retry later";

    return 0;
}
