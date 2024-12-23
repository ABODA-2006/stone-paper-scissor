#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "mylib.h"
using namespace std;
using namespace mylib;
string sysAns() {
	switch (randnumber(1, 3)) {
		case 1: return "Paper";
		case 2: return "Stone";
		case 3: return "scissor";
	}
}
string userAnswer() {
	int ans;
		cout << "\n	(1) ==> paper\n";
		cout << "	(2) ==> Stone\n";
		cout << "	(3) ==> scissor\n";
		cout << "---------------------\n";
		cout << "your choice ? (1 => 3): ";
		cin >> ans;
	
		while ((ans > 3 || ans < 1))
		{
				cout << "\npls enter a valid choice : ";
				cin >> ans;
		}
		switch (ans) {
			case 1: return "Paper";
			case 2: return "Stone";
			case 3: return "scissor";
		}

}
int compare(string UserAns, string SystemAns) {
	// return 1 mean user win, 0 mean equal, -1 means system win
	if (UserAns == "scissor") {
		if (SystemAns == "scissor") return 0;
		else if (SystemAns == "Paper") return 1;
		else if (SystemAns == "Stone") return -1;
	}
	else if (UserAns == "Paper") {
		if (SystemAns == "scissor") return -1;
		else if (SystemAns == "Paper") return 0;
		else if (SystemAns == "Stone") return 1;
	}
	else if (UserAns == "Stone") {
		if (SystemAns == "scissor") return 1;
		else if (SystemAns == "Paper") return -1;
		else if (SystemAns == "Stone") return 0;
	}
}
void PrintRoundResult(int x, string SystemAns, int &PlayerWinTimes, int &SystemWinTimes) {
	string UserAns = userAnswer();
	int result = compare(UserAns, SystemAns);
	switch (result) {
		case 0:
			system("color 6F");
			cout << "\n======== Round [" << x << "] results ======== \n";
			cout << "player choice : " << UserAns << "\n";
			cout << "computer choice : " << SystemAns << "\n";
			cout << "Round Winner : [No Winner!] \n\n";
			break;
		case 1:
			system("color 2F");
			cout << "\n======== Round [" << x << "] results ======== \n";
			cout << "player choice : " << UserAns << "\n";
			cout << "computer choice : " << SystemAns << "\n";
			cout << "Round Winner : You Win :-) \n\n";
			PlayerWinTimes += 1;
			break;
		case -1:
			system("color 4F");
			cout << "\n======== Round [" << x << "] results ======== \n";
			cout << "player choice : " << UserAns << "\n";
			cout << "computer choice : " << SystemAns << "\n";
			cout << "Round Winner : You Lose :-( \a\n\n";
			SystemWinTimes += 1;
			break;
	}
}
void GameEnd(int rounds, int PlayerWinTimes, int SystemWinTimes) {
	string Winner;
	if (PlayerWinTimes > SystemWinTimes) { 
		system("color 2F");
		Winner = "Player :-)";
	}
	else if (PlayerWinTimes < SystemWinTimes) 
	{

		system("color 4F");
		Winner = "Computer :-(";
	}
	else 
	{
		system("color 6F");
		Winner = "No Winner!";
	}
	cout << "-----------------------------------------------------------------------------------------\n";
	cout << "					GAME OVER 								\n\n";


	cout << "--------------------------------------[Game Result]--------------------------------------\n";
	cout << "Game Rounds : " << rounds << "\n";
	cout << "Player Wining Times : " << PlayerWinTimes << "\n";
	cout << "Computer Wining Times : " << SystemWinTimes << "\n";
	cout << "Final Winner : " << Winner << "\n\n\n";
}
int main() {
	int SystemWinTimes = 0, PlayerWinTimes = 0;
	srand((unsigned)time(NULL));
	char ans;
	string text;
	do{
		SystemWinTimes = 0; PlayerWinTimes = 0;
		system("color 07");
		system("cls");

		int rounds = readpositivenumber("how many number of rounds you want : ");
		for (int i = 1; i <= rounds; i++) {
			cout << "\n\n------------------------------------------ Round " << i << " begins ------------------------------------------ \n";
			PrintRoundResult(i, sysAns(), PlayerWinTimes, SystemWinTimes);
				system("pause");
				system("cls");
		}
		GameEnd(rounds, PlayerWinTimes, SystemWinTimes);
		system("pause");
		cout << "play again ? (Y/N) : ";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	return 0;
}