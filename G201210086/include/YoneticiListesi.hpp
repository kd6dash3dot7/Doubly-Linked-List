#pragma once
#include "YoneticiDugumu.hpp"
#include "SatirListesi.hpp"

class YoneticiListesi
{
public:
	YoneticiDugumu* baslangic = nullptr;
	YoneticiDugumu* son = nullptr;

	~YoneticiListesi();

	void ekle(SatirListesi* deger);
	void cikar(int index);
	int sayi();
	YoneticiDugumu* getir(int index);

	void yazdir(int index, int index2, bool sil_sec);

	void secileni_sil();

private:
	void sirala();
	void sirali_ekle(YoneticiDugumu* deger);

	SatirListesi* secili_liste = nullptr;
	int secili_liste_index = -1;
	int silinecek_dugum = -1;
};
