#include <iostream>
#include <vector>
#include<string>
using namespace std;

template <typename T>
bool isPrime(T num) {
	if(num%2 == 0)
		return false;
	else{
		for(int i=3; i < (num)/2+1; i++){
			if(num%i == 0) return false;
		}
	}

	return true;
}


template <typename T>
class PrimeRange {
private:
	T _b; //iterators to begin and end
	T _e;

public:
	PrimeRange(const T& b, const T& e) : _b(b), _e(e) { //move numbers to right place
		while(!(isPrime(_b))){
			++_b;
		}

		while(!(isPrime(_e))){
			++_e;
		}
	}

	

	class iterator : public std::iterator<input_iterator_tag, T> {

		friend bool operator== (const iterator& lhs, const iterator& rhs)  { 
			return lhs._v == rhs._v;
		}

		friend bool operator != (const iterator& lhs, const iterator& rhs) {
			return ! (lhs == rhs);
		}

	private:
		T _v;

	public:
		iterator(const T& v) : _v(v) {}

		T operator* () {
			return _v;
		}

		iterator& operator++() { //pre-increment
			++_v;
			while(!(isPrime(_v))){
				++_v;
			}

			return *this;
		}

		iterator operator++(int) { //post-increment
			iterator temp = *this;
			++*this;
			return temp;
		}


	};

	iterator begin() const {
		return _b;
	}

	iterator end() const {
		return _e;
	}

};


int main(int argc, char const *argv[])
{

	PrimeRange<int> a(4, 16); //moves b and e to 5 and 17
	PrimeRange<int> b(5, 17);
	PrimeRange<int>::iterator it = a.begin();
	while(it!=a.end()) {
		cout << *it << endl; //prints out 5 7 11 13
		++it;
	}
	cout << boolalpha;

	cout << equal(a.begin(), a.end(), b.begin()) << endl; //prints true

	cout << (b.begin() == 5)<< endl; //prints true

	cout << (5 == b.begin())<< endl; //prints true




	return 0;
}