//
// Created by jlibyvali on 24-3-2.
//

#include <iostream>
#include <array>
#include <chrono>

class Node {

private:
    int key;
    /* Key is one Only character to node.
     * */
    int data;
    Node *next;
public:

    Node() { // Generate one null node.
        key = 0;
        data = 0;
        next = nullptr;
    }

    Node(int _data) {
        data = _data;

        auto currentTime = std::chrono::system_clock::now();
        std::time_t timesamp = std::chrono::system_clock::to_time_t(currentTime);   //Use the timestamp as 'key'

        key = static_cast<int>(timesamp);
        next = nullptr;

    }

    Node(int _key, int _data) {  // Generate new node and set the 'key' and 'data'.

        key = _key;
        data = _data;
        next = nullptr;

    }

// Getter and Setter
    int getKey() const {
        return key;
    }

    void setKey(int key) {
        Node::key = key;
    }

    int getData() const {
        return data;
    }

    void setData(int data) {
        Node::data = data;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

};

class SinglyLinkedList {

public:
    Node *HEAD;

    SinglyLinkedList() { // Generate one NULL linkedlist
        HEAD = nullptr;

    }

    SinglyLinkedList(Node *_head) {
        HEAD = _head;
    }

    Node *nodeExist(int _key) {

        Node *ptr = HEAD;

        while (ptr != nullptr) {

            if (ptr->getKey() == _key) {    // If exist the same key , return it
                return ptr;
            }

            ptr = ptr->getNext();

        }
        return nullptr;

    }

    void appendNode(Node *_node) {       // Append one Node

        Node *temp = HEAD;

        if (nodeExist(_node->getKey()) == nullptr) {

            while (temp != nullptr) {

                if (temp->getNext() == nullptr) {    // When arrive at the end node

                    temp->setNext(_node);
                    return;
                }

                temp = temp->getNext();

            }

            HEAD = _node;   // If it's the first node, set it as HEAD.
            return;

        } else {

            std::cout << "Node already exist with key:" << _node->getKey() << std::endl;
            return;
        }


    }

    void prepend(Node *_node) {

        if (nodeExist(_node->getKey()) == nullptr) {

            _node->setNext(HEAD);    // Whether it's empty or not, build '_node' link.
            HEAD = _node;

        } else {

            std::cout << "Node had existed with key:" << _node->getKey() << std::endl;
        }

    }

    void insertNode(int _key, Node *_node) {   // insert one node in 'k-th' pos.

        if (nodeExist(_key) == nullptr) {

                std::cout << "No node exist with key:" << _key << std::endl;
                return;

        } else {

            Node *temp = nodeExist(_key);   // Get 'k-th' position
            temp->setNext(_node);   // Build link
            _node->setNext(temp->getNext());

        }
    }

    void deleNode(int _key){

        if (HEAD == nullptr) {

            std::cout << "Empty list" << std::endl;

        }else{  // If not the empty list.

            if ( HEAD->getKey() == _key){

                HEAD = HEAD->getNext(); // If it's first node.

            }else{

                Node* prev,*current,*next;

                prev = nullptr;
                current = HEAD;
                next = HEAD->getNext();

                while (current != nullptr){

                    prev = current;

                    if (current->getKey() == _key) {
                        prev->setNext(next);    // build link between 'prev' node and 'next' node.
                        current->setNext(nullptr);  // break link with the deleted node.
                        return;
                    }

                    current = current->getNext();
                    next = next->getNext();

                }

                std::cout<<" Invalid key value"<<std::endl;

            }

        }

        return;
    }

    void updateNode(int _key, int _data){   // Update one node's data;

        Node* temp = HEAD;

        if (nodeExist(_key) == nullptr){

            while (temp != nullptr){

                if (temp->getKey() == _key){

                    temp->setData(_data);

                }

                temp = temp->getNext();

            }

        }else{

            std::cout<<"Invalid key"<<std::endl;
        }
        return;

    }

    void display(Node* _head){

        if (_head == nullptr){

           std::cout<<" Empty list"<<std::endl;

        }else{

           std::cout<<"List: ";
           Node* temp = _head;

            while (temp != nullptr){

                std::cout<<temp->getData()<<" ";
                temp = temp->getNext();

            }

            std::cout<<std::endl;
        }


        return;
    }


};

int main() {

    int option,data,key;
    auto s1 = SinglyLinkedList();

    do {
        std::cout<<"Input Option, 0 exit: ";
        std::cout<<"\n1. Append Node";
        std::cout<<"\n2. Prepend Node";
        std::cout<<"\n3. Insert Node";
        std::cout<<"\n4. Delete Node";
        std::cout<<"\n5. Update Node";
        std::cout<<"\n6. Display Node\n";

        std::cin>>option;

        switch (option) {
            case 1: {
                std::cout << "Input data to append: ";
                std::cin >> data;
                Node *node = new Node(data);
                s1.appendNode(node);
                break;
            }
            case 2: {
                std::cout << "Input data to prepend: ";
                std::cin >> data;
                Node *node = new Node(data);
                s1.prepend(node);
                break;
            }
            case 3: {
                std::cout << "Input key of the node after which you want to insert this new node: ";
                std::cin >> key;
                std::cout << "Input data of the node: ";
                std::cin >> data;
                Node *node = new Node(data);
                s1.insertNode(key, node);
                break;
            }
            case 4: {
                std::cout << "Input key of the node to delete: ";
                std::cin >> key;
                s1.deleNode(key);
                break;
            }
            case 5:
                std::cout<<"Input key of the node to update: ";
                std::cin>>key;
                std::cout<<"Input new data to update: ";
                std::cin>>data;
                s1.updateNode(key,data);
                break;
            case 6:
                s1.display(s1.HEAD);
                break;
            default:
                std::cout<<"Invalid option"<<std::endl;
                break;
        }
    } while (option != 0);

    return 0;
}