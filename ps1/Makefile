CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic
DEPS = FibLFSR.hpp
LIBS =  -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all:ps1 test

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< $(LIBS)
ps1:FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^
test:test.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
PhotoMagic:PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
clean:
	rm *.o ps1 test PhotoMagic
lint:
	cpplint *.cpp *.hpp