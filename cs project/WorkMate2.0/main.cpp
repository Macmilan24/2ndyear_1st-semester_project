#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
struct User {
    string username;
    string email;
    string password;
};

struct Gig {
    string title;
    string category;
    string description;
    float price;
};
//user and gig counter
    int numclient = 0;
    int numfreelancer = 0;
    int numGigs = 0;

// Function to create a new user
void createUser();

// Function to create a new gig
void createGig();

// Function to search for gigs based on a keyword
void searchGig();

// Function to purchase a gig
void OrderGig();

//Function for client page
void clientpage();

//Function for freelancer page
void freelancerpage();

//Function for login page
void login();

// Main function
int main() {
    int choice;

    // Loop until the user chooses to exit
    do {
        // Display menu options
        cout << "1. Create User" << endl;
        cout << "2. Log in"<<endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";

        // Get user choice
        cin >> choice;
system("cls");
        // Perform action based on user choice
        switch(choice) {
            case 1:
                // Create new user
                createUser();
                break;
            case 2:
                // login page
               // login();
                break;
            case 3:
                // Exit
                cout << "Goodbye!" << endl;
                break;
            default:
                // Invalid choice
                cout << "Invalid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}

// Function to create a new user
void createUser() {
    User client;
    User freelancer;
    // Differentiate between client and freelancer
    int select;
    returnpoint:
    cout << "Welcome to our sign up page, please select form the given alternatives: "<< endl;
    cout << "\n 1: Register as a client \n";
    cout << "\n 2: Register as a freelancer\n";
    cin >> select;
    system("cls");
    switch (select)
    {
    case 1:
        //Get client name
        cout << "To be registered as a client please enter your name: ";
        cin.ignore();
        getline(cin, client.username);

        //Get client email
       cout << "Please enter your email address: ";
        getline(cin,  client.email);
       // cin.ignore();

       recovpass:
        cout << "please enter your password : ";
       cin >> client.password;
         //Check if the password is valid
       if (client.password.size() >= 8){
             cout << "Registered successfully! \n";
            numclient++;
            system("pause");
            system("cls");
            clientpage();
      }
        else{
          cout << "you have entered an invalid password please try again:\n ";
            goto recovpass;
        }
        break;
    case 2:
         //Get client name
       cout << "To be registered as a Freelancer please enter your name: ";
        cin.ignore();
        getline(cin, freelancer.username);

        //Get client email
        cout << "Please enter your email address: ";
        getline(cin, freelancer.email);

        // Get client email
        recovpass1:
        cout << "please enter your password : ";
        cin >> freelancer.password;
        // Check if the password is valid
        if (freelancer.password.size()>= 8){
             cout << "Registered successfully! \n";
            numfreelancer++;
            system("pause");
            system("cls");
            freelancerpage();
        }
        else{
           cout << "you have entered an invalid password please try again:\n ";
            goto recovpass1;
        }
        break;
    default:
        cout<< "you have entered an invalid number please try again \n";
        goto returnpoint;
    }

}
void freelancerpage(){
 int y;
    return3:
    cout << "Welcome to our freelancer page\n please select form the given alternatives: "<< endl;
    cout << "\n 1: To create gig  \n";
    cout << "\n 2: To access dashboard \n";
    cout << "\n 3: Exit to main page\n";
    cin >> y;
    system("cls");
    switch(y){
    case 1:
       createGig() ;
        goto return3;
        break;
    case 2:
        //Dashboard();
        break;
    case 3:
        break;
    default:
        cout<< "You have entered an invalid number please try again \n";
    goto return3;
    }
    return;
}
void clientpage(){
    int x;
    return2:
    cout << "Welcome to our client page\n please select form the given alternatives: "<< endl;
    cout << "\n 1: To search a gig  \n";
    cout << "\n 2: To order a gig \n";
     cout << "\n 3: Exit to main page\n";
    cin >> x;
    system("cls");
    switch(x){
case 1:
    searchGig();
    break;
case 2:
    OrderGig();
    break;
case 3:
    break;
default:
    cout<< "You have entered an invalid number please try again \n";
    goto return2;
    }
    return;
}
void createGig() {
static Gig gig;
    // Get gig details from user
    cout << "Enter gig title: ";
    cin.ignore();
    getline(cin, gig.title);

    cout << "Enter gig category: ";
    getline(cin, gig.category);
    static string* ptr = &gig.category;
    cout << "Enter gig price: ";
    cin >> gig.price;

    cout << "Enter gig description: ";
    cin.ignore();
    getline(cin, gig.description);

    // Open file for writing gigs
    ofstream outGigsFile("gigs.txt", ios::app);

    if (!outGigsFile) {
        cout << "Error opening file!" << endl;
    }

    // Write gig information to file
    outGigsFile << gig.title << ", " << gig.category << ", " << gig.price << ", " << gig.description << endl;

    // Close the file
    outGigsFile.close();

    cout << "Gig created successfully!" << endl;
    system("pause");
    system("cls");
}
void searchGig() {
 static Gig gig;
string C;
cout << "Enter a category to search for:\n";
cin >> C;

ifstream inFile("gigs.txt");
    string line;
bool found = false;
    while (inFile >> gig.title >> gig.category >> gig.price) {
            getline(inFile, gig.description);
        if (gig.category== C) {
            found = true;
            cout << "Title : " <<gig.title<< endl;
            cout << "category : " <<gig.category<< endl;
            cout << "Price : "<< gig.price<<endl;
            cout << "Description : "<<gig.description<< endl;

        }
    }

 if (!found) {
        cout << "No gigs found in the specified category." << endl;
    }
    inFile.close();
}
void OrderGig() {
    Gig gig;
    string line;
    string title;
    cout << "Enter gig title to purchase: ";
    cin.ignore();
    getline(cin, title);

    ifstream gigFile("gigs.txt");

    while (getline(gigFile, line)) {

        if (gig.title == title) {
          cout << line;

            string buyer;
            cout << "Enter your name: ";
            getline(cin, buyer);

            ofstream orderFile("orders.txt", ios::app);
            orderFile << gig.title << "," << gig.price << "," << buyer << endl;
            orderFile.close();

            cout << "Order placed successfully!" << endl;
            break;
        }
    }

    if (!gigFile) {
        cout << "No gig with title \"" << title << "\" found." << endl;
    }

    gigFile.close();
}
