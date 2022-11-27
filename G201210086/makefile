derlecalistir:program calistir
program:kutuphane main
	g++ ./lib/SatirDugumu.o ./lib/SatirListesi.o ./lib/YoneticiDugumu.o ./lib/YoneticiListesi.o ./lib/smt-odv.o -o ./bin/program

kutuphane:
	g++ -I "./include" -c ./src/SatirDugumu.cpp -o ./lib/SatirDugumu.o
	g++ -I "./include" -c ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -I "./include" -c ./src/YoneticiDugumu.cpp -o ./lib/YoneticiDugumu.o
	g++ -I "./include" -c ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o

main:
	g++ -I "./include" -c ./src/smt-odv.cpp -o ./lib/smt-odv.o 

calistir:
	./bin/program