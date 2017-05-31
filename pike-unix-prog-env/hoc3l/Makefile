YFLAGS = -d
OBJS = hoc.o lex.o init.o math.o symbol.o

hoc3:	$(OBJS)
	gcc $(OBJS) -o hoc3

lex.c: lex.l
	flex2 -o$@ $<

hoc.o:  hoc.h

lex.o init.o symbol.o:	hoc.h y.tab.h

clean:
	rm -fv *.o *.exe lex.c y.tab.h
