#include <iostream>
#include <string> 
using namespace std; 

// prototype go here 
int index(char *p, char ch);
int count_digits(char *p);

int main() { 
    string haystack; 
    char needle; 

    // Also try different values for the string and character
    haystack = "A quick brown fox (id: 34500) jumped over a lazy dog (id: 98)"; 
    needle = 'q'; 
    
    int loc, count; 
    
    loc = index(&haystack[0], needle); 
    cout << "Loc: " << loc << endl; 

    count = count_digits(&haystack[0]); 
	cout << "Count: " << count << endl;  

    cin.get();
    return 0; 
}

// functions go here 
int index(char *p, char ch){
	int locate=0;
	while(*p!='\0') {			
		if(*p==ch){
			return locate;
		}
		locate++;
		p++;
	}
	if(*p!=ch){
		return -1;
	}
}

int count_digits(char *p){
	int count=0;
	while(*p!='\0'){
		if(int(*p)>=48 && int(*p)<=57){
			count++;
		}
		p++;
	}
	return count;
}


