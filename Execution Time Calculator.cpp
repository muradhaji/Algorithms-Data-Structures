#include <iostream>
#include <chrono>
using namespace std;

int main() {
	
	using namespace std::chrono;
	
	auto start = high_resolution_clock::now();
	
	for(int i = 0 ; i < 1000000000 ; i++) {}
	
    auto stop = high_resolution_clock::now();

	cout << "NanoSec:\t" << duration_cast<nanoseconds>(stop - start).count() << endl;
	cout << "MicroSec:\t" << duration_cast<microseconds>(stop - start).count() << endl;
	cout << "MilliSec:\t" << duration_cast<milliseconds>(stop - start).count() << endl;
	cout << "Sec:\t\t" << duration_cast<seconds>(stop - start).count() << endl;
	cout << "Sec (double):\t" << duration_cast<duration<double>>(stop - start).count() << endl;
	cout << "Minutes:\t" << duration_cast<minutes>(stop - start).count() << endl;
	cout << "Hours:\t\t" << duration_cast<hours>(stop - start).count() << endl;
	
	return 0;
}

