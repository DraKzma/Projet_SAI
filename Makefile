all:

	gcc -c src/jeu.c -lm -lglut -lGLU -lGL -o out/jeu.o
	gcc -c src/blocks.c -lm -lglut -lGLU -lGL -o out/blocks.o
	gcc -c src/scores.c -lm -lglut -lGLU -lGL -o out/scores.o
	gcc out/jeu.o out/blocks.o out/scores.o -o jeu -lm -lglut -lGLU -lGL

clean:

	rm out/blocks.o
	rm out/jeu.o
	rm out/scores.o
	rm jeu