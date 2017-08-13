CC = g++
LDFLAGS = -framework OpenGL `pkg-config --libs glfw3`
CFLAGS = -I include -g -c -std=c++11 `pkg-config --cflags glfw3`
SRC = $(wildcard *.cpp src/*.cpp)
HEAD = $(wildcard include/Tutorial/*.h)
OBJ = $(SRC:.cpp=.o)
EXEC = main

all: $(OBJ) $(EXEC) $(HEAD)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o src/*.o $(EXEC)