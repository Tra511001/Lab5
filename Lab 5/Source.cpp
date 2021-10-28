/*
	Nikola trajanovski
	Lab 5 Number guessing game
	due oct 27th

	A number-guessing game in which the computer selects a random
	number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
	the end of each game, users should be told whether they won or lost, and then be asked
	whether they want to play again. When the user quits, the program should output the
	total number of wins and losses.

*/
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool randNumber(bool theResult);
void lossMsg();
void winMsg();
void anotherGame();

int main() {
	bool theResult = false;
	//counterW and counterL they cout the number of times the user wins or loses
	int counterW = 0;
	int counterL = 0;
	theResult = randNumber(theResult);
	int playAgain;

	do{
		//if else that compares the users answer
		if (theResult == true) {
			counterW++;
			
			cout << endl;
			anotherGame();
			cin >> playAgain;
		}
		else {
			counterL++;
			lossMsg();
			cout<< endl;
			anotherGame();
			cin >> playAgain;
		}


		if (playAgain == 1) {// Play again (yes/no)
			theResult = randNumber(theResult);
		}
		else if (playAgain == 0) {
			cout << endl << endl;
			cout << "You won a total of " << counterW << " times" << endl;
			cout << "You lost a total of " << counterL << " times" << endl;
			break;
		}
	} while (true);

	return 0;
}


//void function that prints one of 10 strings, this is printed when user finishes the game regardles of win/loss
void anotherGame(){
	srand(time(0));
	int theNumber = 1 + (rand() % 10);
	switch (theNumber) {
		case 1: cout << "Would you like to play again ? 1(yes)/ 0(no) ";
			break;
		case 2: cout << "Game finished do you want to play again? 1(yes)/ 0(no) ";
			break;
		case 3: cout << "You are do with this round, do you want to play again? 1(yes)/ 0(no) ";
			break;
		case 4: cout << "The round is over, play again? 1(yes)/ 0(no)";
			break;
		case 5: cout << "This round is finished, do you want to play again? 1(yes)/ 0(no) ";
			break;
		case 6: cout << "DO you want to play again? 1(yes)/ 0(no)";
			break;
		case 7: cout << "Play agian? 1(yes) / 0(no)";
			break;
		case 8: cout << "Round is done, do you want to play again? 1(yes)/ 0(no)";
			break;
		case 9: cout << "Do you want to play again? 1(yes)/ 0(no)";
			break;
		case 10: cout << "Will you play one more? 1(yes)/ 0(no)";
			break;
		default: cout << "err anotherGame() " << theNumber;
			break;
	}
}


//void function that prints one of 10 strings, this is printed after use wins
void winMsg() {
	srand(time(0));
	int theNumber = 1 + (rand() % 10);
	switch (theNumber) {
		case 1: cout << "You guessed right! ";
			break;
		case 2: cout << "Great guess, you won! ";
			break;
		case 3: cout << "Correct! You won! ";
			break;
		case 4: cout << "You won! ";
			break;
		case 5: cout << "Good job, you won !";
			break;
		case 6: cout << "Good job, your guess was correct! ";
			break;
		case 7: cout << "Great job! ";
			break;
		case 8: cout << "Mystic guess! ";
			break;
		case 9: cout << "Awsome work, your guess was correct!";
			break;
		case 10: cout << "Right on, your guess is correct! ";
			break;
		default: cout << "err winMsg " << theNumber;
			break;
	}
}





/// <summary>
/// void function that prints one of 10 strings
/// </summary>
void lossMsg(){
	srand(time(0));
	int theNumber = 1 + (rand() % 10);
	switch (theNumber) {
		case 1: cout << "You lost Game Over! ";
			break;
		case 2: cout << "You lost, very unfortunate ";
			break;
		case 3: cout << "Game Over!";
			break;
		case 4: cout << "A few bad guesses and you lost :(";
			break;
		case 5: cout << "You lost, very unlucky ";
			break;
		case 6: cout << "You lost this round ";
			break;
		case 7: cout << "You failed! ";
			break;
		case 8: cout << "Game Over, you lost ";
			break;
		case 9: cout << "You failed to guess the right number after 20 tries";
			break;
		case 10: cout << "Round over, you lost! ";
			break;
		default: cout << "error with switch lossMsg" << theNumber;
			break;
	}
}


/// <summary>
/// generates a random number and if the user guesses it then the parameter is set to true,
/// otherwise false.  
/// </summary>
/// <returns>
/// returns true or false based on wether the user guessed right or wrong, 
/// automatically false if user fails to guess right after 20 tries.
/// </returns>
bool randNumber(bool theResult) {
	int userInput = - 1;
	srand(time(0));
	int theNumber = 1 + (rand() % 100);

	cout << "Guess the number 1-100, you have 20 tries " << endl;
	cin >> userInput;
	for (int i = 0; i < 19; i++) {
		if (userInput == theNumber) {
			winMsg();
			theResult = true;
			break;
		}
		else if (userInput != theNumber) {
			cout << "You guessed wrong try again " << endl;
			theResult = false;
		}
		cin >> userInput;
	}
	return theResult;
}
