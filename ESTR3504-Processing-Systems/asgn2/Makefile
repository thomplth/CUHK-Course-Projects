
magic: magic.o display.o
	gcc -o magic magic.o display.o `pkg-config --cflags --libs gtk+-2.0`

magic.o: magic.c display.h
	gcc -c magic.c

functest: functest.o display.o
	gcc -o functest functest.o display.o `pkg-config --cflags --libs gtk+-2.0`

functest.o: functest.c display.h
	gcc -c functest.c

display.o: display.c display.h
	gcc -c display.c `pkg-config --cflags --libs gtk+-2.0`
