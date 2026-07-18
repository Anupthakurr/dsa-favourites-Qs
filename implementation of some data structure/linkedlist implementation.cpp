#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

   int main()  {
    //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
   // cout << node1 -> next << endl;
    
    //head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    //print(head);

    insertAtTail(tail, 12);

    //print(head);
    
    insertAtTail(tail, 15);
    //print(head);

    insertAtPosition(tail,head, 4, 22);
    //print(head);    

    //cout << "head " << head -> data << endl;
    //cout << "tail " << tail -> data << endl;

    //deleteNode(4, head);
    

    tail -> next = head ->next;

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    //print(head);

   

    /*
    print(head);

    if(isCircularList(head)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
    */


    return 0;
}

// different implementation

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }

    ~Node() {
        cout << "Deleting node " << data << endl;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node* curr = head;

        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void insertAtPosition(int pos, int data) {

        if (pos <= 1) {
            insertAtHead(data);
            return;
        }

        Node* curr = head;
        int cnt = 1;

        while (curr != nullptr && cnt < pos - 1) {
            curr = curr->next;
            cnt++;
        }

        if (curr == nullptr || curr == tail) {
            insertAtTail(data);
            return;
        }

        Node* newNode = new Node(data);

        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteAtPosition(int pos) {

        if (head == nullptr)
            return;

        if (pos == 1) {

            Node* temp = head;

            head = head->next;

            if (head == nullptr)
                tail = nullptr;

            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        int cnt = 1;

        while (curr != nullptr && cnt < pos) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == nullptr)
            return;

        prev->next = curr->next;

        if (curr == tail)
            tail = prev;

        delete curr;
    }

    void print() {

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    LinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtPosition(2, 15);

    list.print();

    list.deleteAtPosition(3);

    list.print();

    return 0;
}
