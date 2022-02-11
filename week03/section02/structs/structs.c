#include <stdio.h>
#include <string.h>

// Declares a structure of type person
struct person {
	char name[32];
	int zip_code;
};

void print_person(struct person *pp) {
	pp->zip_code = 12345;
	printf("Name: %s\n", pp->name);
	printf("ZIP: %d\n", pp->zip_code);
}

int main() {
 	// Defines an instance of struct person on the stack
	struct person phil;

	strncpy(phil.name, "Phil Peterson", 32);
	phil.zip_code = 95070;

	print_person(&phil);
	printf("Phil's zip: %d\n", phil.zip_code);
}
