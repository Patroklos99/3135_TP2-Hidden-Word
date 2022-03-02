motdedyck: motcache.c
	gcc -o motcache -Wall -Wextra -std=c11 motcache.c
test:   motcache 
	bats check.bats
html: README.md
	pandoc -s --self-contained --css=./misc/github-pandoc.css --metadata title=" " README.md -o README.html ; pandoc -s --self-contained --metadata title=" " --css=./misc/github-pandoc.css sujet.md -o sujet.html 
clean: 
	rm -f *.o *.html motcache 
	
