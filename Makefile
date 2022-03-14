CC=g++
CFLAGS=
#change for Maintest if you want to test the app
EXEC=Main

$(EXEC): lexer.o symbole.o etat.o Automate.o $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o lexer.o symbole.o etat.o Automate.o

lexer.o: lexer.cpp lexer.h symbole.o

symbole.o: symbole.cpp symbole.h

etat.o: etat.cpp etat.h Automate.cpp Automate.h	

Automate.o: Automate.cpp Automate.h etat.o symbole.o lexer.o

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC).o: $(EXEC).cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o
cleanall:
	rm -f *.o
	rm $(EXEC)
