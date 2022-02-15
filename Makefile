CC=g++
CFLAGS=
#change for Maintest if you want to test the app
EXEC=Maintest

$(EXEC): lexer.o symbole.o etat.o $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o lexer.o symbole.o etat.o

lexer.o: lexer.cpp lexer.h

symbole.o: symbole.cpp symbole.h lexer.o

etat.o: etat.cpp etat.h

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC).o: $(EXEC).cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o
