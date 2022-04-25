CFLAGS:=-g -Wall -Wextra -std=c11

Make: link
compile: fonctaffichage.o fonctlecture.o fonctcreertab.o fonctrecherche.o motcache.o

fonctaffichage.o: fonctaffichage.c fonctaffichage.h
fonctlecture.o: fonctlecture.c fonctlecture.h
fonctcreertab.o: fonctcreertab.c fonctcreertab.h
fonctrecherche.o: fonctrecherche.c fonctrecherche.h
motcache.o: motcache.c motcache.h 

test:   link
	bats check.bats
clean: 
	rm -f *.o *.html motcache 
html: README.md
	pandoc -s --self-contained --css=./misc/github-pandoc.css --metadata title=" " README.md -o README.html 
link: compile
	gcc *.o -o motcache
	#gcc -o motcache -Wall -Wextra -std=c11 motcache.c
