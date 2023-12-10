WARNING = -Wall -Wshadow
ERROR = -Wvla
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
EXEC = pa1
OBJS = pa1.o shell_array.o shell_list.o

all: $(OBJS)
	$(GCC) $(OBJS) -o $(EXEC)

$(EXEC): $(OBJS)
	$(GCC) $(OBJS) -o $(EXEC)

%.o: %.c 
	$(GCC) -c $<

testall: test1 

test1: $(EXEC)
	./$(EXEC) examples/10K.b output.b
	

memory: $(EXEC)
	valgrind --log-file=log1 --leak-check=full ./$(EXEC) examples/1K.b output.b


clean: # remove all machine generated files
	rm -f pa1 *.o log*



