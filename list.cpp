#include <iostream>
using namespace std;

template<class T>
class Node{
    private:
        T data;
        Node<T>* nextNode;

    public:
        Node(T iData){
            data = iData;
            nextNode = nullptr;
        }

        T getData(){
            return data;
        }

        void setNextNode(Node* node){
            nextNode = node;
        }

        Node<T>* getNextNode(){
            return nextNode;
        }
};

template<class T>
class List{
    private:
        int size;
        Node<T>* firstNode;
        Node<T>* lastNode;

        Node<T>* getNodeInPosition(int position){
            if(size > 0 && position >= 0 && position < size){
                Node<T>* returnNode = firstNode;
                for(int i = 0; i < position; i++){
                    returnNode = returnNode->getNextNode();
                }
                return returnNode;
            }
            return nullptr;
        }

    public:
        List(){
            size = 0;
            firstNode = nullptr;
            lastNode = nullptr;
        }

        void insert(T data){
            Node<T>* newNode = new Node<T>(data);
            if(firstNode == nullptr){
                firstNode = newNode;
                lastNode = newNode;
            }
            else{
                lastNode->setNextNode(newNode);
                lastNode = newNode;
            }
            size++;
        }

        void remove(int position){
            if(position >= 0 && position < size){
                Node<T>* toRemove = getNodeInPosition(position);
                if(position == 0){
                    firstNode = firstNode->getNextNode();
                }
                else{
                    Node<T>* predecessor = getNodeInPosition(position -1);
                    if(position == size -1){
                        lastNode = predecessor;
                        lastNode->setNextNode(nullptr);
                    }
                    else{
                        Node<T>* successor;
                        successor = toRemove->getNextNode();
                        predecessor->setNextNode(successor);
                    }
                }
                delete toRemove;
                size--;
            }
            else{
                cout << "ERROR: Position tried to be removed is out of list bounds.\n";
                exit(0);
            }
        }

        T get(int position){
            Node<T>* node = getNodeInPosition(position);
            if(node != nullptr){
                return node->getData();
            }
            cout << "ERROR: Position tried to be read is out of list bounds.\n";
            exit(0);
        }

        T pop(){
            if(size > 0){
                T data = lastNode->getData();
                remove(size -1);
                return data;
            }
            cout << "ERROR: The list is empty.\n";
            exit(0);
        }

        int getSize(){
            return size;
        }
        
};
