IDIR = include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR= src

LIBS=-lm -lssl -lcrypto

_DEPS = quebra.h leitura.h saida.h structs.h criptografia.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o quebra.o leitura.o saida.o criptografia.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
