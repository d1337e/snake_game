build:
	mkdir -p build
	cd build && cmake .. && make

run: build
	./build/snake

clean:
	rm -rf build

.PHONY: build run clean