##
## EPITECH PROJECT, 2022
## EpiLinter-tokenizer
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -Wall -Wextra -I include -std=c++17 -L /usr/lib64/ -lboost_wave -lpthread

SRC = \
	src/main.cpp \
	src/SocketServer.cpp \
	src/Tokenizer.cpp \
	src/BoostTokenizer.cpp

OBJ = $(SRC:.cpp=.o)

NAME = epi-tokenizer

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)
