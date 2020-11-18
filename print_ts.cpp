/*
 * print_ts.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: kyle
 */
#include "print_ts.h"
#include <mutex>
#include <iostream>
#include <thread>
std::mutex m;

void PRINT1(std::string &txt)	{
	m.lock();
	std::cout << txt << std::endl;
	m.unlock();
}

void PRINT2(std::string &txt, std::string &txt1)	{
	m.lock();
	std::cout << txt << txt1 << std::endl;
	m.unlock();
}

void PRINT3(std::string &txt, std::string &txt1, std::string &txt2)	{
	m.lock();
	std::cout << txt << txt1 << txt2 << std::endl;
	m.unlock();
}

void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3)	{
	m.lock();
	std::cout << txt << txt1 << txt2 << txt3 << std::endl;
	m.unlock();
}

void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4)	{
	m.lock();
	std::cout << txt << txt1 << txt2 << txt3 << txt4 << std::endl;
	m.unlock();
}

