#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct User {
    string username;
    string password;
};

struct Gig {
    string title;
    string category;
    string description;
    float price;
};

// Function to create a new user
void createUser();

// Function to create a new gig
void createGig();

// Function to search for gigs based on a keyword
void searchGig();

// Function to purchase a gig
void purchaseGig();

// Main function
int main() {
    // Define variables and arrays
    int choice;
    int numUsers = 0;
    int numGigs = 0;

    // Loop until the user chooses to exit
    do {
        // Display menu options
        cout << "1. Create User" << endl;
        cout << "2. Create Gig" << endl;
        cout << "3. Search Gigs" << endl;
        cout << "4. Purchase Gig" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";

        // Get user choice
        cin >> choice;

        // Perform action based on user choice
        switch(choice) {
            case 1:
                // Create new user
                createUser();
                numUsers++;
                break;
            case 2:
                // Create new gig
                createGig();
                numGigs++;
                break;
            case 3:
                // Search for gigs
              searchGig();
                break;
            case 4:
                // Purchase a gig
                purchaseGig();
                break;
            case 5:
                // Exit
                cout << "Goodbye!" << endl;
                break;
            default:
                // Invalid choice
                cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new user
void createUser() {
    // Get username and password from user
    User users;
    cout << "Enter username: ";
    cin >> users.username;
   // cin.ignore();
    cout << "Enter password: ";
    cin >> users.password;
return;
}
void createGig() {
    Gig gig;

    // Get gig details from user
    cout << "Enter gig title: ";
    cin.ignore();
    getline(cin, gig.title);

    cout << "Enter gig category: ";
    getline(cin, gig.category);

    cout << "Enter gig price: ";
    cin >> gig.price;

    cout << "Enter gig description: ";
    cin.ignore();
    getline(cin, gig.description);

    // Open file for writing gigs
    ofstream outGigsFile("gigs.txt", ios::app);

    if (!outGigsFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Write gig information to file
    outGigsFile << gig.title << "\n" << gig.category << "\n" << gig.price << "\n" << gig.description << endl;

    // Close the file
    outGigsFile.close();

    cout << "Gig created successfully!" << endl;
}
void searchGig() {
    string category;
    cout << "Enter category to search for: ";
    getline(cin, category);

    ifstream gigFile("gigs.txt");
    Gig gig;
    bool found = false;

    while (gigFile >> gig.title >> gig.category >> gig.price >> gig.description) {
        getline(gigFile, gig.description);

        if (gig.category == category) {
            found = true;
            cout << "Title: " << gig.title << endl;
            cout << "Category: " << gig.category << endl;
            cout << "Description: " << gig.description << endl;
            cout << "Price: " << gig.price << endl;
            cout << endl;
        }
    }

    if (!found) {
        cout << "No gigs found in the " << category << " category." << endl;
    }
    gigFile.close();
}
void purchaseGig() {
    string title;
    cout << "Enter gig title to purchase: ";
    getline(cin, title);

    ifstream gigFile("gigs.txt");
    Gig gig;
    bool found = false;

    while (gigFile >> gig.title >> gig.category >> gig.price) {
        getline(gigFile, gig.description);

        if (gig.title == title) {
            found = true;
            cout << "Title: " << gig.title << endl;
            cout << "Category: " << gig.category << endl;
            cout << "Price: " << gig.price << endl;
            cout << "Description: " << gig.description << endl;

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

    if (!found) {
        cout << "No gig with title \"" << title << "\" found." << endl;
    }

    gigFile.close();
}
