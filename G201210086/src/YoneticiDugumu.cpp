/**
* @file YoneticiDugumu.cpp
* @description Cift yonlu bagli liste 
* @course Ikinci ogretim C grubu
* @assignment Birinci odev
* @date 27.11.2022
* @author samet.guzel@ogr.sakarya.edu.tr
*/
#include "../include/YoneticiDugumu.hpp"

YoneticiDugumu::YoneticiDugumu(SatirListesi* deger)
	: deger(deger)
{
}

YoneticiDugumu::~YoneticiDugumu()
{
	delete deger;
}
