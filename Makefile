all:

	gcc jeu.c -o jeu -lm -lglut -lGLU -lGL -lX11

clean:

	rm jeu