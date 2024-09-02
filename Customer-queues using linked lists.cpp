#include <iostream>
#include <string>

using namespace std;

class Request {
public:
    string description;
    Request* next;

    Request(const string& desc) : description(desc), next(nullptr) {}
};

class RequestQueue {
    Request* front;
    Request* rear;
public:
    RequestQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void addRequest(const string& desc) {
        Request* newRequest = new Request(desc);
        if (!newRequest) {
            cout << "\nMemory Allocation Failed";
            return;
        }
        if (isEmpty()) {
            front = rear = newRequest;
        } else {
            rear->next = newRequest;
            rear = newRequest;
        }
        cout << "\nRequest added: " << desc;
    }

    void processRequest() {
        if (isEmpty()) {
            cout << "\nNo requests to process";
        } else {
            Request* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            cout << "\nProcessing request: " << temp->description;
            delete temp;
        }
    }

    string peekRequest() const {
        if (!isEmpty())
            return front->description;
        else
            return "No requests available";
    }

    void displayRequests() const {
        if (isEmpty()) {
            cout << "\nNo requests to display";
            return;
        }

        Request* current = front;
        cout << "\nCurrent requests in the queue:\n";
        while (current) {
            cout << "- " << current->description << endl;
            current = current->next;
        }
    }

    ~RequestQueue() {
        while (!isEmpty()) {
            processRequest(); 
        }
    }
};

int main() {
    RequestQueue requestQueue;
    int choice;
    string desc;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Request\n";
        cout << "2. Process Request\n";
        cout << "3. View Front Request\n";
        cout << "4. Display All Requests\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter request description: ";
                getline(cin, desc);
                requestQueue.addRequest(desc);
                break;
            case 2:
                requestQueue.processRequest();
                break;
            case 3:
                cout << "Front request is: " << requestQueue.peekRequest() << endl;
                break;
            case 4:
                requestQueue.displayRequests();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
