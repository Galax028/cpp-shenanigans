compile: main.o tictactoe.o
	$(CXX) -O3 -Wextra main.o tictactoe.o -o tictactoe

main.o: main.cpp tictactoe.h
	$(CXX) -O3 -Wextra -c main.cpp

tictactoe.o: tictactoe.cpp
	$(CXX) -O3 -Wextra -c tictactoe.cpp

clean:
	-rm -rf *.o *~ core paper

