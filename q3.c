#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x,y;
}ComplexoRet;

typedef struct
{
    float mod,ang;
}ComplexoPolar;


ComplexoPolar convert_polar( ComplexoRet r)
{
    ComplexoPolar calc;

    calc.mod = sqrtf(powf(r.x,2)+powf(r.y,2));
    calc.ang = (atan(r.y/r.x)*180)/M_PI;
    return calc;
};


    int main(int argc, char *argv[])
{
    double x,y,z,real,img;
    double re1,re2;
    ComplexoRet ret1;
    ComplexoPolar polar1;

    if (argc==4)
    {
        x = atof(argv[1]);
        y = atof(argv[2]);
        z = atof(argv[3]);

        if(x!=0)
        {
            ret1.x = x;
            ret1.y = y;
            polar1 = convert_polar(ret1);

            real=(powf(polar1.mod,z));
            img=(polar1.ang*z);

            re1=real*cos((img*M_PI)/180);
            re2=real*sin((img*M_PI)/180);

            printf("O número retangular %.2f + %.2fj elevado a potência %.2f, é  %.2f %.2fj\n ",x,y,z, re1,re2);

        }else
        {
            printf("\n Número real inválido\n");
        }

    }else
    {
        printf("\n calculador: devem ser passados 4 parâmetros!!!\n");
    }

    return 0;
}
