CC = gcc
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TARGET = flesch
SRCS = main.c flesch.c
 
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)
 
clean:
	rm -f $(TARGET)
 
test: $(TARGET)
	@for f in inputs/input_*.txt; do \
		n=$$(echo $$f | grep -o '[0-9]*'); \
		./$(TARGET) $$f > output_$$n.txt; \
		if diff -q output_$$n.txt expected/expected_$$n.txt > /dev/null; then \
			echo "PASS: input_$$n.txt"; \
		else \
			echo "FAIL: input_$$n.txt"; \
			diff output_$$n.txt expected/expected_$$n.txt; \
		fi; \
		rm -f output_$$n.txt; \
	done
 
.PHONY: clean test