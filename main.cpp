/*
 * main.cpp
 *
 *  Created on: Nov 18, 2020
 *      Author: kyle
 */

#include "print_ts.h"
#include "tester.h"

#include <thread>

int main()	{
//	std::string s1 = "a";
//	std::string s2 = "b";
//	std::string s3 = "c";
//	std::string s4 = "d";
//	std::string s5 = "e";
//
//	std::thread t(PRINT1, std::ref(s1));
//	std::thread t1(PRINT4, std::ref(s1), std::ref(s2), std::ref(s3), std::ref(s4));
//	std::thread t2(PRINT5, std::ref(s1), std::ref(s2), std::ref(s3), std::ref(s4), std::ref(s5));
//	std::thread t3(PRINT5, std::ref(s5), std::ref(s4), std::ref(s3), std::ref(s2), std::ref(s1));
//
//	t.join();
//	t1.join();
//	t2.join();
//	t3.join();


	std::string s = "a";
	int numThreads = 5;
	WHICH_PRINT wp = P4;
	int numTimesToPrint = 200;
	int millisecond_delay = 100;

	startThreads(s, numThreads, wp, numTimesToPrint, millisecond_delay);
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	setCancelThreads(true);
	joinThreads();
//
//	return 0;
}

