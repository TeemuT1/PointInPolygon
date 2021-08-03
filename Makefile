PROG = PIPTest
CC = g++
CPPFLAGS = -g -Wall
OBJS = main.o polygon.o point.o

ifdef OS
   RM = del /Q
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
   endif
endif

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
main.o:
	$(CC) $(CPPFLAGS) -c main.cpp
polygon.o: polygon.h
	$(CC) $(CPPFLAGS) -c polygon.cpp
point.o: point.h
	$(CC) $(CPPFLAGS) -c point.cpp
clean:
	$(RM) core $(OBJS)
