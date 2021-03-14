#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_visualize(char* buff);
void visualize(char* buff);
void print_flag();
void vuln();

void vuln() {
  char padding[16];
  char buff[32];
  int notsecret = 0xffffff00;
  int secret = 0xdeadbeef;

  memset(buff, 0, sizeof(buff)); 
  memset(padding, 0xFF, sizeof(padding));

  init_visualize(buff); 

  visualize(buff);

  printf("Input some text: ");
  gets(buff); 

  visualize(buff); 

  if (secret == 0x67616c66) {
    puts("You did it! Congratuations!");
    print_flag(); 
    return;
  } else if (notsecret != 0xffffff00) {
    puts("Uhmm... maybe you overflowed too much. Try deleting a few characters.");
  } else if (secret != 0xdeadbeef) {
    puts("Wow you overflowed the secret value! Now try controlling the value of it!");
  } else {
    puts("Maybe you haven't overflowed enough characters? Try again?");
  }

  exit(0);
}

int main() {
  setbuf(stdout, NULL);
  setbuf(stdin, NULL);
  vuln();
}
