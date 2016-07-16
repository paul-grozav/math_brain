all: binary

binary:
	rm -Rf bin
	mkdir bin
	cd bin
	cmake ..
	make
