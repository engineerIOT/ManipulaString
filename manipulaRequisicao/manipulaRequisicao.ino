#include <stdio.h>
#include <string.h>

char minhaString[256] = "{HTTP/1.1 404 Not Found Date: Wed, 29 Jul 2020 02:23:22 GMT}";
const char* resposta;
char texto[256];
char respostaCopiada[256];
char dest[256];
char texto2[32];



void setup() {
  Serial.begin(9600);

}

void loop() {
  printMyString () ;
  delay(1000);
  limitMyString();
  delay(1000);
}

void printMyString () {
  resposta = (const char*) minhaString;
  sprintf(texto, "{%s}" , (const char*)resposta);
  Serial.println(texto);


}

void limitMyString() {
  sprintf(respostaCopiada, "{%s}" , (const char*)texto);
  //Serial.println(respostaCopiada);

  const char ch = ':';
  char *ret;
  ret = strchr(respostaCopiada, ch);
  //Serial.println(ret);

  char dest[32];
  memset(dest, '\0', sizeof(dest));
  strncpy(dest, ret, 32);
  //Serial.println(dest);

  sprintf(texto2, "{\"ID\"%s}" , dest);
  Serial.println(texto2);   //{"ID": Wed, 29 Jul 2020 02:23:22}
}
