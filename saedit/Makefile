ifndef CFLAGS
	CFLAGS = -O2 -pipe
endif

ifndef LDFLAGS
	LDFLAGS = 
endif

LDFLAGS += -export-dynamic

GTK_CFLAGS = `pkg-config --cflags gtk+-2.0 gtksourceview-2.0`
IBUS_CFLAGS = `pkg-config --cflags ibus-1.0`

GTK_LDFLAGS = `pkg-config --libs gtk+-2.0 gtksourceview-2.0`
IBUS_LDFLAGS = `pkg-config --libs ibus-1.0`

IBUS_FLAGS = ${IBUS_CFLAGS} ${IBUS_LDFLAGS}
GTK_FLAGS = ${GTK_CFLAGS} ${GTK_LDFLAGS}

OUTPUT = saedit
all:clean main.o search.o config.o xml.o sae.o compile
compile: main.o search.o config.o xml.o
	gcc ${CFLAGS} ${GTK_FLAGS} ${IBUS_FLAGS} ${LDFLAGS} -o '${OUTPUT}' main.o search.o config.o xml.o sae.o
main.o: main.c main.h search.h config.h common.h xml.h
	gcc ${CFLAGS} ${GTK_CFLAGS} ${IBUS_CFLAGS} -c -o main.o main.c
search.o: search.c search.h common.h
	gcc ${CFLAGS} ${GTK_CFLAGS} -c -o search.o search.c
xml.o: xml.c xml.h common.h
	gcc ${CFLAGS} ${IBUS_FLAGS} -c -o xml.o xml.c
config.o: config.c config.h common.h
	gcc ${CFLAGS} ${GTK_CFLAGS} ${IBUS_FLAGS} -c -o config.o config.c
sae.o: sae.c sae.h common.h
	gcc ${CFLAGS} ${GTK_CFLAGS} ${IBUS_CFLAGS} -c -o sae.o sae.c
clean:
	rm -rfv '${OUTPUT}' *.o *.o~ *.c~ *.h~
