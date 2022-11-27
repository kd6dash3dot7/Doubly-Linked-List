/**
* @file smt-odv.cpp
* @description Cift yonlu bagli liste 
* @course Ikinci ogretim C grubu
* @assignment Birinci odev
* @date 27.11.2022
* @author samet.guzel@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

#include "../include/YoneticiListesi.hpp"

int main()
{
	std::ifstream veriler_dosyasi("veriler.txt");
	std::string satir;
	auto yonetici_listesi = new YoneticiListesi;
	while (std::getline(veriler_dosyasi, satir))
	{
		auto satir_listesi = new SatirListesi;
		std::istringstream satir_ss(satir);
		std::string sayi;
		while (std::getline(satir_ss, sayi, ' '))
		{
			satir_listesi->ekle(std::stoi(sayi));
		}
		yonetici_listesi->ekle(satir_listesi);
	}

	int index = 0;
	int index2 = 0;
	bool sil_sec = false;
	srand(time(nullptr));
	while (true)
	{
		system("cls");

		yonetici_listesi->yazdir(index, index2, sil_sec);

		char ch;
		std::cin >> ch;

		if (ch == 'c')
		{
			sil_sec = false;

			if (index2 != 7)
			{
				index2++;
			}
		}
		else if (ch == 'z')
		{
			sil_sec = false;

			if (index2 != 0)
			{
				index2--;
			}
		}
		else if (ch == 'a')
		{
			sil_sec = false;

			if (index >= 8)
			{
				index -= 8;
				index2 = 0;
			}
		}
		else if (ch == 'd')
		{
			sil_sec = false;

			if (yonetici_listesi->sayi() > index + 8)
			{
				index += 8;
				index2 = 0;
			}
		}
		else if (ch == 'p')
		{
			sil_sec = false;

			yonetici_listesi->cikar(index * 8 + index2);
			index = 0;
			index2 = 0;
		}
		else if (!sil_sec && ch == 'k')
		{
			sil_sec = true;
		}
		else if (sil_sec && ch == 'k')
		{
			sil_sec = false;
			yonetici_listesi->secileni_sil();
			index = 0;
			index2 = 0;
		}
	}

	delete yonetici_listesi;

	return 0;
}
