   #include<bits/stdc++.h>
    using namespace std;
 #define endl "\n"

 void FOI () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

  template<class T>
   class ArrayList {
    private:
      T *arr;
      int size , length ;

    public:
     ArrayList( int size) {
       if(size<=1) {
        cout << "invalid size" << endl;
        return ;
       }
        this->size = size ;
        arr = new T [size] ;
        length = 0 ;
     }
      ArrayList(const ArrayList & source) {
        size = source.size ;
         length = source.length;
          arr = new T [size] ;
          assert(arr != NULL) ;
             for(int i = 0 ; i < length ; i++ ) {
               arr[i] = source.arr[i] ;
             }
      }
        bool IsEmpty() {
          return (length==0) ;
        }
        bool IsFull() {
          return (length==size) ;
        }
        void Display() {
          if(IsEmpty()) {
            cout << "Array is empty" << endl;
            return ;
          }
           for(int i=0 ; i < length ;i++) {
            cout << arr[i] << " " ;
           }
            cout << endl;
        }
        void Append( T item) {
           if(IsFull()){
            IncreamentSize();
           }
           arr[length++] = item ;
        }
        void Insert( int index , T val) {
          if(IsFull()){
            IncreamentSize();
          }
          
         for(int i = length ; i > index ; i--) {
             arr[i] = arr[i-1] ; // shifting to right
         }
         arr[index] = val ;
         length ++ ;
       }
     void operator =(const ArrayList&obj) {
              if(this != &obj) {
                delete [] arr;  // ensure copy all values
                size = obj.size;
                 length = obj.length ;
                 arr = new T [size] ;
                 for(int i=0 ; i< length ;i++) {
                  arr[i] = obj.arr[i] ;
                 }
              }
              else
              {
                cout << "same address can not be assigned" << endl;
                return ;
              }
                 
         }
         void RetreiveAt (int index , T &item) ;
           
         void ReplaceAt(int index , int &val) {
          if(IsEmpty()) {
            cout << "list is empty" << endl;
             return ;
          }
          if(index<0 || index >= length)
            {
              return ;
            }
            arr[index] = val ;
          }
           void Delete(int index , T &item) {
            if(IsEmpty()) {
              cout << "list is empty" << endl;
               return ;
            }
            else if (index<0 || index >= length) {
              cout << "invalid index" << endl;
              return ;
            }
             else {
               item = arr[index] ;
              for(int i=index ; i < length-1 ;i++) {
                arr[i] = arr[i+1] ;
              }
              length--;
             }
           }
            int SequentialSearch(int val) {
              if(IsEmpty()) {
                cout << "list is empty" << "\n" ;
                return -1 ;
              }
              for(int i=0 ; i< length ;i++) {
                if(arr[i] == val){
                  return i;
                }
              }
              return -1 ;
            }
             void MaxItem(int &max) {
                if(IsEmpty()) {
                  cout << "list is empty" << "\n" ;
                  return ;
                }
                max = arr[0] ;
                for(int i=1 ; i<length ;i++ ) {
                  if(arr[i] > max) {
                    max = arr[i] ;
                  }
                }
             }
             void MinItem(int &min) {
              if(IsEmpty()) {
                return ;
              }
              min = arr[0] ;
              for(int i=1 ; i<length ;i++ ) {
                if(arr[i] < min) {
                  min = arr[i] ;
                }
              }
           }
           int BinarySearch(T item) {
            if(IsEmpty()) {
              cout << "Array is empty" << endl;
               return -1 ;
            }
          int  low = 0 , high = length-1 , mid =0 ;
              while(high>=low) {
                mid = (low + high ) / 2 ;
                if(arr[mid]==item )
                return mid ;
                else if (arr[mid] > item )
                 high = mid - 1;
                  else
                  low = mid + 1;
              }
              return -1 ;
           }
           void IncreamentSize() {
            T *old = arr;
            arr = new int [size + 5] ;
            for(int i= 0 ; i < length ;i++) {
              arr[i] = old[i] ;
            }
             delete [] old ;
           }
            bool IsItemEqual(int index , const T &item) {
              return (arr[index] == item) ;
            }
            
   };
   template<class T>
   void ArrayList<T>::RetreiveAt (int index , T &item) {
    if(IsEmpty()) {
      cout << "list is empty" << endl;
       return ;
    }
    if(index<0 || index >= length)
      {
         cout << "invalid index" << endl;
        return ;
      }
    item = arr[index] ;
   }
int main() {
    FOI () ;
     ArrayList<int> list1(5) ;
     ArrayList<int> list2(7) ;
     list2.Append(100) ;
      list2.Append(250) ;
      list2.Append(330) ;
      list2.Display() ;
      list1.Append(10) ;
      list1.Append(20) ;
      list1.Append(30) ;
      int item ;
       list1.RetreiveAt(1 , item) ;
        cout << "item = " << item << endl;
      list2 = list1 ;  // assigment operator calling
    
       list1.Insert(1,500) ;
       list1.Display() ;
        int index = list2.BinarySearch(330) ;
         cout << "index = " << index << endl;
    return 0;
}
