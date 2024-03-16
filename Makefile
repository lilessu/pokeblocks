CC = g++

CFLAGS = -Wall -Wextra -pedantic -g -Werror

INCLUDES = 

SRCS = Battle.cpp Game.cpp main.cpp PokeMove.cpp Pokemon.cpp Ability.cpp PokeType.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = pokeblocks

.PHONY: all clean

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~

