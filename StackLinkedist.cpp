  template<class T>
   struct Node{
      T value ;
      Node*next ;
   };
   template<class T>
   class StackLinkedList{
   private:
    Node<T>*top;
     public:
   StackLinkedList() {
      top = nullptr;
   }
      void print() {
         Node<T>*cur = top;
         while(cur != nullptr) {
            cout << cur->value << " " ;
            cur = cur->next;
         }
         cout << endl ;
      }
      bool isEmpty() const {
         return (top == nullptr) ;
      }
      void Push(T value) {
         Node<T>*newnode = new Node<T> ;
         newnode->value = value ;
         newnode->next = top ;
          top = newnode ;
      }
       void Pop(T &item) {
         if(isEmpty()) {
            cout << "is emptyyyy" << endl;
             return ;
         }
         Node<T>*cur = top ;
          item = top->value ;
          top = top->next ;
           delete cur ;
       }
         void MakeEmpty() {
            Node<T>*cur = top ;
            while(top != nullptr) {
              cur = top ;
               top = top->next ;
                delete cur ;
            }
         }
         ~StackLinkedList() {
            MakeEmpty() ;
         }
   };
   template<class T>
   void ReplaceItem(  StackLinkedList <T> &originalStack , T olditem , T newitem) {
      StackLinkedList<T> tempstack ;
        int removeditem = 0 ;
         while(!originalStack.isEmpty()) {
            originalStack.Pop(removeditem) ;
            if(removeditem==olditem){
               tempstack.Push(newitem) ;
            }
            else
            tempstack.Push(removeditem) ;
         }
         while(!tempstack.isEmpty()) {
            tempstack.Pop(removeditem) ;
            originalStack.Push(removeditem) ;
         }
   }
 
  void solve(){
    
   StackLinkedList<int>* stac = new StackLinkedList<int> ;
     stac->Push(2) ;
     stac->Push(3) ;
     stac->Push(4) ;
     stac->Push(3) ;
     stac->Push(5) ;
     stac->print() ;
     int item =0;
     stac->Pop(item) ;
     ReplaceItem(*stac , 3, 9) ;
     stac->print() ;
  }
int main(){
  solve();
return 0 ;
}
