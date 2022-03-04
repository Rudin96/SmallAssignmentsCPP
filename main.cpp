#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

//using namespace std;

int absolute(int a, int b)
{
	printf("ABSOLUTE DIFF: \n");
	int diff = a - b;
	if (diff < 0)
		return diff * -1;
	else
		return diff;
}

int celsiusToFahrenheit(int x)
{
	printf("CELSIUS TO FAHRENHEIT: \n");
	return x * 9 / 5 + 32;
}

void checkEvenOrOdd(int v)
{
	printf("CHECK ODD OR EVEN: \n");
	int evenOddStatus = v % 2;
	if (evenOddStatus == 1)
		printf("%i is odd\n", v);
	else 
		printf("%i is even\n", v);
	
}

void getLastDigit()
{
	printf("GET LAST DIGIT: \n");
	std::string v;
	std::cout << "Enter number\n";
	std::cin >> v;
	printf("Last digit is: %c \n", v.at(v.length() - 1));

	printf("Foreach\n");

	for (int i = 0; i < v.length(); i++)
	{
		printf("%c \n", v.at(i));
	}

	printf("Reverse\n");

	for (int i = v.length() - 1; i >= 0; i--)
	{
		printf("%c \n", v.at(i));
	}
}

void pointerSwap(int* a, int* b)
{
	printf("POINTER SWAP: \n");
	int temp = *a;
	*a = *b;
	*b = temp;
	std::cout << (*a) << std::endl;
	std::cout << (*b) << std::endl;
}

void refSwap(int& a, int& b)
{
	printf("REF SWAP: \n");
	int temp = a;
	a = b;
	b = temp;
}

void stlSwap(int& a, int& b)
{
	printf("STL SWAP: \n");
	std::swap(a, b);
}

void guessGame()
{
	printf("GUESSING GAME: \n");
	srand(time(NULL));
	int secretMin, secretMax, secretNumber, guess, attempts;
	secretMin = 1;
	secretMax = 25;
	secretNumber = rand() % secretMax + secretMin;
	guess = 0;
	attempts = 1;

	while (guess != secretNumber)
	{
		std::cout << "Guess the number between: " << secretMin << " and " << secretMax << std::endl;
		std::cin >> guess;

		if (guess < secretMin)
		{
			std::cout << "Guess was lower than min allowed value, please try again!" << std::endl;
			attempts++;
		}
		else if (guess > secretMax)
		{
			std::cout << "Guess was higher than the max allowed value, please try again!" << std::endl;
			attempts++;
		}

		if (guess != secretNumber)
		{
			std::cout << "Wrong number, try again!" << std::endl;
			attempts++;
		}
		else
			std::cout << "Congratulations, you guessed the number correctly which was: " << secretNumber << " with total attempts of: " << attempts << std::endl;
	}
}

void arithmetics()
{
	const int size = 5;
	int arr[size];
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Enter number in to " << i << " position: " << std::endl;
		std::cin >> arr[i];
	}
	
	int startNumber = arr[0];
	int diff;
	for (size_t i = 0; i < size; i++)
	{
		if (i + 1 == size)
			break;
		if (arr[i + 1] - arr[i] != startNumber)
		{
			std::cout << "Array does not have arithmetic progression!" << std::endl;
			break;
		}
		else
		{
			std::cout << "Array has arithmetic progression" << std::endl;
			break;
		}
	}
}

void bitSwap()
{
	int a = 10;
	int b = 20;

	a << b;

	std::cout << a << " " << b << std::endl;
}

int main()
{
	int absA, absB, c, x, y, oddCheck;
	printf("Abs A");
	std::cin >> absA;
	printf("Abs B");
	std::cin >> absB;
	printf("%i is the abs difference value\n", absolute(absA, absB));
	printf("Enter temp in Celsius\n");
	std::cin >> c;
	printf("%i in celsius is %i in Fahrenheit.\n", c, celsiusToFahrenheit(c));
	std::cout << "Enter odd or even number \n";
	std::cin >> oddCheck;
	checkEvenOrOdd(oddCheck);
	getLastDigit();

	std::cout << "Enter x value: " << std::endl;
	std::cin >> x;
	std::cout << "Enter y value: " << std::endl;
	std::cin >> y;

	pointerSwap(&x, &y);
	printf("x is now %i, and y is now %i\n", x, y);
	refSwap(x, y);
	printf("x is now %i, and y is now %i\n", x, y);
	stlSwap(x, y);
	printf("x is now %i, and y is now %i\n", x, y);
	
	guessGame();

	arithmetics();

	bitSwap();

	printf("Press any key to start again!\n");
	std::cin.get();

	main();
}