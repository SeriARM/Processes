#include <stdio.h>
#include <unistd.h>

// Given a pointer to a string, print out each character (until reaching the terminating character), use a system call. 

void print_str(char *string) {
	// looping through our pointer values until we get to the terminating character '\0' and printing to the screen. 
   for (int i = 0; string[i] != '\0'; i++) {
         write(1, &string[i], 1);
     }
}

int main(void) {
	// initializing a pointer to a string
  char* string = "hello";
    print_str(string);

  return 0;
}