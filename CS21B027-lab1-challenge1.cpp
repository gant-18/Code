#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class IntCell {
    public:
        IntCell(int initialValue=0) {
            storedValue = new int;
            *storedValue = initialValue;
        }
          /* You may need to define copy/move constructors and assignment operators*/
        IntCell(const IntCell & rhs)
        {
            storedValue = new int;
            *storedValue = *(rhs.storedValue);
        }
        IntCell & operator=(const IntCell & rhs)
        {
            *storedValue = *(rhs.storedValue);
            return *this;
        }
        int read() {return *storedValue;}
        void write(int x) {*storedValue = x;}
    private:
        int * storedValue;
};

class Collection {
  private:
      IntCell * arr;
      IntCell size;
      int curr;
      /* You may need to define more members */
  
  public:
      // Constructor which initializes arr with size inpSize

      Collection(int inpSize=10) : size(inpSize)
    {
        arr = new IntCell[size.read()];
        curr = 0;
    }
  
      ~Collection()
    {
          delete arr;
    }
      
    //You may need to define copy,move constructors, and copy/move assignment operators
    Collection(const Collection & rhs)
    {
        size = rhs.size;
        arr = new IntCell[size.read()];
        for(int i = 0; i < rhs.curr; i++)
        {
            arr[i] = rhs.arr[i];
        }
        curr = rhs.curr;
    }
    Collection & operator=(const Collection & rhs)
    {
        size = rhs.size;
        for(int i = 0; i < rhs.curr; i++)
        {
            arr[i] = rhs.arr[i];
        }
        curr = rhs.curr;
        return *this;
    }
    //Define public functions isEmpty, makeEmpty, insert, remove, contains
    void insert(IntCell k)
    {
        int x = k.read();
        int b = size.read();
        if(curr < b)
            arr[curr].write(x);
        else
        {
            IntCell *brr=new IntCell[b+1];
            for(int i = 0; i < b; i++)
            {
                brr[i] = arr[i];
            }
            brr[b].write(x);
            arr = brr;
            size.write(b+1);
        }
        curr++;
    }
    bool isEmpty() {return curr == 0;}
    bool contains(IntCell k)
    {
        int x = k.read();
        for(int i = 0; i < curr; i++)
        {
            if(arr[i].read() == x)
                return true;
        }
        return false;
    }
    void remove(IntCell k)
    {
        int x = k.read();
        int flag2 = 1;
        while(flag2)
        {
            int ind, flag = 0;
            for(int i = 0; i < curr; i++)
            {
                if(arr[i].read() == x)
                {
                    ind = i; flag = 1; break;
                }
            }
            if(flag)
            {
                for(int i = ind; i < curr-1; i++)
                {
                    arr[i]=arr[i+1];
                }
                curr--;
            }
            else
                flag2 = 0;
        }
    }
    void makeEmpty(){curr = 0;}
    void print()
    {
        for(int i=0 ; i<curr; i++)
        {
            cout<<arr[i].read()<<" ";
        }
    }
    //Use call-by-constant-reference wherever applicable.
};


/*DO NOT MAKE ANY CHANGES TO THE CODE BELOW*/

int main() {
  int N;
  cin >> N;
  Collection c;
  int command;
  for (int i = 0; i < N; i++)
  {
    cin >> command;
    switch (command)
    {
      case 1 /*"initialize"*/:
        {
            int inpSize;
            cin >> inpSize;
            Collection c2(inpSize);
            c = c2;
        }
        break;

       case 2 /*"initializeWith"*/:
       {
            int size2;
            cin >> size2;
            Collection c2(size2);
            for (int j = 0; j < size2; j++)
            {
              int elem;
              cin >> elem;
              IntCell elemCell(elem);
              c2.insert(elemCell);
            }
            Collection c3 = c2;
            c = c3;
            break;
       }
      case 3 /*"insert"*/:
        {
            int elem;
            cin >> elem;
            IntCell elemCell(elem);
            c.insert(elemCell);
            break;
        }
      case 4 /*"remove"*/:
       {
            int elem;
            cin >> elem;
            IntCell elemCell(elem);
            c.remove(elemCell);
            break;
       } 
      case 5 /*"copy"*/:
       {
            int size2;
            cin >> size2;
            Collection c2(size2);
            for (int j = 0; j < size2; j++)
            {
              int elem;
              cin >> elem;
              IntCell elemCell(elem);
              c2.insert(elemCell);
            }
            c = c2;
            break;
       }
      case 6 /*"isEmpty"*/:
      {
            if (c.isEmpty())
            cout << "Collection is empty" << endl;
            else
            cout << "Collection is not empty" << endl;
            break;
      }
      case 7 /*"makeEmpty"*/:
            c.makeEmpty();
            break;
      case 8 /*"contains"*/:
      {
            int elem;
            cin >> elem;
            IntCell elemCell(elem);
            if (c.contains(elemCell))
            cout << "Collection contains " << elem << endl;
            else
            cout << "Collection does not contain " << elem << endl;
            break;
      }
      default:
            cout << "Invalid command!" << endl;
    }
  }
  return 0;
}