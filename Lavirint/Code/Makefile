PROGRAM = lavirint
CC      = gcc
CFLAGS  = -g -ansi -I/usr/X11R6/include -I/usr/pkg/include 
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): main.o  crtanje.o inicijalizacija.o provere.o tajmeri.o callback_f.o pomeranje.o ispis_teksta.o start_restart.o image.o tekstura.o citanje_upis.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) main.o  crtanje.o inicijalizacija.o provere.o tajmeri.o callback_f.o pomeranje.o ispis_teksta.o start_restart.o image.o tekstura.o citanje_upis.o $(LDLIBS) 

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
