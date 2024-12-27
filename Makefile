make:
	cc -o ssbs main.cc
install: make
	cp ssbs /bin/
uninstall:
	rm /bin/ssbs