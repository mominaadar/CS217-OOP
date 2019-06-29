#include <iostream> 
#include<string>
#include<fstream>
using namespace std; 
// stuff from Queue lecture goes here ... then apply template on it 
#define SIZE 4


template<class T>
class Queue { 
    private: 
    T q[SIZE]; 
    int in, out; 
    bool is_empty, is_full; 

    // circular increment 
    int inc(int val);

    public: 
    Queue(); 
    void enqueue(T val);  // spell that as ... enq-ue-ue
    T dequeue();          // deq-ue-ue 

    void print_queue(); 
};

template<class T>
Queue<T>::Queue() { 

    in = out = 0; 
    is_empty = true; 
    is_full = false; 
}

template<class T>
int Queue<T>::inc(int val) { 
    if (val + 1 == SIZE)         // loop around 
        val = 0; 
    else 
        val += 1; 
    return val; 
}

template<class T>
void Queue<T>::enqueue(T val) { 
    if (is_full) {
        //throw "Queue full. Cannot enqueue ... "; 
        cout << "Queue is full.." <<endl; 
        return; 
    } 
    // put where in is and increment in 
    q[in] = val; 
    in = inc(in); 
    // check if we are now full 
    if (in == out) 
        is_full = true; 
    // definitely not empty any more 
    is_empty = false; 
}

template<class T>
T Queue<T>::dequeue() { 
    if (is_empty) {
        throw "Queue empty. Cannot dequeue ... "; 
    } 

    // get from where out is and inc out 
    T ret = q[out]; 
    out = inc(out); 

    // see if we are now empty 
    if (in == out) 
        is_empty = true; 

    // definitely not full any more 
    is_full = false;       

    return ret; 
}

template<class T>
void Queue<T>::print_queue() { 
    cout << "[\t"; 
    for (int i = 0; i < SIZE; i++)
        cout << q[i] << "\t"; 
    cout << "]" << endl; 

    cout << " "; 
    for (int i = 0; i <= in; i++) 
        cout << "\t \t"; 
    cout << "^in" << endl;

    cout << " "; 
    for (int i = 0; i <= out; i++) 
        cout << "\t \t"; 
    cout << "^out" << endl;
}



template<class T>
class Writer{ 
    // fill stuff here 
    public:
    void process_file(string filename, Queue<T> *q);
}; 

// method definitions for Writer class here 
template<class T>
void Writer<T>::process_file(string filename, Queue<T> *q){
	
	string line;
	
	ifstream fin(&filename[0], ios::out);
	
	while (!fin.eof()) { 
        getline(fin, line); 
        q->enqueue(line); 
    } 
    
	fin.close();
}



template<class T>
class Reader { 
    // fill stuff  here 
    public:
    int process_queue(Queue<T> *q);
};

// method definitions for Reader class here 
template<class T>
int Reader<T>::process_queue(Queue<T> *q){
	for(int i=0; true; i++){
		try{
			T str;
			str = q->dequeue();
			cout<<"String ["<<str<<"] has length: "<<str.length()<<endl;
		}
		catch(const char* msg){
			cout<<msg<<endl;
			break;
		}
	
	}	
}


int main() { 
    Queue<string> *que; 
    que = new Queue<string>; 

    string filename = "string-collection.txt"; 

    Writer<string> first_writer; 
    Reader<string> first_reader; 
    
    first_writer.process_file(filename, que); 
    que->print_queue();
    first_reader.process_queue(que);

    return 0; 
}
