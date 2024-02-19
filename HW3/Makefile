gcc_sw="-g"

HW3: HW3.o list.o hash.o ingest.o list.h hash.h
	gcc $(gcc_sw) -o HW3 HW3.o list.o hash.o ingest.o -lm
HW3.o: HW3.c
	gcc $(gcc_sw) -c HW3.c
list.o: list.c
	gcc $(gcc_sw) -c list.c
hash.o: hash.c
	gcc $(gcc_sw) -c hash.c
ingest.o: ingest.c
	gcc $(gcc_sw) -c ingest.c
clean:
	rm HW3 HW3.o list.o hash.o ingest.o 
