#include <iostream> 
#include <string>
using namespace std; 

struct node{
	node *next;
	int val;
};

class List { 
	public:
    List();
    void push(int val);
	void print_list();
	int sum_list();
	
	private:
	int do_sum(node *current);
	int sum;
    node *head;
    node *tail;
};

List::List(){
    //sum = 0;
    head = NULL;
    tail = NULL;
}

void List::print_list(){
	
	node *temp = head;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp= temp->next;
	}
}
int List::sum_list(){
    sum = 0;
    return do_sum(head);
}

int List::do_sum(node *current){

    if (current == NULL){
        return sum;
    }
    sum += current -> val;
    do_sum(current->next);
}


void List::push(int val) { 
    node *temp = new node;      // create new node 
    temp->val = val;
    temp->next = NULL; 

    if (head == NULL) {         // for when list is empty
        head = temp; 
        tail = temp; 
    } 
	else {                    // for all other cases 
        tail->next = temp; 
        tail = tail->next; 
    } 
}

int main() { 
    List l; 

    l.push(5);          
    l.push(15);
    l.push(30);
    l.push(32);
    l.push(3);
    l.push(29);
    l.print_list(); 

    cout << "Sum = " << l.sum_list() << endl; 
    
    l.push(4);
    l.print_list(); 
    cout << "Sum = " << l.sum_list() << endl;
    
    l.push(23);
    l.print_list();
    cout << "Sum = " << l.sum_list() << endl;
    cin.get();
    return 0; 
}
