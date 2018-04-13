#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

typedef struct s {
  char name[20];
  char lastName[20];
  unsigned int id;
  unsigned char cal;
} Student;

int main(int argc, char const *argv[]) {
  char *fileName = "studentDb.data";
  int fd = open(fileName, O_RDWR); // file, permisos
  Student *pAvanzada = (Student *)mmap(
    NULL,
    5 * sizeof(Student),
    PROT_READ | PROT_WRITE, // flags
    MAP_FILE  | MAP_SHARED,
    fd,
    0
  );

  printf("First Student %s\n", pAvanzada[0].name);
  strcpy(pAvanzada[1].name,"Pedro");
  printf("Second Student %s\n", pAvanzada[1].name);
  msync(pAvanzada,5 * sizeof(Student), MS_SYNC);
  munmap(pAvanzada,5 * sizeof(Student));
  close(fd);
  return 0;
}
