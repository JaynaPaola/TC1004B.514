#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

char entrada;
//char mayuscula;
int n;

int main(){
    do{
        char vocal = '1';
        n = read(STDIN_FILENO,&entrada,1);//leer la entrada estándar, guardar en entrada y leer uno por uno
        //mayuscula = toupper(entrada);//Convertir a mayúsculas
        if (entrada == 'A' || entrada =='E' || entrada =='I' || entrada =='O' || entrada =='U'|| entrada =='a'|| entrada =='e'|| entrada =='i'|| entrada =='o' || entrada =='u'){
        write(STDOUT_FILENO,&vocal,1);
    }
    }
    while(n!=0);
    return 0;
}