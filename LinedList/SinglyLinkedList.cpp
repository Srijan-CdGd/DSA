#include <iostream>
using namespace std;

class SinglyLinkedList {
    private:
        int val;
        SinglyLinkedList* next;
        SinglyLinkedList* head = NULL;
        SinglyLinkedList* tail = NULL;
        int length = 0;

        SinglyLinkedList() {
            val = 0;
            next = NULL;
        }

        SinglyLinkedList(int n, SinglyLinkedList* add){
            val = n;
            next = add;
        }

    public:
        SinglyLinkedList(int val){
            head = new SinglyLinkedList();
            head->val = val;
            tail = head;
            length++;
        }

        SinglyLinkedList* getTail(){
            return tail;
        }

        int getNodeVal(int pos){
            if(pos == 1)
                return head->val;
            SinglyLinkedList* nn = head;
            pos -= 1;
            while(pos > 0){
                nn = nn->next;
                pos--;
            };
            return nn->val;
        }

        SinglyLinkedList* getNodeNext(){
            return next;
        }
        
        void insertAtStart(int val){
            SinglyLinkedList* n = new SinglyLinkedList(val, head);
            head = n;
            length++;
        }

        void insertAtEnd(int val){
            SinglyLinkedList* n = new SinglyLinkedList();
            n->val = val;
            tail->next = n;
            tail = tail->next;
            length++;
        }

        void insertAtPosition(int pos, int val){
            if(pos == 1){
                insertAtStart(val);
                return;
            } if (pos == length+1){
                insertAtEnd(val);
                return;
            }
            SinglyLinkedList* nn = head;
            pos -= 2;
            while(pos > 0){
                nn = nn->next;
                pos--;
            };
            SinglyLinkedList* newSinglyLinkedList = new SinglyLinkedList(val, nn->next);
            nn->next = newSinglyLinkedList;
            length++;
        }

        void deleteFromStart(){
            SinglyLinkedList* temp = head;
            head = head->next;
            delete(temp);
            length--;
        }

        void deleteFromEnd(){
            SinglyLinkedList* temp = head;
            while(temp-> next -> next != NULL){
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            length--;
            
        }

        void deleteFromPosition(int pos){
            if(pos == 1){
                deleteFromStart();
                return;
            }
            if(pos == length){
                deleteFromEnd();
                return;
            }
            SinglyLinkedList* nn = head;
            pos -= 2;
            while(pos > 0){
                nn = nn->next;
                pos--;
            };
            nn -> next = nn -> next -> next;
            length--;
        }

        int getLength(){
            return length;
        }

        void print(){
            SinglyLinkedList* temp = head;
            
            while(temp != NULL){
                cout<<temp -> val<<" ";
                temp = temp -> next;
            }
            cout<<endl;
        }
};

// int main(){
//     SinglyLinkedList* head = new SinglyLinkedList(2);
//     head->insertAtPosition(1, 1);
//     head->insertAtStart(0);
//     head->insertAtEnd(3);
//     head->insertAtPosition(4, 4);
//     head->insertAtEnd(5);
//     cout<<endl;
//     head->print();
//     cout<<"Length of the current list: "<<head->getLength();
//     cout<<endl<<endl;
//     head->deleteFromStart();
//     head->print();
//     head->deleteFromPosition(3);
//     head->print();
//     head->deleteFromEnd();
//     head->print();
//     cout<<head->getNodeVal(3)<<endl;
//     head->print();
//     return 0;
// }