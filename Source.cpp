#include <windows.h>
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include <ctime>
#include<time.h>
#include "Header.h"

using namespace std;

int score = 0;


void displayScore() {
	gotoxy(30, 0);
	cout << "SCORE: " << score;
}



void print_blue_square(int x, int y)
{
	myRectangle(x + 20, y + 20, x + 60, y + 60, 0, 0, 255, 0, 0, 255);
}

void print_red_square(int x, int y)
{
	myRectangle(x + 20, y + 20, x + 60, y + 60, 255, 0, 0, 255, 0, 0);
}

void print_green_circle(int x, int y)
{
	myEllipse(x + 20, y + 20, x + 60, y + 60, 100, 75, 79, 100, 75, 79);
}

void triangle(int x, int y)
{
	myLine(x + 20, y + 60, x + 40, y + 20, 100);
	myLine(x + 20, y + 60, x + 60, y + 60, 100);
	myLine(x + 40, y + 20, x + 60, y + 60, 100);
}



void myCircle(int x, int y)
{
	myEllipse(x + 20, y + 20, x + 60, y + 60, 255, 255, 0, 255, 255, 0);
}






void print_grid(int arr[][8])
{
	myRectangle(50, 100, 750, 700, 255, 255, 255, 255, 255, 255);
	displayScore();
	gotoxy(1000, 500);



	int x = 60;
	int y = 110;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 0)
				print_blue_square(x + (j * 70), y + (i * 70));

			else if (arr[i][j] == 1)
				print_red_square(x + (j * 70), y + (i * 70));

			else if (arr[i][j] == 2)
				myCircle(x + (j * 70), y + (i * 70));

			else if (arr[i][j] == 3)
				triangle(x + (j * 70), y + (i * 70));
			else
				print_green_circle(x + (j * 70), y + (i * 70));


		}
	}

}


void print_selector(int x, int y)
{
	myLine(x, y, x + 60, y, 100);
	myLine(x, y, x, y + 60, 100);
	myLine(x, y + 60, x + 60, y + 60, 100);
	myLine(x + 60, y + 60, x + 60, y, 100);
}

void blank_print_selector(int x, int y)
{
	myLine(x, y, x + 60, y, 255);
	myLine(x, y, x, y + 60, 255);
	myLine(x, y + 60, x + 60, y + 60, 255);
	myLine(x + 60, y + 60, x + 60, y, 255);
}


bool check_for_three(int arr[][8])
{

	bool changes = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
			{
				score = score + 200;
				arr[i][j] = rand() % 5;
				arr[i][j + 1] = rand() % 5;
				arr[i][j + 2] = rand() % 5;


				system("cls");
				print_grid(arr);

				changes = true;

			}

			else if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j])
			{
				score = score + 200;
				arr[i][j] = rand() % 5;
				arr[i + 1][j] = rand() % 5;
				arr[i + 2][j] = rand() % 5;

				system("cls");
				print_grid(arr);

				changes = true;
			}


		}
	}


	return changes;
}




void check_match(int x, int y, int arr[][8])
{

	if (arr[x][y] == arr[x - 2][y] && arr[x][y] == arr[x - 3][y])
		swap(arr[x][y], arr[x - 1][y]);

	if (arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x - 1][y - 2])
		swap(arr[x][y], arr[x - 1][y]);

	if (arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x - 1][y + 2])
		swap(arr[x][y], arr[x - 1][y]);

	if (arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x - 1][y - 1])
		swap(arr[x][y], arr[x - 1][y]);

	if (arr[x][y] == arr[x + 2][y] && arr[x][y] == arr[x + 3][y])
		swap(arr[x][y], arr[x + 1][y]);

	if (arr[x][y] == arr[x + 1][y + 1] && arr[x][y] == arr[x + 1][y + 2])
		swap(arr[x][y], arr[x + 1][y]);

	if (arr[x][y] == arr[x + 1][y - 1] && arr[x][y] == arr[x + 1][y - 2])
		swap(arr[x][y], arr[x + 1][y]);

	if (arr[x][y] == arr[x + 1][y - 1] && arr[x][y] == arr[x + 1][y + 1])
		swap(arr[x][y], arr[x + 1][y]);

	if (arr[x][y] == arr[x][y + 2] && arr[x][y] == arr[x][y + 3])
		swap(arr[x][y], arr[x][y + 1]);

	if (arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x - 2][y + 1])
		swap(arr[x][y], arr[x][y + 1]);

	if (arr[x][y] == arr[x + 1][y + 1] && arr[x][y] == arr[x + 2][y + 1])
		swap(arr[x][y], arr[x][y + 1]);

	if (arr[x][y] == arr[x - 1][y + 1] && arr[x][y] == arr[x + 1][y + 1])
		swap(arr[x][y], arr[x][y + 1]);

	if (arr[x][y] == arr[x][y - 2] && arr[x][y] == arr[x][y - 3])
		swap(arr[x][y], arr[x][y - 1]);

	if (arr[x][y] == arr[x + 1][y - 1] && arr[x][y] == arr[x + 2][y - 1])
		swap(arr[x][y], arr[x][y - 1]);

	if (arr[x][y] == arr[x - 1][y - 1] && arr[x][y] == arr[x - 2][y - 1])
		swap(arr[x][y], arr[x][y - 1]);

	if (arr[x][y] == arr[x + 1][y - 1] && arr[x][y] == arr[x - 1][y - 1])
		swap(arr[x][y], arr[x][y - 1]);





}

int main()
{

	myRectangle(50, 100, 750, 700, 255, 255, 255, 255, 255, 255);

	srand(time(0));

	int arr[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = rand() % 5;
		}
	}

	print_grid(arr);






	int index1 = 0, index2 = 0;

	while (score < 5000)
	{



		while (check_for_three(arr))
		{

		}

		print_selector(70 + (index2 * 70), 120 + (index1 * 70));

		int k = _getch();

		int j = k;

		if (isCursorKeyPressed(k) || j == 13)

		{
			if (k == 1)
			{
				blank_print_selector(70 + (index2 * 70), 120 + (index1 * 70));
				index2--;
				print_selector(70 + (index2 * 70), 120 + (index1 * 70));
			}

			else if (k == 2)
			{
				blank_print_selector(70 + (index2 * 70), 120 + (index1 * 70));
				index1--;
				print_selector(70 + (index2 * 70), 120 + (index1 * 70));
			}

			else if (k == 3)
			{
				blank_print_selector(70 + (index2 * 70), 120 + (index1 * 70));
				index2++;
				print_selector(70 + (index2 * 70), 120 + (index1 * 70));
			}

			else if (k == 4)
			{
				blank_print_selector(70 + (index2 * 70), 120 + (index1 * 70));
				index1++;
				print_selector(70 + (index2 * 70), 120 + (index1 * 70));
			}

			else if (j == 13)
			{
				check_match(index1, index2, arr);
				system("cls");
				print_grid(arr);
				Sleep(500);

				system("cls");
				print_grid(arr);


			}
		}
	}

	Sleep(2000);
	system("cls");


	if (score < 5000)
		cout << "YOU lost";

	else
		cout << "YOU won";
}