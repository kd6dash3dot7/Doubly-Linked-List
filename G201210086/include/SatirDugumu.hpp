#pragma once

class SatirDugumu
{
public:
	SatirDugumu* onceki = nullptr;
	int deger;
	SatirDugumu* sonraki = nullptr;

	SatirDugumu(int deger);
};
