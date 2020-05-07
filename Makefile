
test: Test.cpp solver.cpp
	/usr/bin/g++ -g Test.cpp solver.cpp -o test
	./test

demo: Demo.cpp solver.cpp
	/usr/bin/g++ -g Demo.cpp solver.cpp -o demo
	./demo

clean: 
	rm ./test
	rm ./demo
