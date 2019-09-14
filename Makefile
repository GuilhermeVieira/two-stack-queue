CFLAGS=-Wall -Wextra -Werror -pedantic 

file: twoStackQueue.cpp
	g++ twoStackQueue.cpp $(CFLAGS) -g -O2 -o queue

clean:
	rm queue

test:
	./queue