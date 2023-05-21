/* Stack from scratch as the name says StackS. */


#include<iostream>
using namespace std;

template <class S>
class StackS{
    private:
        class Node{
            public:
                S val;
                Node* next;
        };
        Node* top = NULL;
        int length = 0;
    
    public:
        StackS (S val) {
            top = new Node();
            top -> val = val;
            top -> next = NULL;
            length++;
        }

        void push(S val){
            if(top == NULL){
                StackS<S> top = StackS<S> (val);
            }
            Node* nn = new Node();
            nn -> val = val;
            nn -> next = top;
            top = nn;
            length++;
        }

        S pop(){
            if(top == NULL){
                cout<<"Stack empty, cannot pop";
                return top->val;
            }

            if(top -> next == NULL){
                S val = top->val;
                top = NULL;
                length--;
                return val;
            }
            S val = top->val;
            Node* nn = top;
            top = top->next;
            free(nn);
            length--;
            return val;
        }

        S peek(){
            if(top == NULL){
                cout<<"Stack empty";
            }
            return top->val;
        }

        int getLength(){
            return length;
        }

        void print(){
            Node* nn = top;
            while(nn != NULL){
                cout<<nn->val<<" ";
                nn = nn->next;
            }
            cout<<endl;
        }
};

// int main(){
//     StackS<char>* s = new StackS<char> ('s');
//     s->push('r');
//     s->push('i');
//     cout<<s->getLength()<<endl;
//     s->print();
//     cout<<"Peek: "<<s->peek()<<endl;
//     s->pop();
//     s->pop();
//     s->pop();
//     cout<<s->getLength()<<endl;
//     s->print();
//     cout<<"Peek: "<<s->peek()<<endl;
//     return 0;
// }
