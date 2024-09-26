#include<iostream>
using namespace std;
// Node
class Node{
    public:
        int value;
        Node* next;
        Node(int value){
            this->value = value;
            this->next = NULL;
        }
};
// Linkedlist
class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = new Node(0);
            head->next = NULL;
        }
        bool checkDulpicate(int value){
            Node* check = head;
            while (check)
            {
                
                if(check->value == value){
                    return true;
                    break;
                }
                check = check->next;
            };
            return false;
        }
        // Insert After
        void insertAfter(int value , int id){
            Node* n = new Node(value);
            if(head->value == 0 && head->next == NULL){
                head = n;
            }
            else{
               
                Node* ptr = head;
                bool error;
                while (ptr)
                {
                    
                    error = checkDulpicate(value);
                    if(error == false){                    
                        if(!ptr->next){ //??????????
                            ptr->next = n;
                            n->next = NULL;
                            
                            break;
                        }
                        else if(ptr->value == id){ 
                            n->next = ptr->next;
                            ptr->next = n;
                            break;
                        }
                    }
                    else{
                        break;
                    }
                    ptr = ptr->next;
                }    
            }
        }
        void insertBefore(int value , int id){
                Node* ptr = head;
                Node* n = new Node(value);
                if (id == 0 && ptr->next == NULL) {
                    head = n;
                } else if ( ptr->value == id) {
                    n->next = ptr;
                    head = n;
                } else if(ptr->next==NULL&& ptr->value !=id){
                        ptr->next=n;
				}
                else{
                    
                    for (Node* ptr = head; ptr !=NULL ; ptr = ptr->next )  {
                        if(checkDulpicate(value) == false){
                            if(ptr->next->value == id){
                                n->next = ptr->next;
                                ptr->next = n;
                                break;
                            }
                            else if( ptr->next->next == NULL &&ptr->value != id ){
                                n->next = ptr->next->next;
                                ptr->next->next =n;
                                break;
                            }
                        }


                    }
                    

                }
                
        }
        

        
        //Delete

        //Display Linkedlist
        void display(){
            Node* ptr = head;
            while(ptr){
                cout << ptr->value << " ";
                ptr = ptr->next;
            }cout<<endl;
        }

};

int main(){
    int value,id;
    char s;
    LinkedList* l = new LinkedList();
    do
    {
        cin >> s;
        switch(s){
            case 'I':
                cin >>value>>id;
                // Insert Before method 
                l->insertBefore(value,id);
                //Display 
                l->display();
                break;
            case 'A':
                cin >>value>>id;
                // Insert After method
                l->insertAfter(value,id);
                //Display 
                l->display();
                break;
            case 'D':
                // Delete Method

                //Display 
                break;
            case 'E':
                //Exit
                break;
        }
    } while (s != 'E');
    
    return 0;
}
