   #include<bits/stdc++.h>
    using namespace std;
 #define endl "\n"

 void FOI () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 template<typename T>
   struct Node {
 
     T data ;
      Node *next ;
  };
   
  template<typename T>
   class LinkedList{
    private:
     Node<int> * head ;
      int count ;
      public:
      LinkedList() {
        head = nullptr ;
        count = 0;
      }
      bool isEmpty() {
        return (head==nullptr) ;
      }
      void insertAtPosition(int position , T data) {
        if(position < 0) {
          cout << "invalid position" << endl;
           return ;
        }
         Node<int>* temp = head ;
        Node<int>* t = new Node<int> ;
        t->data = data ;
         if(position == 0) {
          // add mode at first
          
            t->next = head ;
             head = t ;
         }
         else{
            for(int i=0 ; i< position-1 && temp ; i++) {
              temp = temp->next ;
            }
             if(temp !=nullptr) {
            t->next = temp->next ;
            temp->next = t ;
             }
             else{
              cout << "position is greater than number of elements" << endl;
              delete t ;
              return ;
             }
             
         }
         count ++;
      }
      void Print() {
        Node<int>* t = head ;
         while(t !=nullptr) {
          cout << t->data << endl;
           t = t->next ;

         }
      }
      int Count() {
        return count ;
      }
      int deleteAtPosition(int pos) {
        if(isEmpty()) {
          cout << "linked list is empty" << endl;
           return -1 ;
        }
         if(pos <= 0) {
          cout << "invalid position" << endl;
           return -1 ;
         }
         int x ;
         if(pos == 1) {
          Node<int>*t = head ;
          x = head->data;
           head = head->next ;
            delete t ;
         }
         else{
          Node<int>*prev = nullptr ;
           Node<int>*curr = head ;
            for(int i=0 ; i< pos-1 && curr ; i++) {
              prev = curr ;
               curr = curr->next;
            }
            if(curr !=nullptr) {
              prev->next = curr->next ;
              delete curr ;
            }
            else{
              cout << "invalid position " << endl;
               return -1;
            }
         }
         return x ;
      }
   };
  
 
 
int main() {
    FOI () ;
    LinkedList<int> *l1 = new LinkedList<int>;
      l1->insertAtPosition(0,10) ;
      l1->insertAtPosition(1,20) ;
      l1->insertAtPosition(2,30) ;
       l1->Print() ;
        cout << endl;
        l1->deleteAtPosition(1) ;
        l1->Print() ;
	return 0;
}
