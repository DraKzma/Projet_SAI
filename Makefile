all:

	gcc -c src/jeu.c -lm -lglut -lGLU -lGL -o out/jeu.o
	gcc -c src/blocks.c -lm -lglut -lGLU -lGL -o out/blocks.o
	gcc out/jeu.o out/blocks.o -o jeu -lm -lglut -lGLU -lGL

clean:

	rm out/blocks.o
	rm out/jeu.o
	rm jeu