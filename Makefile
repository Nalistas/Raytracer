##
## EPITECH PROJECT, 2024
## raytracer
## File description:
## Makefile
##

.PHONY: all clean fclean re figures tests_run

all: figures

figures:
	@echo "Building Plugins..."
	@mkdir -p ./plugins
	@make -C ./Raytracer
	@make -C ./Primitives/Sphere
	@make -C ./Primitives/Cylinder
	@make -C ./Primitives/Cone
	@make -C ./Primitives/Plane
	mv ./Primitives/Sphere/raytracer_spheres.so ./plugins
	mv ./Primitives/Cylinder/raytracer_cylinders.so ./plugins
	mv ./Primitives/Cone/raytracer_cones.so ./plugins
	mv ./Primitives/Plane/raytracer_planes.so ./plugins

clean:
	@make -C ./Raytracer clean
	@make -C ./Primitives/Sphere clean
	@make -C ./Primitives/Cylinder clean
	@make -C ./Primitives/Cone clean
	@make -C ./Primitives/Plane clean
	@make -C ./tests clean

fclean:
	@make -C ./Raytracer fclean
	@make -C ./Primitives/Sphere fclean
	@make -C ./Primitives/Cylinder fclean
	@make -C ./Primitives/Cone fclean
	@make -C ./Primitives/Plane fclean
	@make -C ./tests clean
	rm -rf ./plugins

tests_run:
	@make -C ./tests tests_run

re: fclean all
