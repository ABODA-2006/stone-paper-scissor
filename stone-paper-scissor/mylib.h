#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
namespace mylib
{
	//to read a positive number from user

	int readpositivenumber(string messege) {
		int num;
		do {
			cout << messege;
			cin >> num;
		} while (num < 0);
		return num;
	}

	// get random number in range
	int randnumber(int from, int to) {
		int randnum = (rand() % (to - from + 1)) + from;
		return randnum;
	}

}
