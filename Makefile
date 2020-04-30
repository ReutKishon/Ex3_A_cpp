test: Test.cpp solver.cpp solver_complex.cpp
	/usr/bin/g++ -g Test.cpp solver.cpp solver_complex.cpp -o test
	

demo: demo.cpp solver.cpp solver_complex.cpp
	/usr/bin/g++ -g demo.cpp solver.cpp solver_complex.cpp -o demo
	

clean: 
	rm ./test
	rm ./demo
