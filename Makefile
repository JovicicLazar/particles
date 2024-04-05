GCC     = g++
CFLAGS  = -Wall -Wextra -std=c++11
LDFLAGS = -lraylib -lstdc++ -ljsoncpp -lm
SRC 	= main.cpp ./src/particles.cpp
OUT 	= particles

all: $(OUT)
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -rf $(OUT)

