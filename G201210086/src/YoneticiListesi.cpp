/**
* @file YoneticiListesi.cpp
* @description Cift yonlu bagli liste 
* @course Ikinci ogretim C grubu
* @assignment Birinci odev
* @date 27.11.2022
* @author samet.guzel@ogr.sakarya.edu.tr
*/
#include "../include/YoneticiListesi.hpp"

#include <iomanip>
#include <iostream>

YoneticiListesi::~YoneticiListesi()
{
	while (baslangic)
	{
		auto sonraki = baslangic->sonraki;
		delete baslangic;
		baslangic = sonraki;
	}
	son = nullptr;
}

void YoneticiListesi::ekle(SatirListesi* deger)
{
	auto dugum = new YoneticiDugumu(deger);
	dugum->onceki = nullptr;
	dugum->sonraki = nullptr;

	if (!baslangic)
	{
		baslangic = dugum;
		son = baslangic;
	}
	else
	{
		dugum->onceki = son;
		son->sonraki = dugum;
		son = dugum;
	}

	sirala();
}

void YoneticiListesi::yazdir(int index, int index2, bool sil_sec)
{
	YoneticiDugumu* yazdirilacaklar[8];
	bool son_var = false;
	int son_index = 0;
	for (int i = 0; i < 8; i++)
	{
		yazdirilacaklar[i] = getir(index + i);
		son_index++;
		if (yazdirilacaklar[i] == son)
		{
			son_var = true;
			break;
		}
	}

	if (index == 0)
	{
		std::cout << "ilk";
	}
	else
	{
		std::cout << "<--";
	}

	if (son_var)
	{
		std::cout << std::right << std::setw(13 * son_index - 6) << std::setfill(' ') << "son";
	}
	else
	{
		std::cout << std::right << std::setw(13 * son_index - 6) << std::setfill(' ') << "-->";
	}
	std::cout << std::endl;

	for (int i = 0; i < son_index; i++)
	{
		std::cout << " " << yazdirilacaklar[i] << " " << "   ";
	}
	std::cout << std::endl;

	for (int i = 0; i < son_index; i++)
	{
		std::cout << "----------" << "   ";
	}
	std::cout << std::endl;

	for (int i = 0; i < son_index; i++)
	{
		std::cout << "|" << yazdirilacaklar[i]->onceki << "|" << "   ";
	}
	std::cout << std::endl;

	for (int i = 0; i < son_index; i++)
	{
		std::cout << "----------" << "   ";
	}
	std::cout << std::endl;

	for (int i = 0; i < son_index; i++)
	{
		std::cout << "|" << std::right << std::setw(8) << std::setfill(' ') << yazdirilacaklar[i]->deger->ortalama() << "|" << "   ";
	}
	std::cout << std::endl;

	for (int i = 0; i < son_index; i++)
	{
		std::cout << "----------" << "   ";
	}
	std::cout << std::endl;

	for (int i = 0; i < son_index; i++)
	{
		std::cout << "|" << yazdirilacaklar[i]->sonraki << "|" << "   ";
	}
	std::cout << std::endl;

	for (int i = 0; i < son_index; i++)
	{
		std::cout << "----------" << "   ";
	}
	std::cout << std::endl;

	if (index2 == 0)
	{
		std::cout << "^^^^^^^^^^";
	}
	else
	{
		std::cout << std::right << std::setw(13 * index2 + 10) << std::setfill(' ') << "^^^^^^^^^^";
	}
	std::cout << std::endl;

	auto yazdirilacak_dugum = yazdirilacaklar[index2];
	auto yazdirilacak_deger = yazdirilacak_dugum->deger->baslangic;
	int yazdirma_index = 0;
	if (!sil_sec)
	{
		secili_liste_index = -1;
		secili_liste = nullptr;
		silinecek_dugum = -1;
	}
	else
	{
		secili_liste_index = index * 8 + index2;
		secili_liste = yazdirilacak_dugum->deger;
		silinecek_dugum = rand() % yazdirilacak_dugum->deger->sayi();
	}
	while (yazdirilacak_deger)
	{
		std::cout << std::endl;
		std::cout << std::right << std::setw(13 * index2 + 1) << std::setfill(' ') << "|" << yazdirilacak_deger << "|";
		std::cout << std::endl;
		std::cout << std::right << std::setw(13 * index2 + 10) << std::setfill(' ') << "----------";
		std::cout << std::endl;
		std::cout << std::right << std::setw(13 * index2 + 1) << std::setfill(' ') << "|" << std::right << std::setw(8) << std::setfill(' ') << yazdirilacak_deger->deger << "|";
		std::cout << std::endl;
		std::cout << std::right << std::setw(13 * index2 + 10) << std::setfill(' ') << "----------";
		if (silinecek_dugum == yazdirma_index)
		{
			std::cout << "   " << "<-- silinecek secili";
		}
		std::cout << std::endl;
		std::cout << std::right << std::setw(13 * index2 + 1) << std::setfill(' ') << "|" << yazdirilacak_deger->sonraki << "|";
		std::cout << std::endl;
		yazdirilacak_deger = yazdirilacak_deger->sonraki;
		yazdirma_index++;
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

void YoneticiListesi::secileni_sil()
{
	secili_liste->cikar(silinecek_dugum);
	if (secili_liste->sayi() == 0)
	{
		cikar(secili_liste_index);
	}
	sirala();
}

YoneticiDugumu* YoneticiListesi::getir(int index)
{
	auto item = baslangic;
	for (int i = 0; i < index; i++)
	{
		if (!item)
		{
			return nullptr;
		}

		item = item->sonraki;
	}

	return item;
}

void YoneticiListesi::cikar(int index)
{
	auto item = baslangic;
	for (int i = 0; i < index; i++)
	{
		if (!item)
		{
			return;
		}

		item = item->sonraki;
	}

	if (item == baslangic)
	{
		if (baslangic->sonraki)
		{
			baslangic->sonraki->onceki = nullptr;
		}
		baslangic = baslangic->sonraki;
	}
	else if (item == son)
	{
		son->onceki->sonraki = nullptr;
		son = son->onceki;
	}
	else
	{
		item->onceki->sonraki = item->sonraki;
		item->sonraki->onceki = item->onceki;
	}

	delete item;
}

int YoneticiListesi::sayi()
{
	int sayi = 0;
	auto item = baslangic;
	while (item)
	{
		sayi++;
		item = item->sonraki;
	}
	return sayi;
}

void YoneticiListesi::sirala()
{
	auto sirali_liste = new YoneticiListesi;

	auto item = baslangic;
	while (item)
	{
		auto sonraki = item->sonraki;

		item->onceki = nullptr;
		item->sonraki = nullptr;

		sirali_liste->sirali_ekle(item);

		item = sonraki;
	}

	*this = *sirali_liste;
	sirali_liste->baslangic = nullptr;
	delete sirali_liste;
}

void YoneticiListesi::sirali_ekle(YoneticiDugumu* deger)
{
	auto dugum = deger;

	if (!baslangic)
	{
		baslangic = dugum;
		son = baslangic;
	}
	else if (baslangic->deger->ortalama() >= dugum->deger->ortalama())
	{
		dugum->sonraki = baslangic;
		baslangic->onceki = dugum;
		if (son == dugum)
		{
			baslangic->sonraki = nullptr;
			son = baslangic;
		}
		baslangic = dugum;
	}
	else
	{
		auto item = baslangic;

		while (item->sonraki && item->sonraki->deger->ortalama() < dugum->deger->ortalama())
		{
			item = item->sonraki;
		}

		dugum->sonraki = item->sonraki;

		if (!dugum->sonraki)
		{
			son = dugum;
		}
		else
		{
			dugum->sonraki->onceki = dugum;
		}

		item->sonraki = dugum;
		dugum->onceki = item;
	}
}
