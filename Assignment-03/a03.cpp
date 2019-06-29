#include <iostream> 
using namespace std; 

// node structure here 
struct node{
	node *next;
	int val;
};


class List { 
	public:
	node *head=NULL;
	node *last=NULL;
    void push(int val);
	void print_list();
	void delete_after_node(node *current); 
	void delete_head_node(node *current);
	int pop();
};

void List::push(int val) { 
    node *temp = new node;      // create new node 
    temp->val = val;
    temp->next = NULL; 

    if (head == NULL) {         // for when list is empty
        head = temp; 
        last = temp; 
    } 
	else {                    // for all other cases 
        last->next = temp; 
        last = last->next; 
    } 
}

int main() { 
    // Part - 1 Starts here ----------------------
    List l; 

    l.push(5);          
    l.push(15);
    l.push(30);
	l.print_list(); 
	
    // Part - 1 Ends here ----------------------



    // Part - 2 Starts here ----------------------

    cout << "Poppping: " << l.pop() << endl; 
    l.print_list(); 

    cout << "Poppping: " << l.pop() << endl; 
    l.print_list(); 

    cout << "Poppping: " << l.pop() << endl;         // this will give an error at first 
    l.print_list(); 

	cout<<"The list is empty..";
	
    // Part - 2 Ends here ----------------------

    return 0; 
}

void List::print_list(){
	
	node *temp = head;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp= temp->next;
	}
}

void List::delete_after_node(node *current){
	
	node *temp = current -> next;
	last = current;   // so all the 'last's now become the current
	last -> next = NULL;   //can be current too
	delete temp;
	
}

void List::delete_head_node(node *current){  

	node *temp=current;
	delete temp;
	
	current=NULL;
	last=NULL;
	temp=NULL;
	head=NULL;
} 

int List::pop(){

	node *current = head;
	int last_node_val, head_node_val;
	
	if ( current->next == NULL ){   
		head_node_val = head->val;
		delete_head_node(current);
		return head_node_val; 	
	} 
	
	else{
		while (current->next!=last){  //comparing addresses 
			current = current->next;
		}
		last_node_val = last -> val;
		delete_after_node(current);	
		return last_node_val;
	}
}
