make:
	cc -o ssbs main.c
install: make
	cp ssbs /bin/
uninstall:
	rm /bin/ssbs
