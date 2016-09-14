/*  Taylor Jenkins
	03-29-16
	CIT 213-875
	Ch. 6 Ex. 11 
	Part II         */

/* This program calculates the average of a group of test scores, where the lowest 
score in the group is dropped.*/

#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

//Prototypes:
void getScore(int &score);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);


//*****************************************
// Function main                          *
//*****************************************
int main()
{
	//Variables:
	int score1 = 0, 
	    score2 = 0, 
		score3 = 0, 
		score4 = 0, 
		score5 = 0;

	//get the scores from the user
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	//calculate average
	calcAverage(score1, score2, score3, score4, score5);

	system("PAUSE");
	return 0;
}

//*****************************************
// Definition of function void getScore() * 
// ask the user for a test score store it *
// in a reference parameter variable      *
// and validate it .This function is      *
// called by main once for each of the    * 
//five scores to be entered               *
//*****************************************
void getScore(int &score)
{
	cout << "Enter a test score (Please enter a value between 1 and 100) : ";
	cin >> score;
	while (score < 1 || score > 100)
	{
		cout << "\n\nERROR: Please enter Test score values 0 to 100! ";
		cout << "\nEnter a valid test score: ";
		cin >> score;
	}
}

//*****************************************
// Definition of function int findLowest()*
// Finds and returns the lowest of the    *
// five scores passed to it. It is called *
// by function void calcAverage.          *
//*****************************************
int findLowest(int score1, int score2, int score3, int score4, int score5)
{
	int lowest;

	if (score1 > score5 && score2 > score5 && score3 > score5 && score4 > score5)
	{
		lowest = score5;
	}
	else if (score1 > score4 && score2 > score4 && score3 > score4 && score5 > score4)
	{
		lowest = score4;
	}
	else if (score1 > score3 && score2 > score3 && score4 > score3 && score5 > score3)
	{
		lowest = score3;
	}
	else if (score1 > score2 && score3 > score2 && score4 > score2 && score5 > score2)
	{
		lowest = score2;
	}
	else if (score2 > score1 && score3 > score1 && score4 > score1 && score5 > score1)
	{
		lowest = score1;
	}

	return lowest;
}

//*****************************************
// Definition of function void calcAverage*
// calculates and displays the average of *
// the four highest scores. This function *
// is called just once by main and is     *
// passed the five test scores.           *
//*****************************************
void calcAverage(int score1, int score2, int score3, int score4, int score5)
{
	double lowest = findLowest(score1, score2, score3, score4, score5);
	double average = (((double)score1 + (double)score2 + (double)score3 + (double)score4 + (double)score5) - lowest) / 4;

	cout << fixed << showpoint << setprecision(2);
	cout << "The average of the highest scores is " << average << "\n\n";
}