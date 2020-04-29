test: Test.cpp solver.cpp 
	/usr/bin/g++ -g Test.cpp solver.cpp -o test
	./test

demo: demo.cpp solver.cpp solver_complex.cpp
	/usr/bin/g++ -g demo.cpp solver.cpp solver_complex.cpp -o demo
	./demo

clean: 
	rm ./test
	rm ./demo
