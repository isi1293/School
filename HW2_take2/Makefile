gcc_sw="-g"
main: HW2.o ingest.o list.o list.h
	gcc $(gcc_sw) -o main HW2.o ingest.o list.o
HW2.o: HW2.c
	gcc $(gcc_sw) -c HW2.c
ingest.o: ingest.c
	gcc $(gcc_sw) -c ingest.c
list.o: list.c
	gcc $(gcc_sw) -c list.c
clean:
	rm HW2.o ingest.o list.o
