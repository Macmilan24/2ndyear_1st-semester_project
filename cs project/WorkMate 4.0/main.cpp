#include <iostream>
#include <fstream>
#include<ctime>
#include <Windows.h>
using namespace std;

struct User  {
    string username;
    string password;
};

struct  Gig{

    string name;
    string skill;
    string field;
    double pph;
};

struct  Job{
		string name;
		string skill;
		int quant;
		string description;
		string email;
};
string g_username;
// All function prototype
void mainmenu();
void createAccount();
void Regasfree();
void Regasclient();
void login();
void loginasclient();
void loginasfreelancer();
void clientpage();
void freelancerpage();
void dashboard();
void neworder();
void gig();
void searchgig();

int main()
{
    int option;
	cout << "\n\t \t ----------#                                #----------\n"
	        "  \t \t \t           Welcome To Work Mate   \n"
			"  \t \t ----------#                                #----------\n\n";
return0:
    cout << "\n  1 : Login\n "
               " 2 : Create New Account\n "
			   " 3 : Quit\n\n"
			   "Enter Your Choice: ";
    cin>>option;
    switch(option)
   	{
   	   case 1:
   	         Sleep(300);
   	      system("cls");
// Redirect to login function
   	       login();
   	       break;
       case 2:
// wait for some seconds before clearing the page
           Sleep(300);
           system("cls");

// Redirect to createAccount function
           createAccount();
           break;
       case 3:
           exit(0);
       default:
           cout << "Invalid Option"<<endl;
           goto return0;
   }

}

void createAccount()
{
   int option;
   cout << "\n \t \t ----------#                               #----------\n"
	        "  \t \t ----------#         Register Form         #----------\n"
			"  \t \t ----------#                               #----------\n\n";
 return4:
   cout << "\n   1 -> Register as a Client\n"
           "   2 -> Register as a Freelancer\n"
           "   3 -> Quit\n\n"
           "Enter Your Choice: ";
    cin>>option;
    switch(option)
    {
    	case 1:
    	    Sleep(300);
    	   system("cls");
    	   Regasclient();
    	   break;
        case 2:
            Sleep(300);
           system("cls");
           Regasfree();
           break;
        case 3:
           exit(0);
        default:
           cout << "Invalid Option please try again"<<endl;
           goto return4;
    }
}

void Regasclient()
{
 User client;
    // Get user input for username and password
    cout << "\n \t \t ----------#                                  #----------\n"
	        "   \t \t        Welcome to our client registration page\n"
			"   \t \t ----------#                                  #----------\n\n";
    return7:
    cout << "Enter username: ";
    cin >> client.username;

    // check if the user name is unique
    string line;
    bool validCredentials = false;

    ifstream file("dataoffree.txt");

    // Check if the file was successfully opened
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        exit(0);
    }

    // Check if the username is unique
    while (getline(file, line)) {
        // Split each line into username
        size_t pos = line.find("|");
        string fileUsername = line.substr(0, pos);
        if (client.username == fileUsername) {
            validCredentials = true;
            break;
        }
    }

    // Print message based on validity of credentials
    if (validCredentials) {
        cout << "Similar username found please try another one :-)" << endl;
     goto return7;
    }

    // Close the file
    file.close();

    cout << "Enter password: ";
    cin >> client.password;
    if (client.password.size() < 8){
        cout << "you have entered an invalid number of password please try again\n\n";
        goto return7;
    }
    // Open file for writing
    ofstream outfile("dataofclient.txt", ios::app);

    // Write user data to file
    outfile << client.username << "|" << client.password << endl;


    // Close file
    outfile.close();
    cout << "You have registered successfully!!!\n";
    Sleep(300);
    system("cls");

    login();

}


