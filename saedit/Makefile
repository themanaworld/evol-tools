CC ?= gcc

CFLAGS += `pkg-config --cflags gtk+-3.0 gtksourceview-3.0`
CFLAGS += -fPIC -Itreefolderview -Ispritedrawingarea
CFLAGS += -Wall -Wdeclaration-after-statement -ansi
CFLAGS += -Werror -Wextra -Wstrict-prototypes
CFLAGS += -Wno-unused-parameter

LDFLAGS += `pkg-config --libs gtk+-3.0 gtksourceview-3.0`
LDFLAGS += -rdynamic -Ltreefolderview -Lspritedrawingarea

FLAGS = ${CFLAGS} ${LDFLAGS}

all: saedit glade/libsaedit.so

saedit: main.o treefolderview/treefolderview.o xml.o  \
	spritedrawingarea/spritedrawingarea.o \
	context.o imageset.o action.o animation.o common.o \
	interactor.o callbacks.o errors.o config.o file.o \
	buffer.o spritedrawingarea/sdalayer.o xmlsetup.o \
	drawfuncs.o
	${CC} $^ -o saedit ${FLAGS}

glade/libsaedit.so: treefolderview/treefolderview.o \
	spritedrawingarea/spritedrawingarea.o \
	spritedrawingarea/sdalayer.o
	${CC} $^ -o glade/libsaedit.so ${FLAGS} -shared

%.o: %.c
	${CC} $^ -c -o $@ ${CFLAGS}

clean:
	rm -f *.o */*.o *~ glade/libsaedit.so saedit
