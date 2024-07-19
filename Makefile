all: clean install develop execute

clean:
	rm -rf build
	mkdir build

install:
	cd build && cmake ..

develop:
	cd build && cmake --build .

execute:
	cd build/app && ./Executable 
