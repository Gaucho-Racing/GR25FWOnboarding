.PHONY: clean

all: testingStreamBuffer

testingStreamBuffer: streamBuffer.c testingStreamBuffer.c
	gcc $^ -o $@

clean: streamBuffer
	rm $^