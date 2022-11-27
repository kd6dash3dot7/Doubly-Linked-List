#pragma once
#include "SatirListesi.hpp"

class YoneticiDugumu
{
public:
	YoneticiDugumu* onceki = nullptr;
	SatirListesi* deger;
	YoneticiDugumu* sonraki = nullptr;

	YoneticiDugumu(SatirListesi* deger);

	~YoneticiDugumu();
};