void Regasfree()
{
	User free;
    // Get user input for username and password
    cout << "\n \t \t ----------#                                  #----------\n"
	        "   \t \t      Welcome to our Freelancer registration page\n  "
			"   \t \t ----------#                                  #----------\n\n";
			cout << "To be registered as Freelancer please\n";
    return7:
    cout << "Enter username: ";
    cin >> free.username;
    // check if the user name is unique
    string line;
    bool validCredentials = false;

    ifstream file("dataoffree.txt");

    // Check if the file was successfully opened
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        exit(0);
    }

    // Check if the username and password are correct
    while (getline(file, line)) {
        // Split each line into username and password
        size_t pos = line.find("|");
        string fileUsername = line.substr(0, pos);
        if (free.username == fileUsername) {
            validCredentials = true;
            break;
        }
    }

    // Print message based on validity of credentials
    if (validCredentials) {
        cout << "Similar username found please try another one :-)" << endl;
     goto return7;
    }

    // Close the file
    file.close();

    cout << "Enter password: ";
    cin >> free.password;

     if (free.password.size() < 8){
        cout << "you have entered an invalid number of password please try again with an eight digit password\n\n";
        goto return7;
    }

    // Open file for writing
    ofstream outfile("dataoffree.txt", ios::app);

    // Write user data to file
    outfile << free.username << "|" << free.password  << endl;

    // Close file
    outfile.close();
    cout << "You have registered successfully!!!\n";
    Sleep(300);
    system("cls");
    login();
}


void login()
{
	int option;
	cout << "\n \t \t ----------#                                  #----------\n"
	        "   \t \t ----------#     Welcome to Login Page !!     #----------\n"
			"   \t \t ----------#                                  #----------\n\n";
	return2:
	cout << "\n 1 : Login as Client\n "
               "2 : Login as Freelancer\n "
               "3: To the previous page\n"
			   "4 : Quit\n\n"
			   "Enter Your Choice: ";
    cin>>option;
    switch(option)
    {
    	case 1:
	       system("cls");
    	   loginasclient();
    	   break;
        case 2:
           system("cls");
           loginasfreelancer();
           break;
        case 3:
            system("cls");
            main();
        case 4:
           exit(0);
        default:
           cout << "Invalid Option please try again"<<endl;
           goto return2;
    }
}

void loginasclient()
{
	string username, password, line;
    bool validCredentials = false;
    cout << "\n \t \t ----------#                           #----------\n"
	        "   \t \t ----------#       Login As Client     #----------\n"
			"   \t \t ----------#                           #----------\n\n";
 return1:
    ifstream file("dataofclient.txt");

    // Check if the file was successfully opened
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        exit(0);
    }

    // Get user input for username and password

    cout << "Enter your username: ";
    cin >> username;
    string* ptr0;
    ptr0 = &username;
    cout << "Enter your password: ";
    cin>>password;
    string* ptr1;
    ptr1 = &password;

    // Check if the username and password are correct
    while (getline(file, line)) {
        // Split each line into username and password
        size_t pos = line.find("|");
        string fileUsername = line.substr(0, pos);
        string filePassword = line.substr(pos+1);

        if (*ptr0 == fileUsername && *ptr1 == filePassword) {
            validCredentials = true;
            break;
        }
    }

    // Print message based on validity of credentials
    if (validCredentials) {
        cout << "Login successful!" << endl;
        Sleep(300);
        system("cls");
        clientpage();

    } else {
        cout << "Invalid username or password." << endl;
        goto return1;
    }

    // Close the file
    file.close();
}

void loginasfreelancer()
{
	string username, password, line;
    bool validCredentials = false;
    cout << "\n \t \t ----------#                                #----------\n"
	        "   \t \t ----------#       Login As Freelancer      #----------\n"
			"   \t \t ----------#                                #----------\n\n";
   return3:
    ifstream file("dataoffree.txt");

    // Check if the file was successfully opened
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        exit(0);
    }

    // Get user input for username and password

    cout << "Enter your username: ";
    cin>>username;
    cout << "Enter your password: ";
    cin>>password;

    // Check if the username and password are correct
    while (getline(file, line)) {
        // Split each line into username and password
        size_t pos = line.find("|");
        string fileUsername = line.substr(0, pos);
        string filePassword = line.substr(pos+1);

        if (username == fileUsername && password == filePassword) {
            validCredentials = true;
            break;
        }
    }

    // Print message based on validity of credentials
    if (validCredentials) {
        cout << "Login successful!" << endl;
        system("cls");
        g_username = username;
        freelancerpage();
    } else {
        cout << "Invalid username or password. please try again" << endl;
        goto return3;
    }

    // Close the file
    file.close();

}

