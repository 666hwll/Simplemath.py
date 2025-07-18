
build:
	
	clang++ -o Simplemath simplemath.cpp

clean:
	rm Simplemath

deb:
	dpkg-deb --build --root-owner-group debianrel
	mv debianrel.deb Simplemath.deb


all: 
	make clean
	make build
