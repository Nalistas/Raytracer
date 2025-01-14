##
## EPITECH PROJECT, 2024
## nanotekspice
## File description:
## Makefile
##

CC = g++

CPPFLAGS += -Wall -Wextra -std=c++20 -I./include/ \
		-I./include -I./src/Lights/ -I../Primitives/ -I../Textures/ -I../Textures/ -fPIC -g3

SRC =	main.cpp									\
		src/3D/Point3D.cpp							\
		src/3D/Vector3D.cpp							\
		src/3D/Ray.cpp								\
		src/3D/Rectangle3D.cpp						\
		src/Core/DLLoader.cpp						\
		src/Core/Core.cpp							\
		src/3D/Camera.cpp							\
		src/Mediator/Mediator.cpp					\
		src/3D/Color.cpp							\
		../Textures/BasicTexture/BasicTexture.cpp	\
		../Textures/ChestBoard/SphericChessBoard.cpp	\
		../Textures/ReflexionTexture/ReflexionTexture.cpp	\
		../Textures/TransparenceTexture/TransparenceTexture.cpp	\
		../Textures/Rotation/RotationDecorator.cpp	\
		src/Lights/PointLight/PointLight.cpp	\
		src/Lights/AmbientLight/AmbientLight.cpp	\
		src/Lights/DirectionnalLight/DirectionnalLight.cpp	\
		src/Lights/ColorLight/ColorLight.cpp	\
		src/Parser/Parser.cpp						\
		src/Parser/Cli.cpp							\
		src/Parser/Export.cpp						\
		src/SFML/SFML.cpp

NAME = ../raytracer

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -g -lconfig++ -ldl -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	$(RM) $(OBJ)
	$(RM) */*.o
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean
re: all

.PHONY: all clean fclean re
