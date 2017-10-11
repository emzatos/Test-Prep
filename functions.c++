#include <iostream>
#include <vector>
#include <deque>
#include<string>
using namespace std;






template <typename II, typename UF> 
long long my_all_of (II b, II e, UF uf) {
	while(b!=e){
		if(!uf(*b))
			return false;
		++b;
	}

	return true;
}


template <typename II, typename UF> 
long long my_any_of (II b, II e, UF uf) {
	while(b!=e){
		if(uf(*b))
			return true;
		++b;
	}

	return false;
}



template <typename II, typename UF> 
long long my_count_if (II b, II e, UF uf) {
	long long val = 0;
	while(b!=e){
		if(uf(*b))
			++val;
		++b;
	}

	return val;
}



template <typename II, typename T> //T just means some arbitrary value/object
long long my_count (II b, II e, const T& v) {
	long long val = 0;
	while(b!=e){
		if(*b == v)
			++val;
		++b;
	}

	return val;
}




template <typename II, typename OI>
OI my_merge(II b1, II e1, II b2, II e2, OI r) {
	while(b1 != e1) {
		if(b2 == e2) {
			std::copy(b1, e1, r);
			return r;
		}
		if(*b1 < *b2){
			*r = *b1;
			++b1;
			++r;
		}else{
			*r = *b2;
			++b2;
			++r;
		}
	}

	std::copy(b2, e2, r);
	return r;
}


bool isPowerOfTwo(int n){
	return (n & (n-1)) == 0;
}

struct A{
	bool operator()(int b) {
		return b%3 == 0;
	}
};





int main () {
	vector<int> a{2,4,6};
	vector<int> b{1,3,5};
	vector<int> c(a.size() + b.size());
	my_merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

	for(auto a : c)
		cout << a << " "; //outputs 1 2 3 4 5 6

	cout << endl;

	cout << my_count(a.begin(), a.end(), 2) << endl; //outputs 1

	cout << my_count_if(a.begin(), a.end(), [](int a){return a%2==0;}) << endl; //outputs 3

	cout  <<  my_any_of(a.begin(), a.end(), isPowerOfTwo) << endl; //outputs 1 (true)



	cout <<  my_all_of(a.begin(), a.end(), A()) << endl; // outputs 0 (false)

	/*

	I used three different ways of passing in a 'function', or, rather, a function-like object. The first is a simple lambda. The second is simply a pointer to a function that I had defined earlier. The last one is an example of a function-like object that is not technically an object. Essentially, I overloaded the () operator for the A object so that you can call an A object like a function. Then, I pass in an instance of the A object so from the function's perspective, it only needs to call f(arg) in order for the unary function to work properly.

	*/


}




