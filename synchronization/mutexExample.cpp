#include <iostream>
#include <thread>
#include <unistd.h>   //sleep() fun
#include <mutex>

using namespace std;

int count=0;
mutex lockObj;

void increment(){
	lockObj.lock();
	for (int i=0; i<=100000; i++) {
		count++;
	}
	lockObj.unlock();
}

int main() {
	thread t1(increment);
	thread t2(increment);
	t1.join();
	t2.join();
	cout << count << endl;
	return 0;
}
