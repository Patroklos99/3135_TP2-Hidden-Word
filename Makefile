Make: link
compile: fonctaffichage.o fonctlecture.o fonctcreertab.o fonctrecherche.o motcache.o
fonctaffichage.o: fonctaffichage.c fonctlecture.h fonctaffichage.h
	gcc -Wall -Wextra -std=c11 -c fonctaffichage.c

fonctlecture.o: fonctlecture.c fonctcreertab.h fonctlecture.h
	gcc -Wall -Wextra -std=c11 -c fonctlecture.c
fonctcreertab.o: fonctcreertab.c fonctrecherche.h fonctcreertab.h
	gcc -Wall -Wextra -std=c11 -c fonctcreertab.c
fonctrecherche.o: fonctrecherche.c motcache.h fonctrecherche.h
	gcc -Wall -Wextra -std=c11 -c fonctrecherche.c
motcache.o: motcache.c motcache.h 
	gcc -Wall -Wextra -std=c11 -c motcache.c

test:   link
	bats check.bats
clean: 
	rm -f *.o *.html motcache 
html: README.md
	pandoc -s --self-contained --css=./misc/github-pandoc.css --metadata title=" " README.md -o README.html 
link: compile
	gcc *.o -o motcache
	#gcc -o motcache -Wall -Wextra -std=c11 motcache.c
