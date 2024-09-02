Overview
This C++ program implements a queue-based request management system using a linked list. It allows users to manage a queue of requests with functionalities to add, process, and view requests. The queue follows the First In, First Out (FIFO) principle.

Features
Add Request: Add a new request to the end of the queue.
Process Request: Process (remove) the request at the front of the queue.
View Front Request: View the description of the request currently at the front of the queue without removing it.
Display All Requests: Display all requests in the queue from front to back.
Exit Program: Exit the application.

Request Class
Purpose: Represents an individual request.
Attributes:
string description: Description of the request.
Request* next: Pointer to the next request in the queue.

Constructor:
Request(const string& desc): Initializes the request with a description and sets next to nullptr.

RequestQueue Class
Purpose: Manages a queue of Request objects.
Attributes:
Request* front: Pointer to the front of the queue.
Request* rear: Pointer to the rear of the queue.

Methods:
RequestQueue(): Constructor that initializes front and rear to nullptr.
bool isEmpty() const: Checks if the queue is empty.
void addRequest(const string& desc): Adds a new request to the end of the queue.
void processRequest(): Processes and removes the request at the front of the queue.
string peekRequest() const: Returns the description of the request at the front of the queue without removing it.
void displayRequests() const: Displays all requests in the queue from front to back.
~RequestQueue(): Destructor that processes and deletes all requests to free memory.

Main Function
The main function provides a menu-driven interface for users to interact with the RequestQueue:

Add Request: Prompts for a description and adds it to the queue.
Process Request: Removes and processes the request at the front of the queue.
View Front Request: Displays the request description at the front of the queue.
Display All Requests: Lists all requests in the queue.
Exit: Exits the program.

Menu:
1. Add Request
2. Process Request
3. View Front Request
4. Display All Requests
5. Exit

Enter your choice: 1

Enter request description: Request 1

Request added: Request 1

Menu:
1. Add Request
2. Process Request
3. View Front Request
4. Display All Requests
5. Exit
Enter your choice: 3

Front request is: Request 1

Menu:
1. Add Request
2. Process Request
3. View Front Request
4. Display All Requests
5. Exit
   
Enter your choice: 4

Current requests in the queue:Request 1

Menu:
1. Add Request
2. Process Request
3. View Front Request
4. Display All Requests
5. Exit

Enter your choice: 2

Processing request: Request 1

Menu:
1. Add Request
2. Process Request
3. View Front Request
4. Display All Requests
5. Exit

Enter your choice: 5

Exiting program.

Memory Management
The program dynamically allocates memory for each request and ensures that all memory is properly freed when the RequestQueue object is destroyed. This prevents memory leaks.

License
This program is provided under the MIT License. See the LICENSE file for more details.

Feel free to adjust the description according to your specific needs or project details.
