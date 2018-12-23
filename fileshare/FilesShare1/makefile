CC=g++
CFLAGS=-I. -std=c++11 -pthread  -g

SRC_PATH := ./src/
OBJ_PATH := ./bin
INC_PATH := -I ./inc


DEPS = tcpserver.h tcpsocket.h
OBJS = tcpserver.o tcpsocket.o server.o sendModule.o 
OBJC =  tcpsocket.o client.o sendModule.o 
%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(INC_PATH)
all :	server client
server: $(OBJS)
	$(CC) -o  $@ $^  $(CFLAGS)

client: $(OBJC)
	$(CC) -o  $@ $^  $(CFLAGS)
clean:
	rm -rf *.o server client recv_*
