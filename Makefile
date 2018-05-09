all: manage

local: manage
	cp local-script/* .

manage:
	g++ --std=c++11 main.cpp -o manage

clean:
	rm manage
	-rm *.sh
