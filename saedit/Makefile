GTK_FLAGS = $(shell pkg-config gtk+-2.0 --cflags --libs) $(shell pkg-config gtksourceview-2.0 --cflags --libs)
IBUS_FLAGS = $(shell pkg-config ibus-1.0 --cflags --libs)
OUTPUT = saedit
all:compile clean
compile:
	gcc ${CFLAGS} ${GTK_FLAGS} ${IBUS_FLAGS} ${LDFLAGS} main.c -o '${OUTPUT}'
clean:
	rm -rfv *.o~ *.c~ *.h~
