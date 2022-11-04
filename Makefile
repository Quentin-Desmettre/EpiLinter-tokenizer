DOT_PRO_FILE = epi-tokenizer.pro
BINARY_NAME = epi-tokenizer

all:
	rm -rf build && mkdir build
	cd build && qmake ../$(DOT_PRO_FILE) && make -s

run-prod:
	cd build && ./$(BINARY_NAME) &
run-dev:
	cd build && ./$(BINARY_NAME) --debug &
