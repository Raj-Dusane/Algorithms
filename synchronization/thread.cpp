#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

void task1(){
	for (int i=0; i<100; i++){
		sleep(0.5);
		cout << "Task1 : " << i << endl;
	}
}

void task2(){
	for (int i=0; i<100; i++) {
		sleep(0.5);
		cout << "Task2 : " << i << endl;
	}
}

int main() {
	thread t1(task1);
	thread t2(task2);
	t1.join();
	t2.join();
	return 0;
}
