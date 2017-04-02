ifeq ($(OS),Windows_NT)
	exec = game.exe
else
	exec = game
endif

make:
	g++ -o $(exec) gfx/graphics.cpp -lsfml-graphics -lsfml-window -lsfml-system
