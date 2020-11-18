/*
 * tester.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: kyle
 */

#include "tester.h"
#include "print_ts.h"
#include <mutex>
#include <vector>
#include <thread>
#include <iostream>
std::mutex mut;
std::vector<std::thread> threads;
bool stop = false;

void testThreadFunc(std::string s, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay);


void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay)	{
	int i = 0;
	while (i < numThreads)	{

//		std::thread t(testThreadFunc, s, wp, numTimesToPrint, millisecond_delay);
		threads.push_back(std::thread(testThreadFunc, s, wp, numTimesToPrint, millisecond_delay));
		i++;
	}
}

void setCancelThreads(bool bCancel)	{
	stop = bCancel;
}

void joinThreads()	{
	for (auto &t : threads)	{
		t.join();
	}
	threads.clear();
}

void testThreadFunc(std::string s, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay)	{
	for (int i = 0; i < numTimesToPrint; i++)	{

		if(stop)	{
			mut.lock();
			std::cout << USER_CHOSE_TO_CANCEL << std::endl;
			mut.unlock();
			i = numTimesToPrint;
		}
		else	{
			switch(wp)	{
			case P1:
				PRINT1(std::ref(s));
				break;
			case P2:
				PRINT2(std::ref(s), std::ref(s));
				break;
			case P3:
				PRINT3(std::ref(s), std::ref(s), std::ref(s));
				break;
			case P4:
				PRINT4(std::ref(s), std::ref(s), std::ref(s), std::ref(s));
				break;
			case P5:
				PRINT5(std::ref(s), std::ref(s), std::ref(s), std::ref(s), std::ref(s));
				break;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
		}
	}
}

