// #include<iostream>
   #include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define imax INT_MAX
#define imin INT_MIN
#define sz(a) (int) a.size()
#define pll pair<ll,ll>
 using namespace std;
 #define endl "\n"
 #define ull  unsigned long long
 void FOI () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
   const int N = 2e5 + 20 , M = 1e5 + 5 , NN=1e6+6;
   const ll MOD = 1e9 + 7 , inf = 1e18; 
 // l+(r-l)/2
  // ll num = 1LL << 60 ;
 const double EPS = 0.00000001;
     
    #define FAST ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    template<class T>
   struct Node{
      T value ;
      Node*next ;
   };
   template<class T>
   class QueueLinkedList{
  private:
   Node<T>*front;
   Node<T>*rear;
  public:
  QueueLinkedList() {
   front = rear = nullptr;
  }
     void print () {
      Node<T>*cur = front;
       while(cur != nullptr) {
         cout << cur->value << " " ;
         cur = cur->next;
       }
       cout << endl;
     }
     bool isEmpty() {
      return (front == nullptr) ;
     }
     void Enqueue(T item) {
      Node<T>*newnode = new Node<T>;
       newnode->value = item ;
        if(isEmpty()) {
         front = newnode ;
        }
        else{
         rear->next = newnode ;
        }
        rear = newnode ;
        newnode->next = nullptr;
     }
      void Dequeue(T &item) {
         if(isEmpty()) {
            cout << "queue is emptyyy" << endl;
             return ;
         }
         Node<T>*cur = front;
           item = front->value ;
           front = front->next ;
           if(front==nullptr)
           {
            rear = nullptr ;
           }
           delete cur ;
      }
      void MakeEmpty() {
       Node<T>*cur = nullptr;
        while(front != nullptr) {
           cur = front ;
            front = front->next ;
             delete cur ;
        }
        rear = nullptr ;
      }
      ~QueueLinkedList() {
         MakeEmpty() ;
      }
      int QueueLength() {
         Node<T>*cur = front;
          int counter = 0;
         while(cur != nullptr) {
           counter++;
           cur = cur->next;
         }
         return counter ;
      }
   };
   template<class T>
   int Length( QueueLinkedList<T>&queue) {
      QueueLinkedList<T>tempqueue;
      int item =0 , length = 0;
       while(!queue.isEmpty()) {
         queue.Dequeue(item) ;
         tempqueue.Enqueue(item) ;
         length++;
       }
       while(!tempqueue.isEmpty()) {
         tempqueue.Dequeue(item) ;
         queue.Enqueue(item) ;
       }
       return length;
   }
 
  void solve(){
    QueueLinkedList<int>q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
     q.print() ;
      cout << "length od queue is " << Length(q) << endl;
 
  }
   
  // #define FAST ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 int main(){
    FAST 
      FOI () ;
       //  cout << fixed << setprecision(9);
    int tt = 1;
     // cin>> tt;
    while (tt--) {
        solve();
    }  
 }
