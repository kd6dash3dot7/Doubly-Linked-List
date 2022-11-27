/**
* @file SatirListesi.cpp
* @description Cift yonlu bagli liste 
* @course Ikinci ogretim C grubu
* @assignment Birinci odev
* @date 27.11.2022
* @author samet.guzel@ogr.sakarya.edu.tr
*/
#include "../include/SatirListesi.hpp"

SatirListesi::~SatirListesi()
{
	while (baslangic)
	{
		auto sonraki = baslangic->sonraki;
		delete baslangic;
		baslangic = sonraki;
	}
	son = nullptr;
}

void SatirListesi::ekle(int deger)
{
	auto dugum = new SatirDugumu(deger);
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
}

void SatirListesi::cikar(int index)
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

int SatirListesi::sayi()
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

SatirDugumu* SatirListesi::getir(int index)
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

float SatirListesi::ortalama()
{
	float ort = 0.0f;
	int index = 0;
	auto dugum = baslangic;
	while (dugum)
	{
		index++;
		ort += (dugum->deger - ort) / index;
		dugum = dugum->sonraki;
	}
	return ort;
}
