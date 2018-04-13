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
  int id;
  char name[20];
  Student *pAvanzada = (Student *)mmap(
    NULL,
    5 * sizeof(Student),
    PROT_READ | PROT_WRITE, // flags
    MAP_FILE  | MAP_SHARED,
    fd,
    0
  );
  for (int i = 0; i < 4; i++) {
    printf("Provide id\n");
    scanf("%d\n", &id);
    printf("Student data: %s\n", pAvanzada[id]);
  }
  munmap(pAvanzada,5 * sizeof(Student));
  close(fd);
  return 0;
}
