#include<iostream>
using namespace std;

template<class Object>
class DoublyLinkedList
{
	private:
		struct Node
		{
			Object data;
			Node *next;
			Node *prev;
          	Node(const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr) 
              : data(d), prev(p), next(n) {}
		};
  		
  		Node *head; //sentinel node at the beginning
		Node *rear; //sentinel node at the end
        int size;
	
	public:
  
		/*TODO: Define a constructor for DoublyLinkedList here, allocating the sentinel nodes*/
        
        explicit DoublyLinkedList(const Object & initialValue = Object())
        {
            head = new Node;
            rear = new Node;
            head->next = rear;
            rear->prev = head;
            size=0;
        }
  
		class Iterator
		{
			private:
				Node *current;		
			public:
				Iterator(Node *inp) : current(inp) {}
				Object & operator*() {return current->data;}
          
				/*TODO: You can add more methods here */
                Iterator & operator ++()
                {
                    this->current = this->current->next;
                    return *this;
                }
                Iterator & operator --()
                {
                    this->current = this->current->prev;
                    return *this;
                }
                Iterator operator ++(int)
                {
                    Iterator old = *this;
                    ++(*this);
                    return old;
                }
                bool operator !=(const Iterator & rhs)const
                {
                    return !(current == rhs.current);
                }
          
			friend class DoublyLinkedList<Object>;
		};

		Iterator begin(){return Iterator(head->next);}	
		Iterator end(){return Iterator(rear);}
		Iterator insert(Iterator itr, Object & o)
        {
            Node* temp = new Node;
            Node* cur = itr.current;
            temp->data = o;
            temp->prev = cur->prev;
            temp->next = cur;
            cur->prev->next = temp;
            cur->prev = temp;
            size++;
            return Iterator(temp);
        }
		Iterator erase(Iterator itr)
        {
            Node* temp = itr.current;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            Iterator ret = Iterator(temp->next);
            free(temp);
            size--;
            return ret;
        }
		Iterator atIndex(int p)
        {
            Node* ptr = head;
            for(int i=1;i<=p+1;i++)
            {
                ptr = ptr->next;
            }
            return Iterator(ptr);
        }
		int indexOf(Iterator itr)
        {
            int i=-1;
            Node* ptr = head;
            while(ptr!=itr.current)
            {
                i++;
                ptr = ptr->next;
            }
            return i;
        }	
		void display()
		{			
			for (auto it = begin(); it != end(); it++)
				cout << *it << " ";
			cout << endl;
		}		
};

int main()
{
    int N;
    cin >> N;
    DoublyLinkedList<int> dl;
    int n;
    int index;
    int command;
    for (int i = 0; i < N; i++)
    {
        cin >> command;
        switch (command)
        {
            case 1: /*insert the element at an index*/
                cin >> index;
                cin >> n;
                dl.insert(dl.atIndex(index), n);
                break;
            
            case 2: /*erase the element at an index*/
                cin >> index;
                dl.erase(dl.atIndex(index));
                break;

            case 3: /*print the head element*/
                cout << *(dl.begin()) << endl;
                break;

            case 4: /*print the rear element*/
                cout << *(--dl.end()) << endl;
                break;

            case 5: /*print the element at an index*/
                cin >> index;
                cout << *(dl.atIndex(index)) << endl;
                break;

            case 6: /*display the list*/
                dl.display();
                break;

            case 7: /*print the index of the iterator*/
                    cin >> index;
                        cout << dl.indexOf(dl.atIndex(index)) << endl;
                        break;
        }
    }
}