compile: main.o tictactoe.o
	$(CXX) -O3 -Wall -Wextra -std=c++2a main.o tictactoe.o -o tictactoe

main.o: main.cpp tictactoe.h
	$(CXX) -O3 -Wall -Wextra -std=c++2a -c main.cpp

tictactoe.o: tictactoe.cpp
	$(CXX) -O3 -Wall -Wextra -std=c++2a -c tictactoe.cpp

clean:
	-rm -rf *.o *~ core paper

