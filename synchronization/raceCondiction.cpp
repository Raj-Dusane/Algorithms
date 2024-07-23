#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

// shared resources
int count=0; 

void increment(){
	for (int i=0; i<=100000; i++) {
		count++;
	}
	cout << count << endl;
}

int main(){
	thread t1(increment);
	thread t2(increment);
	t1.join();
	t2.join();
	return 0;
}
