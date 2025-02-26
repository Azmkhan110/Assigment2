#include "Deque.h"
#include <limits>

using namespace std;

void showMenu() {
    cout << "\nBank Customer Service Queue:\n"
         << "1. Add Priority Customer\n"
         << "2. Add Regular Customer\n"
         << "3. Serve Next Priority\n"
         << "4. Serve Last Customer\n"
         << "5. Check Queue Status\n"
         << "6. Show Customer Count\n"
         << "7. Display Full Queue\n"
         << "8. Exit\n"
         << "Enter choice: ";
}
int main() {
    Deque serviceQueue;
    int choice, customerID;

    do {
        showMenu();
        if(!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        try {
            switch(choice) {
                case 1:
                    cout << "Enter priority customer ID: ";
                    if(!(cin >> customerID)) throw invalid_argument("Invalid ID");
                    serviceQueue.pushLeft(customerID);
                    cout << "Priority customer " << customerID << " added.\n";
                    break;

                case 2:
                    cout << "Enter regular customer ID: ";
                    if(!(cin >> customerID)) throw invalid_argument("Invalid ID");
                    serviceQueue.pushRight(customerID);
                    cout << "Regular customer " << customerID << " added.\n";
                    break;

                case 3:
                    if(serviceQueue.isEmpty()) {
                        cout << "Queue is empty!\n";
                    } else {
                        customerID = serviceQueue.popLeft();
                        cout << "Serving priority customer: " << customerID << endl;
                    }
                    break;

                case 4:
                    if(serviceQueue.isEmpty()) {
                        cout << "Queue is empty!\n";
                    } else {
                        customerID = serviceQueue.popRight();
                        cout << "Serving last customer: " << customerID << endl;
                    }
                    break;

                case 5:
                    cout << "Queue is " << (serviceQueue.isEmpty() ? "empty" : "active") << endl;
                    break;

                case 6:
                    cout << "Customers waiting: " << serviceQueue.size() << endl;
                    break;

                case 7:
                    if(serviceQueue.isEmpty()) {
                        cout << "Queue is empty!\n";
                    } else {
                        serviceQueue.display();
                    }
                    break;

                case 8:
                    cout << "Closing service system...\n";
                    break;

                default:
                    cout << "Invalid choice! Please enter a number between 1 and 8.\n";
            }
        } catch(const exception& e) {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while(choice != 8);

    return 0;
}