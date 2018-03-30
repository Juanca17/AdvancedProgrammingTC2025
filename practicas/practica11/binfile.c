#include <stdio.h>

typedef struct s {
  char name[20];
  char lastName[20];
  unsigned int id;
  unsigned char cal;
} Student;

int main() {
  char *studentDb = "studentDb.data";
  FILE *data;
  Student pAvanzada[5];

  for(int i = 0; i < 5; i++) {
    sprintf(pAvanzada[i].name,"student%d", i);
    sprintf(pAvanzada[i].lastName,"Perez%d", i);
    pAvanzada[i].id = i * 20;
    pAvanzada[i].cal = i * 7;
  }

  data = fopen(studentDb, "wb");

  fwrite(pAvanzada,sizeof(Student),5,data);

  fclose(data);

  return 0;
}
