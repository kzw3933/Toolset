WOLFRAM_APPID :=

.PHONY: build
build: configure
	cmake --build build

.PHONY: configure
configure:
	cmake -B build -DWOLFRAM_APPID=${WOLFRAM_APPID}

.PHONY: run
run:
	./build/answer_app

.PHONY: clean
clean:
	rm -rf build