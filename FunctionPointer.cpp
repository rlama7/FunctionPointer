#include <iostream>
using namespace std;

// Function Pointers
// #1 Function add
int add(int a, int b) {
	return a+b;
}

// #2 Function PrintHello
void PrintHello() {
	cout << "Hello Universe!";
}

//#3 Function sayHi
void sayHi(string name) {
	cout << "Hello " + name + "!";
}


int main() {
	
	
	// Function Pointers example#1
	int val{};
	// pointer to function should take (int,int) as argument/parameter and return int
	int(*ptr1)(int,int);
	ptr1 = add;		// assign address of add to ptr1
	val = ptr1(2,3);	// dereference and execute the function with given arguments
	cout << "val is: " << val;
	cout << "\n--------------------------------------------------------\n" <<endl;
	
	// Function Pointers example#2
	void(*ptr2)();
	ptr2 = PrintHello;
	ptr2();
	cout << "\n--------------------------------------------------------\n" <<endl;
	
	// Function Pointers example#3
	void(*ptr3)(string);
	ptr3 = sayHi;
	ptr3("Ray");
	cout << "\n--------------------------------------------------------\n" <<endl;
	
	
	return 0;
}