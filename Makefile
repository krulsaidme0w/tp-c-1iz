build-project:
	rm -rf build && mkdir build && cd build && cmake .. && make

run-project:
	cd build/cmd/ && ./main

build-n-run:
	make build-project && make run-project

run-all-tests:
	cd build/tests/ && ./tests

build-n-test:
	make build-project && make run-all-tests