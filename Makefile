.PHONY: clean

cterm:
	gcc -Wall -std=gnu99 -g -o cterm cterm.c
	cp cterm ct

clean:
	rm -f cterm
	rm -f ct