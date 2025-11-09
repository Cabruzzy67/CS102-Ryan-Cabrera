CC = gcc
CFLAGS = -Wall -std=c99

OBJS = parser.o csv_parser.o

parser: $(OBJS)
	$(CC) $(OBJS) -o parser

parser.o: parser.c csv_parser.h
	$(CC) $(CFLAGS) -c parser.c

csv_parser.o: csv_parser.c csv_parser.h
	$(CC) $(CFLAGS) -c csv_parser.c

clean:
	rm -f $(OBJS) parser
