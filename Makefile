test: Test.cpp solver.cpp
	/usr/bin/g++ -g Test.cpp solver.cpp -o test
	

demo: demo.cpp solver.cpp
	/usr/bin/g++ -g demo.cpp solver.cpp -o demo
	

clean: 
	rm ./test
	rm ./demo
