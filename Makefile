build-project:
	rm -rf build && mkdir build && cd build && cmake .. && make

run-project:
	cd build/cmd/ && ./main

build-n-run:
	make build-project && make run-project

run-all-tests:
	cd build/tests/ && ./tests

coverage:
	cd build/src/storage-device/CMakeFiles/storage.dir && gcov *.gcno && lcov --capture --directory . --output-file coverage.info && mkdir coverage && genhtml coverage.info --output-directory coverage

build-n-test:
	make build-project && make run-all-tests


	#&& valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --undef-value-errors=no --verbose ./build/tests/tests

