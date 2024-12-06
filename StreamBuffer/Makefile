.PHONY: clean

all: testingStreamBuffer

testingStreamBuffer: streamBuffer.c testingStreamBuffer.c
	gcc @^ -o testingStreamBuffer

clean: streamBuffer
	rm @^