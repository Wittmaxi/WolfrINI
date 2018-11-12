test:
	g++ -g ./*.cpp -o test
	-./test

compile: 
	-mkdir ./build
	g++ -c ./wolfrini.cpp -o ./build/wolfrini.o -O3
	ar rvs ./build/libwolfrini.a ./build/*.o

install: compile
	-sudo mkdir /usr/local/include/wolfrini
	sudo cp ./build/libwolfrini.a /usr/local/lib/libwolfrini.a
	sudo cp ./wolfrini.hpp /usr/local/include/wolfrini/

uninstall:
	sudo rm -r /usr/local/include/wolfrini
	sudo rm /usr/local/lib/libwolfrini.a