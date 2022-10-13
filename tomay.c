#include <unistd>
#include <ctype>

int main(){
    char c;
    char may;
    int n;

    do{
        n = read(STDIN_FILENO,&c,1); 
        may = toupper(c); 
        write(STDOUT_FILENO,&may,1);
    }
    while(n!=0);
    return 0;
}