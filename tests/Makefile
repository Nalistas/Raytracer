##
## EPITECH PROJECT, 2024
## B-OOP-400-BAR-4-1-raytracer-hugo.tesson
## File description:
## Makefile
##

CC			= g++

CPPFLAGS 	+= 	-Wall -Wextra -std=c++20 -Werror -iquote include

UT_NAME		= 	raytracer.test

TST_DIR		=	tests

TST_OBJ		=	$(SRC:.cpp=.o) $(TST:.cpp=.o)

UT_SRC		=	testSphere.cpp		\
				testCylinder.cpp	\
				testCone.cpp		\
				testPlane.cpp		\

tests_run:
	$(CC) -o $(UT_NAME) -I ./test/ --coverage $(SRC) $(UT_SRC) -lcriterion
	./$(UT_NAME)
	gcovr --exclude $(TST_DIR)
	gcovr --exclude $(TST_DIR) --branches


$(UT_NAME): $(TST_OBJ)
	$(CC) $(TST_OBJ) -o $(UT_NAME) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(TST_OBJ)
	$(RM) *.gcda
	$(RM) *.gcno

.PHONY: tests_run clean