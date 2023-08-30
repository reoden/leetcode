CC = g++
CFLAGS = -g -Wall

sol:
	$(CC) $(CFLAGS) -DReoden -o sol sol.cc

clean:
	rm -f sol