#include <iostream>
using namespace std;
// Define the structure for a Node
struct Node {
    int data;
    Node* next;
};

// Define the LinkedList class
class LinkedList {
private:
    Node* head; // Pointer to the head (first) node of the list

public:
    // Constructor to initialize the linked list
    LinkedList() {
        head = nullptr; // Initialize the head as nullptr (empty list)
    }

    // Function to add a new node at the beginning of the list (prepend)
    void prepend(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head; // Set the next pointer of the new node to the current head
        head = newNode; // Update the head to point to the new node
    }

    // Function to add a new node at the end of the list
    void append(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            // Otherwise, traverse to the end and add the new node there
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
     // Function to add a new node after a specific element in the list
    void insertAfter( int newValue , int existingValue) {
        Node* newNode = new Node;
        newNode->data = newValue;
        newNode->next = nullptr;

        Node* current = head;

        // Find the node with the existing value
        while (current != nullptr && current->data != existingValue) {
            current = current->next;
        }

        if (current != nullptr) {
            // Insert the new node after the found node
            newNode->next = current->next;
            current->next = newNode;
        } else {
            // The existing value was not found in the list
            //std::cout << "Element " << existingValue << " not found in the list." << std::endl;
        }
    }
     // Function to add a new node before a specific element in the list
    void insertBefore( int newValue, int existingValue) {
        Node* newNode = new Node;
        newNode->data = newValue;
        newNode->next = nullptr;

        if (head == nullptr) {
            // If the list is empty, insert the new node as the head
            head = newNode;
            return;
        }

        // If the existing element is the head, update the head
        if (head->data == existingValue) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;

        // Find the node with the existing value
        while (current->next != nullptr && current->next->data != existingValue) {
            current = current->next;
        }

        if (current->next != nullptr) {
            // Insert the new node before the found node
            newNode->next = current->next;
            current->next = newNode;
        } else {
            // The existing value was not found in the list
            //std::cout << "Element " << existingValue << " not found in the list." << std::endl;
        }
    }
    // Function to print the elements of the list
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
     // Function to remove a specific element from the list
    void remove(int value) {
        if (head == nullptr) {
            // If the list is empty, nothing to remove
            //std::cout << "List is empty. Cannot remove." << std::endl;
            return;
        }

        // If the element to be removed is the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        // Find the node with the specified value
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current != nullptr) {
            // Remove the node with the specified value
            previous->next = current->next;
            delete current;
        } else {
            // The element was not found in the list
            //std::cout << "Element " << value << " not found in the list." << std::endl;
        }
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;  // Store the next node
            current->next = prev;  // Reverse the current node's next pointer
            prev = current;        // Move prev to current
            current = next;        // Move current to next
        }

        head = prev;  // Update the head to the last node (new first node)
    }

    // Function to search for an element in the list
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true; // Element found
            }
            current = current->next;
        }
        return false; // Element not found
    }
};

int main() {
    LinkedList myList;

    int n ; // số phần tử ban đầu của linkedList
    cin >> n;
    
    for(int i = 0 ; i< n; i++){
        int v;
        cin >> v;
        if(!myList.search(v)) myList.append(v);
    }
    string s;
    while (cin>> s) {
        if (s == "addlast"){ // thêm một phần tử vào cuối danh sách
            int k; 
            cin >> k;
            if(!myList.search(k)) myList.append(k); // kiểm tra không có phần tử k trong danh sách thì thêm vào
        }
        else if (s == "addfirst"){ // thêm một phần tử vào đầu danh sách
            int k;
            cin >> k;
            if(!myList.search(k)) myList.prepend(k); // kiểm tra không có phần tử k trong danh sách thì thêm vào
        }
        else if (s == "addafter"){
            int u , v ;
            cin >> u >> v ;
            if (myList.search(v) && !myList.search(u)) myList.insertAfter(u,v); //v đã tồn tại , u chưa tồn tại thì mới add
        }
        else if (s == "addbefore"){
            int u , v ;
            cin >> u >> v ;
            if (myList.search(v) && !myList.search(u)) myList.insertBefore(u, v); //v đã tồn tại , u chưa tồn tại thì mới add
        }else if (s == "remove") { // xoá phần tử có giá trị k khỏi danh sách
            int k;
            cin >> k;
            if(myList.search(k)) myList.remove(k); 
        } else if (s == "reverse"){
            myList.reverse();
        }
        else if (s == "print") myList.print();
        else if ( s =="#") break;
    }
    // Print the list
    myList.print();

    return 0;
}
