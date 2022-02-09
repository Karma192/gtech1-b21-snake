CC=g++
EXE=snake
CPP=main.cpp snake.cpp MainSDLWindow.cpp apple.cpp score.cpp
HPP=apple.hpp MainSDLWindow.hpp snake.hpp score.hpp

default: $(EXE)

$(EXE): $(CPP) $(HPP)
	$(CC) $(CPP) -lSDL2 -o $(EXE)

run: $(EXE)
	./$(EXE)

uml/classes.png: *.hpp
	./uml/mk_uml.sh uml/classes.png *.hpp

nblines:
	@wc -l *.h *.[ch]pp