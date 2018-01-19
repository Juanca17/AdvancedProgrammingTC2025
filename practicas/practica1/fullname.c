#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int doFullName(char *firstName, char *lastName, char **fullNameValue) {
  int sizeFirstName = strlen(firstName);
  int sizeLastName = strlen(lastName);
  int sizeFulltName = sizeFirstName + sizeLastName;

  char *src = (char *) malloc(sizeFulltName * sizeof(char));

  strcpy(src, firstName);
  strcpy(src + sizeFirstName, " "); // " " string with space
  strcpy(src + sizeFirstName + 1, lastName);
  *fullNameValue = src;

  return 0;
}

int main(int argc, char const *argv[]) {
  char *firstName = "Juan Carlos";
  char *lastName = "Sanchez";
  char *fullName;
  doFullName(firstName,lastName,&fullName);
  printf("\n%s\n\n",fullName);
  free(fullName);
  return 0;
}
