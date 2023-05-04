.PHONY: clean
.PHONY: cterm_zsh

cterm: clean cterm.c
	gcc -Wall -std=gnu99 -g -o cterm cterm.c
	cp cterm ct

cterm_zsh: clean cterm.c cterm_zsh
	gcc -Wall -std=gnu99 -DTERM=1 -g -o cterm cterm.c
	cp cterm ct

clean:
	rm -f cterm
	rm -f ct