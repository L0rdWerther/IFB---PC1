CC = gcc
CFLAGS = -Wall -g
IDIR = ./include
ODIR = ./src
OBJDIR = objects
BINDIR = bin
src = $(wildcard $(ODIR)/*.c)
OBJ = $(patsubst $(ODIR)/%.c,$(OBJDIR)/%.o,$(src))
all: objfolder binfolder bin/main
objfolder:
	mkdir -p $(OBJDIR)
binfolder:
	mkdir -p $(BINDIR)
bin/main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
$(OBJDIR)/%.o: $(ODIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/main.o: $(ODIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY: clean run
clean:
	rm -f $(OBJDIR)/* $(BINDIR)/*
	rmdir $(OBJDIR) $(BINDIR)
run:
	$(BINDIR)/main