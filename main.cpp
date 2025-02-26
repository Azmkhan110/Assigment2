#include "Deque.h"
#include <limits>

using namespace std;

void showMenu() {
    cout << "\nBank Customer Service Queue:\n"
         << "1. Add Priority Customer\n"  // Adds a customer to the front
         << "2. Add Regular Customer\n"   // Adds a customer to the back
         << "3. Serve Next Priority\n"    // Removes a customer from the front
         << "4. Serve Last Customer\n"    // Removes a customer from the back
         << "5. Check Queue Status\n"     // Checks if queue is empty or active
         << "6. Show Customer Count\n"    // Shows how many customers are waiting
         << "7. Display Full Queue\n"     // Displays all customers in the queue
         << "8. Exit\n"                   // Ends the program

         << "Enter choice: ";
}

int main() {
    Deque serviceQueue; // Create an empty queue to store customers
    int choice, customerID;

    do {
        showMenu(); // Show the menu options
        cin >> choice; // Get user choice

        try {
            switch(choice) {
                case 1:
                    cout << "Enter priority customer ID: ";
                    if(!(cin >> customerID)) throw invalid_argument("Invalid ID");   // If input is wrong like not a number it will show an error
                    serviceQueue.pushLeft(customerID); // Add customer to front
                    break;

                case 2:
                    cout << "Enter regular customer ID: ";
                    if(!(cin >> customerID)) throw invalid_argument("Invalid ID"); // If input is wrong, show an error
                    serviceQueue.pushRight(customerID); // Add customer to back
                    break;

                case 3:
                    cout << "Serving priority customer: "
                << serviceQueue.popLeft() << endl; // Remove customer from front
                break;

                case 4:
                    cout << "Serving last customer: "
                         << serviceQueue.popRight() << endl; // Remove customer from back
                break;

                case 5:
                    cout << "Queue is "
                         << (serviceQueue.isEmpty() ? "empty" : "active") << endl; // Check if queue has customers
                break;

                case 6:
                    cout << "Customers waiting: "
                         << serviceQueue.size() << endl; // Show number of customers
                break;

                case 7:
                    serviceQueue.display(); // Show all customers in queue
                break;

                case 8:
                    cout << "Closing service system...\n"; // End the program
                break;

                default:
                    cout << "Invalid choice!"; // If user enters a wrong option
            }
        } catch(const exception& e) {
            // Catch errors like wrong input and show a message
            cerr << "Error: " << e.what() << endl;
            cin.clear(); // Clear wrong input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while(choice != 8); // Keep running until the user chooses to exit

    return 0;
}