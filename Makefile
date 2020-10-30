__start__: obj conv __plugin__
	export LD_LIBRARY_PATH="./libs"; echo;./conv plik.txt plik2.txt

obj:
	mkdir obj

__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -g -pedantic -std=c++11 -Iinc 
LDFLAGS=-Wall

conv: obj/main.o 						 obj/Parser.o obj/LibraryInterface.o  obj/PluginManager.o  obj/Conversion.o  
	g++ ${LDFLAGS} -o interp  obj/main.o obj/Parser.o obj/LibraryInterface.o  obj/PluginManager.o  obj/Conversion.o -ldl

obj/main.o: src/main.cpp inc/Simulation.hh inc/Cuboid.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Parser.o: src/Parser.cpp inc/Parser.hh
	g++ -c ${CPPFLAGS} -o obj/Parser.o src/Parser.cpp

obj/LibraryInterface.o: src/LibraryInterface.cpp inc/LibraryInterface.hh inc/Interp4Command.hh
	g++ -c ${CPPFLAGS} -o obj/LibraryInterface.o src/LibraryInterface.cpp

obj/PluginManager.o: src/PluginManager.cpp inc/PluginManager.hh inc/LibraryInterface.hh inc/Scene.hh
	g++ -c ${CPPFLAGS} -o obj/PluginManager.o src/PluginManager.cpp

obj/Conversion.o: src/Conversion.cpp inc/Conversion.hh inc/Conversion.hh inc/Conversion.hh inc/Conversion.hh
	g++ -c ${CPPFLAGS} -o obj/Simulation.o src/Simulation.cpp

clean:
	rm -f obj/* interp core*


clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
 
