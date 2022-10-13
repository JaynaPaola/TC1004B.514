#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

char entrada;
char mayuscula;
int n;

int main(){
    do{
        char vocal = '1';
       // n = read(STDIN_FILENO,&c,1); //leer la entrada estándar, guardar en c y leer uno por una
        //may = toupper(c); //Convertir a mayúsculas
        //write(STDOUT_FILENO,&may,1);

        n = read(STDIN_FILENO,&centrada,1);
        mayuscula = toupper(entrada); 
        if (mayuscula == 'A' || mayuscula =='E' || mayuscula =='I' || mayuscula =='O' || mayuscula =='U' ){
        write(STDOUT_FILENO,&vocal,1);
    }

    }
    while(n!=0);
    return 0;
}