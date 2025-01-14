##
## EPITECH PROJECT, 2024
## Triangle Makefile
## File description:
## Makefile
##

CC		= 	g++

CPPFLAGS	= 	-Wall -Wextra -std=c++20 -fPIC
CPPFLAGS	+= 	-iquote ../Raytracer/include -I../../Raytracer/include/3D -I../../Raytracer/include/interface

SRC			= 	Triangle.cpp \
				../../Raytracer/src/3D/Point3D.cpp	\
				../../Raytracer/src/3D/Vector3D.cpp	\
				../../Raytracer/src/3D/Ray.cpp	\
				../../Raytracer/src/3D/Color.cpp

OBJ			= 	$(SRC:.cpp=.o)

NAME		= 	raytracer_triangles.so

.PHONY:		all re clean fclean

all:	$(NAME)
$(OBJ): $(SRC)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -shared -o $@ $^

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

