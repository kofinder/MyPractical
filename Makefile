all: clean install develop validate execute

clean:
	rm -rf build
	mkdir build

install:
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graph.png 

develop:
	cd build && cmake --build .

validate:
	cd build/tests && ./unit_tests

execute:
	cd build/app && ./Executable 
