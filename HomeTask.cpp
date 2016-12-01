		Листинг номер 1 "Исходный код программы"

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <conio.h>


int XOR( int a, int gamma)
{
			return (a ^ gamma);
}


int Cyclic_shift(int a_gamma)
{
			return ((a_gamma >> 5) | (a_gamma << 3));
}


int Reverse_Cyclic_Shift(int a_res)
{
			return ((a_res >> 3) | (a_res << 5));
}


int Reverse_XOR(int a_pre_gamma, int gamma) {
			return (a_pre_gamma ^ gamma);
}


using namespace std;
int main()
{
					char TEXT[256];
					int key;
					cout << "Input: " << endl;
					cin.getline(TEXT, 256);
					cout << "Input key: " << endl;
					cin >> key;
					cin.clear();
					srand(key);

					int gamma = rand() % 128;
					int n = 0;


					for (unsigned int i = 0; TEXT[i] != '\0'; ++i)
					{
								n++;
					}

					char *Input_message = (char *)malloc(n * sizeof(char));
					for (unsigned int i = 0; i < n; ++i)
					{
						Input_message[i] = TEXT[i];
					}

					int *buffer = (int *)malloc(n * sizeof(int));
					cout << "XOR: " << endl;
					for (unsigned int i = 0; i < n; ++i)
					{
							buffer[i] = XOR(Input_message[i], gamma);
							putchar(buffer[i]);
					}
					cout << "Cyclic shift: "<< endl;
					for (unsigned int i = 0; i < n; ++i)
					{
							buffer[i] = Cyclic_shift(buffer[i]);
							putchar(buffer[i]);
					}
					cout << "Reverse cyclic shift: "<< endl;
					for (unsigned int i = 0; i < n; ++i)
					{
							buffer[i] = Reverse_Cyclic_Shift(buffer[i]);
							putchar(buffer[i]);
					}
					cout << "Reverse XOR: "<< endl;
					for (unsigned int i = 0; i < n; ++i)
					{
							buffer[i] = Reverse_XOR(buffer[i], gamma);
							putchar(buffer[i]);
					}
					cout << "\n\n";
					cout << "Press any button to exit " << endl;
					_getch();
						return 0;
}
