
struct CITY {
	char name[120];
	double lat;
	double lon;
	int pop;
};

int ingest_file(FILE *fp, struct CITY cities[50]);
void pass_int(int num,struct CITY cities[50]);
void pass_string(int size, char *word, struct CITY cities[50]);

