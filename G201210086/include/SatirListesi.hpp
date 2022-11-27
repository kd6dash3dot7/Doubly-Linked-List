#pragma once
#include "SatirDugumu.hpp"

class SatirListesi
{
public:
	SatirDugumu* baslangic = nullptr;
	SatirDugumu* son = nullptr;

	~SatirListesi();

	void ekle(int deger);
	void cikar(int index);
	int sayi();
	SatirDugumu* getir(int index);

	float ortalama();
};
