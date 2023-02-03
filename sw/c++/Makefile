.DELETE_ON_ERROR:
#Can temporarily prevent deleting on error when an old version of the program currently works but new one probably doesn't.

#The include just does a few defines like CXX=g++ -std=c++17
#include /home2/usr/local/make/include1
CXX=g++ -std=c++17

#preprocessor debug options: -D to #DEFINE and -g to assist valgrind. 
debug=-D DEBUG -g

#BGp is an acronym for Bible Gateway parser
BGp=BGp.o
#VC is an acronym for Verse Compare
VC=VC.o

all: $(BGp) $(VC)

$(BGp): BGgetVerse.cpp Makefile
	$(CXX) -D SKIP  $(debug) BGgetVerse.cpp -o $@ 2>&1

$(VC): VC.cpp Makefile
	$(CXX) -D SKIP  $(debug) VC.cpp -o $@ 2>&1


.PHONY : clean
clean:
	if [ -f $(BGp) ]; then rm $(BGp); fi;
	if [ -f $(VC) ]; then rm $(VC); fi;