void freelancerpage()
{
	int apply;
    cout << "\n \t \t ----------#                                     #----------\n"
	        "   \t \t ----------#           Hello! Freelancer         #----------\n"
			"   \t \t ----------#                                     #----------\n\n";
	return5:
	cout << "\n 1 : To Create Gig\n"
            " 2 : To access dashboard\n"
            " 3: To the previous page\n"
            " 4 : Quit\n"
			"Enter Your Choice: ";
    cin >> apply;
    switch(apply)
    {
    	case 1:
    	   system("cls");
    	   gig();
    	   break;
        case 2:
            system("cls");
            dashboard();
            break;
        case 3:
            system("cls");
            login();
            break;
        case 4:
           exit(0);
        default:
           cout << "Invalid Option"<<endl;
           goto return5;
    }
}

void clientpage()
{
	int option;
	cout << "\n \t \t ----------#                                  #----------\n"
	        "   \t \t ----------#           Hello! Client          #----------\n"
			"   \t \t ----------#                                  #----------\n\n";
return6:

    cout << "\n 1 -> Search Gigs\n "
               "2 -> To the previous page\n"
			   "3 -> Quit\n\n"
			   "Enter Your Choice: ";

	cin >> option;
	switch(option)
    {
        case 1:
           system("cls");
           searchgig();
           break;
        case 2:
            system("cls");
            login();
            break;
        case 3:
           exit(0);
        default:
           cout << "Invalid Option"<<endl;
           system("cls");
           goto return6;

    }

}


void neworder()
{
Job norder;
	time_t now;
	time (&now);
	string time = asctime(localtime(&now));
	cout << "\n\n U Can Order A Service By Filling The Form. Thank You! \n\n";

	cout << "Enter gig name: ";
	getline(cin, norder.name);
	cin.ignore();
	cout << "Skill: ";
	getline(cin, norder.skill);
	cout << "Quantity: ";
    cin >> norder.quant;
	cout << "Describtion: ";
	cin.ignore();
	getline(cin, norder.description);
	cout << "Enter you email address: ";
	cin.ignore();
	getline(cin, norder.email);

	// Open file for writing
    ofstream outfile("order.txt", ios::app);

    // Write user data to file
    outfile << norder.name << " | " << norder.skill  << " | " << norder.quant << " | " << norder.description <<"|"<< norder.email << " | " << time << endl;

    // Close file
    outfile.close();
    cout << "\n \t !!!!!!  Ur Order Created Successfully !!!!!!\n";
    system("cls");
}


void gig()
{
    Gig gig;
	cout << "Enter Your userame: ";
	cin.ignore();
	getline(cin, gig.name);
	cout << "Enter Your Field: ";
	getline(cin, gig.field);
	cout << "Enter Your Skill: ";
	getline(cin, gig.skill);
	cout << "Enter Price Per Hour: $ ";
	cin >> gig.pph;

	// Open file for writing
    ofstream outfile("profile.txt", ios::app);

    // Write user data to file
    outfile << gig.name << "|" << gig.field << "|" << gig.skill << "|" << gig.pph << endl;


    // Close file
    outfile.close();
int c;
	cout << "\n\n1: To return to previous page\n "
	               "2: To exit\n";
    cin >> c;
    if (c == 1){
            system("cls");
	freelancerpage();
    }else {
    return ;
    }
}

void dashboard()
{
    string filename = "order.txt";

	cout << "List Of Created Orders \n\n";
	cout << "|  name |  skill  |  quantity  |  description   | Email |  Date  | \n";

	ifstream file("order.txt");
	string line;
	while (getline(file, line)) {
		if (line.find(g_username) != string::npos) {
			cout << line << endl;
		}

	}
	file.close();
int c;
	cout << "\n\n1: To return to previous page\n "
	               "2: To exit\n";
    cin >> c;
    if (c == 1){
            system("cls");
	freelancerpage();
    }else {
    return ;
    }
}

void searchgig()
{
	string filename = "profile.txt";
	string search_term ;

	ifstream file("profile.txt");
	string line;

	cout << "Search by skill: ";
	cin >> search_term;
	cout << "\n";
	cout << "|  User name  |  Field  |  skill  |  cost per-hour($)  | \n\n";
	while (getline(file, line)) {
		if (line.find(search_term) != string::npos) {
			cout << line << endl;
		}

	}
	file.close();
	neworder();
int c;
	cout << "\n\n1: To return to previous page\n "
	               "2: To exit\n";
    cin >> c;
    if (c == 1){
            system("cls");
	clientpage();
    }else {
    return ;
    }
}
