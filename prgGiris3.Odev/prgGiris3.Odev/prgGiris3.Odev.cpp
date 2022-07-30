/***************************************************************************
*				                                                           *
*				ÖĞRENCİ ADI ve SOYADI: FATİH DURMAZ                        *
*				ÖĞRENCİ NUMARASI: G191210064                               *
*				DERS GRUBU: 2/B                                            *
****************************************************************************/

#include<iostream>
#include<Windows.h> //Sleep fonksiyonu icin gereklidir.
#include<time.h> //Random deger atamasi icin gereklidir.


using namespace std;

void koordinatGir(int x, int y);
void kursorGizle();

struct sahne
{
	int  sahneninGenisligi;
	int  sahneninYuksekligi;
	char cizimkarakteri;
};

sahne sahneOlustur();
void sahneCiz(sahne s1);

struct lSekli
{
	int  x, y;
	int  lsekliboyutu;
	char cizimkarakteri;
};

lSekli lSekliOlustur();
void lSekliCiz(lSekli l1);
void lSekliSil(sahne s1);
lSekli lSekliAsagiGotur(lSekli l1, sahne s1);

int main()
{
	srand(time(NULL));
	kursorGizle();

	sahne sahne1;
	sahne1 = sahneOlustur();

	lSekli lSekli1;
	lSekli1 = lSekliOlustur();

	//Sahne ve L seklinin cizimini surekli olarak devam ettirir.
	while (true)
	{
		system("cls");

		sahneCiz(sahne1);

		lSekliCiz(lSekli1);

		//L seklini asagiya goturur ve L seklini silip tekrar cizdirir.
		if (lSekli1.y + 2 * lSekli1.lsekliboyutu + 2 < sahne1.sahneninYuksekligi)
		{
			lSekli1 = lSekliAsagiGotur(lSekli1, sahne1);

			Sleep(200);

			lSekliSil(sahne1);

			lSekliCiz(lSekli1);
		}

		//L seklinin sahne sinirlarindan cikmasina engel olur L seklini tekrar olusturur.
		else
		{
			lSekli1 = lSekliOlustur();
		}

		Sleep(100);
	}
}

void koordinatGir(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void kursorGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO  cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

sahne sahneOlustur()
{
	sahne s1;

	do //Sahnenin genisligine 30-40-50 degerlerinden herhangi birini atar.
	{
		s1.sahneninGenisligi = rand() % 21 + 30;

	} while (!(s1.sahneninGenisligi == 30 || s1.sahneninGenisligi == 40 || s1.sahneninGenisligi == 50));

	//Sahnenin genisligine 20 ile 30 arasinda deger atar.
	s1.sahneninYuksekligi = rand() % 11 + 20;

	//Sahneyi olusturan karakteri belirler.
	char karakterSekli[5] = { '*','#', '+', '@', '$' };
	int a = rand() % 5;
	s1.cizimkarakteri = karakterSekli[a];

	return s1;
}

void sahneCiz(sahne s1)
{
	//Sahnenin yatay ust kenarini yapar.
	for (int i = 0; i < s1.sahneninGenisligi; i++)
	{
		cout << s1.cizimkarakteri;
	}
	//Sahnenin dikey sağ kenarini yapar.
	for (int i = 0; i < s1.sahneninYuksekligi; i++)
	{
		koordinatGir(s1.sahneninGenisligi - 1, i);

		cout << s1.cizimkarakteri;
	}
	//Sahnenin yatay alt kenarini yapar.
	for (int i = 0; i < s1.sahneninGenisligi; i++)
	{
		koordinatGir(s1.sahneninGenisligi - i - 1, s1.sahneninYuksekligi - 1);

		cout << s1.cizimkarakteri;
	}
	//Sahnenin dikey sol kenarini yapar.
	for (int i = 0; i < s1.sahneninYuksekligi; i++)
	{
		koordinatGir(0, s1.sahneninYuksekligi - 1 - i);

		cout << s1.cizimkarakteri;
	}
}

lSekli lSekliOlustur()
{
	lSekli lSekli;

	//L seklinin olusturuldugu x koordinatina 5 ile 25 arasında deger atar.
	lSekli.x = rand() % 21 + 5;
	//L seklinin olusturuldugu y koordinatina 3 degerini atar.
	lSekli.y = 3;

	//L seklinin boyutuna 2 ile 7 arasinda deger atar.
	lSekli.lsekliboyutu = rand() % 6 + 2;

	//L seklini olusturan karakteri belirler.
	char karakterSekli[5] = { '*','#', '+', '@', '$' };
	int a = rand() % 5;
	lSekli.cizimkarakteri = karakterSekli[a];

	return lSekli;
}

void lSekliCiz(lSekli l1)
{
	int geciciYkoordinati = l1.y;

	koordinatGir(l1.x, l1.y);
	//L seklinin ust kenarini yapar.
	for (int i = 0; i < l1.lsekliboyutu; i++)
	{
		cout << l1.cizimkarakteri;
	}
	//L seklinin dikey uzun kenarini yapar.
	for (int i = 0; i < 2 * l1.lsekliboyutu + 1; i++)
	{
		koordinatGir(l1.x, l1.y);
		cout << l1.cizimkarakteri;
		l1.y++;
	}

	l1.y = geciciYkoordinati;
	//L seklinin alt kenarini yapar.
	for (int i = 0; i < 2 * l1.lsekliboyutu - 1; i++)
	{
		cout << l1.cizimkarakteri;
	}
	//L seklinin dikey girintisini yapar.
	for (int i = 0; i < l1.lsekliboyutu + 1; i++)
	{
		koordinatGir(l1.x + l1.lsekliboyutu - 1, l1.y);
		cout << l1.cizimkarakteri;
		l1.y++;
	}

	l1.y = geciciYkoordinati;
	//L seklinin yatay girintisini yapar.
	for (int i = 0; i < l1.lsekliboyutu; i++)
	{
		cout << l1.cizimkarakteri;
	}
	//L seklinin dikey kısa kenarini yapar.
	for (int i = 0; i < l1.lsekliboyutu - 1; i++)
	{
		koordinatGir(l1.x + 2 * l1.lsekliboyutu - 1, l1.y + l1.lsekliboyutu + 1);
		cout << l1.cizimkarakteri;
		l1.y++;
	}

	l1.y = geciciYkoordinati;
}

void lSekliSil(sahne s1)
{
	system("cls");

	sahneCiz(s1);
}

lSekli lSekliAsagiGotur(lSekli l1, sahne s1)
{
	l1.y++;

	return l1;
}