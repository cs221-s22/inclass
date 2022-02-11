#include <stdio.h>
#include <string.h>

// Declare a struct
struct person {
	char name[32];
	int age;
};

void print_person(struct person *pp) {
	printf("name: %s, age: %d, size: %ld\n", pp->name, pp->age, sizeof(*pp));
}

int main() {
	// Defines a struct named p on the stack
	struct person phil;
	strcpy(phil.name, "Phil Peterson");
	phil.age = 54;

	print_person(&phil);
	
	return 0;
}
