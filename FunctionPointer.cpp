/**
 * @file 		FunctionPointer.cpp
 * @author		Ratna Lama
 * @date		8/8/2018
 * @brief 		Function Pointers
 */
#include <iostream>
#include <string>		// c++ style string
#include <functional>
#include <vector>
using namespace std;

// #1 Function hello()
void hello() {
	cout << "Hello Universe!" << endl;;
} // end hello()

// #2 Function makeGreeting()
string makeGreeting(const string& str) {
	return "Happy " + str + "!";
} // end makeGreeting()



int main() {
	string test_phrase{};
	string test_word{"Programming"};
	
	// #1. Auto
	cout << "\n\n--------------------Function Pointer Test Using Auto-------------------------\n";
	// points to function that take NO argument and returns NOTHING
	auto ptr_1b{hello};					
	ptr_1b();
	
	// points to function that take one string argument and returns string type
	auto ptr_1a{makeGreeting};				
	test_phrase = ptr_1a(test_word);		
	cout << "test_phrase: " << test_phrase << endl;
	
										 

	// #2. Actual type
	cout << "\n\n--------------------Function Pointer Test Using Actual Type-------------------\n";
	// points to function that take NO argument and returns NOTHING
	void(*ptr_2b)() {hello};							
	ptr_2b();
	
	// points to function that take one string argument and returns string type
	string(*ptr_2a)(const string& test_phrase) {makeGreeting};	
	test_phrase = ptr_2a(test_word);
	cout << "test_phrase: " << test_phrase << endl;
	
	
	
	// #3. Function object, <functional>
	cout << "\n\n--------------------Function Pointer Test Using Function----------------------\n";
	// points to function that take NO argument and returns NOTHING
	function<void(void)> ptr_3b{hello};							
	ptr_3b();
	
	// points to function that take one string argument and returns string type
	function<string(const string& s)> ptr_3a{makeGreeting};		
	test_phrase = ptr_3a(test_word);
	cout << "test_phrase: " << test_phrase << endl;	
	
	// #4. typedef; deprecated use using instead
	cout << "\n\n--------------------Function Pointer Test Using Typedef-----------------------\n";
	// points to function that take NO argument and returns NOTHING
	typedef void(*funcTypedef_4b)();								
	funcTypedef_4b ptr_4b{hello};
	ptr_4b();
	// points to function that take one string argument and returns string type
	typedef string(*funcTypedef_4a)(const string& s);				
	funcTypedef_4a ptr_4a{makeGreeting};
	test_phrase = ptr_4a(test_word);
	cout << "test_phrase: " << test_phrase << endl;	
	
	
	// #5. using; modern c++ approach; preferred over typedef
	cout << "\n\n--------------------Function Pointer Test Using Using------------------------\n";
	// points to function that take NO argument and returns NOTHING
	using funcUsing_5b = void();
	funcUsing_5b* ptr_5b{hello};	// no argument
	ptr_5b();
	
	// points to function that take one string argument and returns string type
	using funcUsing_5a =  string(const string& s);					
	funcUsing_5a* ptr_5a{makeGreeting};
	test_phrase = ptr_5a(test_word);
	cout << "test_phrase: " << test_phrase << endl;	
	
	cout << "\n---------------------------------------------------------------------\n" << endl;
	return 0;
}