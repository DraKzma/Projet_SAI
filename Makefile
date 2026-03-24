all:

	gcc jeu.c -o jeu -lm -lglut -lGLU -lGL

clean:

	rm jeu