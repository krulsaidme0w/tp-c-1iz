build-project:
	rm -rf build && mkdir build && cd build && cmake .. && make

	
run-project:
	cd build/cmd/ && ./main