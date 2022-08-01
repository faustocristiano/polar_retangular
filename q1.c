#include <stdio.h>
#include <string.h>

int inserir_string(char *p1, char *p2, int n) {
    {
        char *p;
        p=p1+n;

        char aux[50];
        int tmp1,tmp2;

        tmp2=strlen(p2);
        int i,j;
        for(i=0;i<n;i++)
        {
            aux[i]=*p1++;
        }
        for(j=0;j<tmp2;j++)
        {
            aux[n+j]=*p2++;
        }
        for(i=0;*p!=0;i++)
        {
            aux[n+tmp2+i]=*p++;
        }
        tmp1=strlen(aux);



        for(i=0;i<tmp1;i++)
        {
            *p1++=aux[i];
        }

        return tmp1;
    }
}
int main()
{
    char alfa[50]="Instituto de Santa Catarina";
    int tamanho;
    tamanho = inserir_string(alfa,"Federal ",10);
    printf("%s %d\n",alfa,tamanho);
    return 0;

}