#include <iostream> //нужен для вывода строк "cout<<"
#include "conio.h" //нужен намеренно для "getche()" , а не "cin>>"
#include "windows.h" //библиотека audiere её требует
#include "audiere.h" //сама библиотека
using namespace std;
using namespace audiere; //определяем пространства имён для более короткой записи кода
AudioDevicePtr device = OpenDevice(); //Для начала нужно открыть AudioDevice
OutputStreamPtr SongInMenu = OpenSound(device, "undertale_034.-Memory.wav", false), MenuSound = OpenSound(device, "jg-punch.wav", true); //открываем наш звук
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const int MENU_SIZE = 5;
char Menu[MENU_SIZE][30] = { "Прототип меню", "Выбор1", "Выбор2", "Выбор3", "Выбор4" };
bool FirstSound()
{
	if (!device) {
		cout << "Ошибка открытия AudioDevice. Нажмите любую клавишу для выхода..";
		return 1; //выходим из программы
	}
	if (!SongInMenu || !MenuSound) {
		cout << "Ошибка открытия файла! Для выхода нажмите любую клавишу..";
		return 1;
	}
	return 0;
}
void menu()
{
	int X, choice = 0;
	while (true)
	{
		MenuSound->setPitchShift(5.0);
		MenuSound->setVolume(0.5f);
		SongInMenu->play();
		SongInMenu->setVolume(0.5f);
		for (int i = 0; i < MENU_SIZE; i++)
		{
			if (choice == i)
			{
				SetConsoleTextAttribute(hConsole, 8);
				cout << Menu[i];
				cout << "<=";
				SetConsoleTextAttribute(hConsole, 11);
			}
			else
			{
				cout << Menu[i];
			}
			cout << endl;
		}
		X = _getch();
		switch (X)
		{
		case 119:
			if (choice != 1)
			{
				choice--;
				MenuSound->play();
			}
			break;//Клавиша W
		case 115:
			if (choice != MENU_SIZE - 1)
			{
				choice++;
				MenuSound->play();
			}
			break;//Клавиша S

		}
		system("cls");
	}
}
void DebugClavish()
{
	while (true)
	{
		int a = _getch();
		cout << a << "\t" << (char)a << endl;
	}
}
int main()
{
	system("chcp 1251");
	system("cls");
	if (FirstSound())
	{
		return 0;
	}
	menu();
}