#include <iostream>

using namespace std;
static string nam[ ]={"abebe", "tewabech", "messi", "lebron", "cardi"};
string& name(int  i){
//static string nam[ ]={"abebe", "tewabech", "Christiano", "lebron", "Gigi"};
return nam[ i ];
}

int main()
{
//string nam[ ]={"abebe", "tewabech", "messi", "lebron", "cardi"};
    cout<< "names before change:"<<endl;
    for (int i=0; i<5; i++){
        cout<< "Name [ "<< i <<" ] =";
        cout <<nam[i]<<endl;
    }
    name(2)="Christiano ";
    name(4)="Gigi";
     cout<< "names after change:"<<endl;
    for (int i=0; i<5; i++){
        cout<< "Name [ "<< i <<" ] =";
        cout <<nam[i]<<endl;
    }

    return 0;
}
