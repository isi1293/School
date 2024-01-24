gcc_sw=-g
main: cities.o ingest_file.o pass_int.o pass_string.o
	gcc -o main cities.o ingest_file.o pass_int.o pass_string.o
cities.o: cities.c
	gcc $(gcc_sw) -c cities.c 
ingest_file.o: ingest_file.c
	gcc $(gcc_sw) -c ingest_file.c 
pass_int.o: pass_int.c
	gcc $(gcc_sw) -c pass_int.c
pass_string.o: pass_string.c
	gcc $(gcc_sw) -c pass_string.c
clean:
	rm cities.o ingest_file.o pass_int.o pass_string.o

