#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <cmath>
#include <ctime>


using namespace std;

int power(int i)
{
	return pow(2, i);
}



int main()
{
	string bit;
	int bit_n;
	bool good();
	string only_ones[8] = {"1","1","1","1","1","1","1","1"};
	int mask_1;
	int i;
	int licznik = 0;
	int licznik_caly=0;
	int changes;
	string binary;
	string binary_mask;
	bitset<8> parzystosc;
	double ile = 0;
	double blad = 0.1;
	double ilosc_bl=0;
	int znak_zmiana;
	int znaczek;


	ifstream txt;
	txt.open("SSS.txt", ios::binary);

	ofstream txt_n;
	txt_n.open("SSS_n.txt", ios::binary);

	if (txt.good() == true)
	{
		cout << "Wszystko ok. Plik otwarty." << endl;
		//tu operacje na pliku
	}
	else cout << "Coœ z plikiem pierwotnym!" << endl;

	if (txt_n.good() == true)
	{
		cout << "Wszystko ok. Nowy plik otwarty." << endl;
		//tu operacje na pliku
	}
	else cout << "Coœ z plikiem docelowym!" << endl;
	cout << endl;


	int ktory_program;
	int wariant;
	cout << "Ktory program chcesz uruchomic? (1,2,3)" << endl;
	cin >> ktory_program;
	if (ktory_program == 1)
	{
		cout << "Jaki blad w %? " << endl;
		cin >> blad;
		cout << "Z powtorzeniami(1) czy bez(2)?" << endl;
		cin >> wariant;
	}

	if (ktory_program == 1)
	{
		int ch;
		while ((ch = txt.get()) != EOF)
		{
			txt.seekg(-1, ios::cur);//indykator w lewo
			bit_n = txt.get();
			//istream & seekg(streamoff offset, ios_base::seekdir cur);// o ile i kierunek
			txt.seekg(-1, ios::cur);//indykator w lewo
			bit = txt.get();
			txt_n << bit; // T U   J E S T    B L A D
			txt_n.flush();
			//cout << bit;




			binary = bitset<8>(bit_n).to_string();
			licznik = 0;
			ile += 1;

			for (i = 0; i < 8; i++)
			{
				mask_1 = power(i);

				binary_mask = bitset<8>(mask_1).to_string();
				parzystosc = bitset<8>(mask_1) & bitset<8>(bit_n);
				changes = (int)(parzystosc.to_ulong());

				if (changes > 0)
				{
					licznik += 1;
				}
				//cout << "Parzystosc" << endl;
				//cout << parzystosc << endl << endl;
			/*	if (i == 7) {
					cout << "Binarna maska" << endl;
					cout << binary_mask << endl << endl;
				}
				*/
			}

			licznik = licznik % 2;
			//cout << licznik << " to liczba licznika" << endl << endl;




			if (licznik > 0)
			{
				licznik_caly += 1;
			}
			else if (licznik == 0)
			{
			}
		}

		txt_n << "." << licznik_caly;

		int licznik_caly_przed = licznik_caly;


		cout << "Przed" << endl;
		cout << bit_n << endl << endl;
		cout << "Przed w stringu" << endl;
		cout << bit << endl << endl;
		cout << "Po" << endl;
		cout << binary << endl << endl;
		cout << "Suma jedynek" << endl;
		cout << licznik_caly << endl << endl;


		string koncowka;
		int dlugosc_koncowki;
		koncowka = to_string(licznik_caly);
		dlugosc_koncowki = koncowka.length();
		cout << "Dlugoœæ koncowki to: " << dlugosc_koncowki << endl;

		ile = ile + 1 + dlugosc_koncowki;



		txt.seekg(0, ios::beg);
		ilosc_bl = ceil(ile*(blad / 100));
		cout << "Ilosc bledow to: " << ilosc_bl << endl;
		//0.1% to 0.1/100
		cout << ile << " ile jest znakow ogolnie" << endl << blad << " to blad w procentach" << endl;
		//ilosc_bl = 20;
		i = ilosc_bl;
		int ilosc_znakow = ile;
		int x;


		char *nowe;//buffer do malloca
		nowe = (char*)malloc(i + 1);
		int *do_zaklocen = new int[i + 1];
		srand(time(NULL));

		bool *bez_powtorzen = new bool[ilosc_znakow];

		int s;
		for (s = 0; s < ilosc_znakow; s++)
		{
			bez_powtorzen[s] = false;
		}


		if (nowe == NULL)
			exit(1);

		//char roboczy2;
		txt.seekg(0, ios::beg);


		cout << endl << endl;


		for (x = 0; x < i; x++)
		{
			txt.clear();//wazne dla szukania bo dostaje do eof
			znak_zmiana = rand() % ilosc_znakow;//dodac jeszcze liczba
			znak_zmiana += 1;
			cout << "Znak do zmiany: " << znak_zmiana << endl;//tablica od 0

			if (wariant == 1)
			{
				while ((bez_powtorzen[znak_zmiana - 1] == true))
				{
					znak_zmiana = rand() % ilosc_znakow;//dodac jeszcze liczba
					znak_zmiana += 1;
				}
			}
			do_zaklocen[x] = znak_zmiana;


			txt.seekg(znak_zmiana - 1, ios::beg);

			bit_n = rand() % 8;
			cout << "Jego bit do zmiany: " << bit_n + 1 << endl;

			mask_1 = power(bit_n);
			znaczek = txt.get();
			//cout << "Wczytany znak to: " << roboczy2 << endl;
			//znaczek = (int)roboczy2;
			//cout << "To znaczek: " << znaczek << endl;
			txt.seekg(-1, ios::cur);
			parzystosc = bitset<8>(mask_1) & bitset<8>(znaczek);
			//cout << "Czy parzysty" << parzystosc << endl;
			changes = (int)(parzystosc.to_ulong());
			//cout << "Dodana potega to: " << power(bit_n) << " a znak to: " << znaczek << endl;

			if (changes > 0)
			{
				nowe[x + 1] = znaczek - power(bit_n);
			}
			else
			{
				nowe[x + 1] = znaczek + power(bit_n);
			}
			bez_powtorzen[znak_zmiana - 1] = true;
			//cout << "Nowy wstawiany znak to: " << nowe[x+1] << "Zamieniony z: " << znaczek << endl;
		}

		cout << endl << endl;


		int tymczasowa, j;

		//int *tablica = new int[ilosc_bl]; // dynamicznie

		for (x = 1; x < ilosc_bl; x++)
		{
			tymczasowa = do_zaklocen[x];
			for (j = x - 1; j >= 0; j--)
			{
				if (tymczasowa < do_zaklocen[j])
					do_zaklocen[j + 1] = do_zaklocen[j];
				else
					break;
			}
			do_zaklocen[j + 1] = tymczasowa;
		}

		for (x = 0; x < ilosc_bl; x++)
			cout << "tablica[" << x << "] = " << do_zaklocen[x] << endl;


		txt_n.close();

		ifstream do_zaklocenia;
		do_zaklocenia.open("SSS_n.txt", ios::binary);
		ofstream zaklocone;
		zaklocone.open("zaklocone.txt", ios::binary);

		string roboczy;
		int nkonwert = 0;//dodane

		//zaklocenia.seekg(0, ios::beg);
		for (i = 0; i < ilosc_bl; i++)
		{
			//for (x = 0; x < do_zaklocen[i]; x++)
			for (x = 0; x < do_zaklocen[i] - 1 - nkonwert; x++)
			{
				roboczy = do_zaklocenia.get();
				zaklocone << roboczy;
			}
			roboczy = do_zaklocenia.get();//przesuwa o 1 z kazdym kolejnym
			nkonwert = do_zaklocen[i];
			zaklocone << nowe[i + 1];
		}

		while ((ch = do_zaklocenia.get()) != EOF)
		{
			do_zaklocenia.seekg(-1, ios::cur);//indykator w lewo
			bit = do_zaklocenia.get();
			zaklocone << bit;
		}


		//free(do_zaklocen);
		free(nowe);
		zaklocone.close();
		do_zaklocenia.close();
		txt.close();
		txt_n.close();
		zaklocone.close();
		delete[] bez_powtorzen;
		delete[] do_zaklocen;


		ifstream sprawdzanie;
		sprawdzanie.open("zaklocone.txt", ios::binary);
		int kropka = 0;
		int a = 0;
		int length = 0;

		sprawdzanie.seekg(0, ios_base::end);
		length = sprawdzanie.tellg();

	
		sprawdzanie.seekg(0, ios::beg);
		licznik_caly = 0;

		int g;
		for (g = 0; g < length - (dlugosc_koncowki+1); g++)
		{
			bit_n = sprawdzanie.get();
			//cout << bit_n << endl;
			binary = bitset<8>(bit_n).to_string();
			licznik = 0;

			for (i = 0; i < 8; i++)
			{
				mask_1 = power(i);

				binary_mask = bitset<8>(mask_1).to_string();
				parzystosc = bitset<8>(mask_1) & bitset<8>(bit_n);
				changes = (int)(parzystosc.to_ulong());

				if (changes > 0)
				{
					licznik += 1;
				}
			}

			licznik = licznik % 2;

			if (licznik > 0)
			{
				//cout << "Parzysta" << endl;
				licznik_caly += 1;
			}
		}
		cout << "Parzystosc przed zakloceniami: " << licznik_caly_przed << endl;
		cout << "Parzystosc po zakloceniach: " << licznik_caly << endl;
	}






	//----------------------------------------------------------------------------------------------------------------------------------------//






	if (ktory_program == 2)
	{

		cout << "Jaki dlugi ma byc blok danych? (8bit, 16bit etc...)" << endl;
		int blok;
		cin >> blok;
		long int suma_kontrolna=0;
		int ch;
		int dzielnik;
		dzielnik = power(blok);//to nasz dzielnik
		bool czy_parzy = true;
		int bit_n2;
		string bit2;
		long int szesnastka;
		bitset<16> szesc;
		int petla = 0;

		while ((ch = txt.get()) != EOF)
		{
			txt.seekg(-1, ios::cur);
			bit_n = txt.get();
			txt.seekg(-1, ios::cur);
			bit = txt.get();
			txt_n << bit;
			txt_n.flush();

			if ((ch = txt.get()) != EOF)
			{
				txt.seekg(-1, ios::cur);
				bit_n2 = txt.get();
				txt.seekg(-1, ios::cur);
				bit2 = txt.get();
				txt_n << bit2;
				txt_n.flush();
				ile += 1;
			}
			else
			{
				bit_n2 = 0;
			}

			ile += 1;
					szesc=(bitset<8>(bit_n).to_ulong() << bitset<8>(bit_n).size() | bitset<8>(bit_n2).to_ulong());
					szesnastka = (int)(szesc.to_ulong());
					cout << "Szesnastka: " << szesnastka << endl;
					suma_kontrolna = (suma_kontrolna + szesnastka) % dzielnik;
					petla++;
		}
		txt_n << "." << suma_kontrolna;
		cout << "Suma kontrolna: " << endl;
		cout << suma_kontrolna << endl << endl;







		string koncowka;
		int dlugosc_koncowki;
		koncowka = to_string(suma_kontrolna);
		dlugosc_koncowki = koncowka.length();
		cout << "Dlugoœæ koncowki to: " << dlugosc_koncowki << endl;

		ile = ile + 1 + dlugosc_koncowki;

		cout << "Jaki blad?" << endl;
		cin >> blad;


		txt.seekg(0, ios::beg);
		ilosc_bl = ceil(ile*(blad / 100));
		cout << "Ilosc bledow to: " << ilosc_bl << endl;
		//0.1% to 0.1/100
		cout << ile << " ile jest znakow ogolnie" << endl << blad << " to blad w procentach" << endl;
		//ilosc_bl = 20;
		i = ilosc_bl;
		int ilosc_znakow = ile;
		int x;


		char *nowe;//buffer do malloca
		nowe = (char*)malloc(i + 1);
		int *do_zaklocen = new int[i + 1];
		srand(time(NULL));

		bool *bez_powtorzen = new bool[ilosc_znakow];

		int s;
		for (s = 0; s < ilosc_znakow; s++)
		{
			bez_powtorzen[s] = false;
		}


		if (nowe == NULL)
			exit(1);

		//char roboczy2;
		txt.seekg(0, ios::beg);


		cout << endl << endl;


		//---------------------------------------------------------------------------------------------//










		for (x = 0; x < i; x++)
		{
			txt.clear();//wazne dla szukania bo dostaje do eof
			znak_zmiana = rand() % ilosc_znakow;//dodac jeszcze liczba
			znak_zmiana += 1;
			cout << "Znak do zmiany: " << znak_zmiana << endl;//tablica od 0

			if (wariant == 1)
			{
				while ((bez_powtorzen[znak_zmiana - 1] == true))
				{
					znak_zmiana = rand() % ilosc_znakow;//dodac jeszcze liczba
					znak_zmiana += 1;
				}
			}
			do_zaklocen[x] = znak_zmiana;


			txt.seekg(znak_zmiana - 1, ios::beg);

			bit_n = rand() % 8;
			cout << "Jego bit do zmiany: " << bit_n + 1 << endl;

			mask_1 = power(bit_n);
			znaczek = txt.get();
			//cout << "Wczytany znak to: " << roboczy2 << endl;
			//znaczek = (int)roboczy2;
			//cout << "To znaczek: " << znaczek << endl;
			txt.seekg(-1, ios::cur);
			parzystosc = bitset<8>(mask_1) & bitset<8>(znaczek);
			//cout << "Czy parzysty" << parzystosc << endl;
			changes = (int)(parzystosc.to_ulong());
			//cout << "Dodana potega to: " << power(bit_n) << " a znak to: " << znaczek << endl;

			if (changes > 0)
			{
				nowe[x + 1] = znaczek - power(bit_n);
			}
			else
			{
				nowe[x + 1] = znaczek + power(bit_n);
			}
			bez_powtorzen[znak_zmiana - 1] = true;
			//cout << "Nowy wstawiany znak to: " << nowe[x+1] << "Zamieniony z: " << znaczek << endl;
		}

		cout << endl << endl;


		int tymczasowa, j;

		//int *tablica = new int[ilosc_bl]; // dynamicznie

		for (x = 1; x < ilosc_bl; x++)
		{
			tymczasowa = do_zaklocen[x];
			for (j = x - 1; j >= 0; j--)
			{
				if (tymczasowa < do_zaklocen[j])
					do_zaklocen[j + 1] = do_zaklocen[j];
				else
					break;
			}
			do_zaklocen[j + 1] = tymczasowa;
		}

		for (x = 0; x < ilosc_bl; x++)
			cout << "tablica[" << x << "] = " << do_zaklocen[x] << endl;


		txt_n.close();

		ifstream do_zaklocenia;
		do_zaklocenia.open("SSS_n.txt", ios::binary);
		ofstream zaklocone;
		zaklocone.open("zaklocone.txt", ios::binary);

		string roboczy;
		int nkonwert = 0;//dodane

						 //zaklocenia.seekg(0, ios::beg);
		for (i = 0; i < ilosc_bl; i++)
		{
			//for (x = 0; x < do_zaklocen[i]; x++)
			for (x = 0; x < do_zaklocen[i] - 1 - nkonwert; x++)
			{
				roboczy = do_zaklocenia.get();
				zaklocone << roboczy;
			}
			roboczy = do_zaklocenia.get();//przesuwa o 1 z kazdym kolejnym
			nkonwert = do_zaklocen[i];
			zaklocone << nowe[i + 1];
		}

		while ((ch = do_zaklocenia.get()) != EOF)
		{
			do_zaklocenia.seekg(-1, ios::cur);//indykator w lewo
			bit = do_zaklocenia.get();
			zaklocone << bit;
		}


		//free(do_zaklocen);
		free(nowe);
		zaklocone.close();
		do_zaklocenia.close();
		txt.close();
		txt_n.close();
		zaklocone.close();
		delete[] bez_powtorzen;
		delete[] do_zaklocen;


		ifstream sprawdzanie;
		sprawdzanie.open("zaklocone.txt", ios::binary);
		int kropka = 0;
		int a = 0;
		int length = 0;

		sprawdzanie.seekg(0, ios_base::end);
		length = sprawdzanie.tellg();

		suma_kontrolna = 0;
		sprawdzanie.seekg(0, ios::beg);

		int g;
		//for (g = 0; g < length - (dlugosc_koncowki + 1); g++)
		for (g=0; g<petla;g++)
		{
				bit_n = sprawdzanie.get();

				if ((ch = sprawdzanie.get()) != EOF)
				{
					sprawdzanie.seekg(-1, ios::cur);
					bit_n2 = sprawdzanie.get();
				}
				else
				{
					bit_n2 = 0;
				}

				szesc = (bitset<8>(bit_n).to_ulong() << bitset<8>(bit_n).size() | bitset<8>(bit_n2).to_ulong());
				szesnastka = (int)(szesc.to_ulong());
				cout << "Szesnastka: " << szesnastka << endl;
				suma_kontrolna = (suma_kontrolna + szesnastka) % dzielnik;
			}
		cout << "Suma kontrolna: " << endl;
		cout << suma_kontrolna << endl << endl;
		cout << "Parzystosc po zakloceniach: " << licznik_caly << endl;





		}

		



	
	


	system("PAUSE");
	return 0;
}