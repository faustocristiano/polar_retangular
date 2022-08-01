#include <stdio.h>
#include <string.h>

typedef  struct {
    char nome[100];
    unsigned int matricula;

} tipo_aluno;

typedef struct {
    char titulo[100];
    char autor[100];
    unsigned int matricula_aluno;
}tipo_livro;

tipo_aluno alunos[5]={
        {"Maria",155},
        {"Joao",167},
        {"Jose",313},
        {"Lara",211},
        {"Silvana",417},

};

tipo_livro livros[5]={
        {"Macbeth","Shakespeare",0},
        {"Dom Casmurro", "Machado de Assis",0},
        {"Iracema", "Jose de Alencar",0},
        {"Os Sertoes", "Euclides da Cunha",0},
        {"2001: Uma Odisseia no Espaço", "Artur C. Clarke",0 },
};

tipo_livro *encontrar_livro(char *titulo)
{
    /*pesquisa o livro passado como parametro e retorna um ponteiro para
     * estrutura do livro
     * se nao encontrado retorna NULL*/
    int i;
    int achar=0;
    tipo_livro *p;
    for (i = 0; i<5 &&achar==0; i++) {
        if (strcmp(titulo, livros[i].titulo) == 0) {
            achar = 1;
            p = &livros[i];
        }
    }
    if (achar==1){
        return p;
    }
    else{
        return NULL;
    }
}

tipo_aluno *encontrar_aluno(unsigned int matricula) {
    /*pesquisa o livro passado como parametro e retorna um ponteiro para
     * estrutura do livro
     * se nao encontrado retorna NULL*/
    int i;
    int procurar=0;
    tipo_aluno *p;
    for (i = 0; i<5 && procurar == 0; i++) {
        if (matricula==alunos[i].matricula) {
            procurar = 1;
            p = &alunos[i];
        }
    }
    if (procurar == 1){
        return p;
    }
    else{
        return NULL;
    }
}

int emprestar_livro(char *livro, unsigned int *matricula) {
    /* esta funçao deve usar duas funçoes adicionais: encontrar_livro() e encontrar aluno ()
    * a matricula do aluno deve ser registrada na estrutura do livro na ocasiao do emprestimo
    * a funçao retorna
    * 0 se o emprestimo realizado
    * 1 se o livro nao existe
    * 2 se o livro ja foi emprestado
    * 3 se o aluno ado
    * 4 se o aluno ja tem um livro emprestado - fazer uma funçao para isto  */


    tipo_aluno *aluno;
    aluno = encontrar_aluno(*matricula);
    tipo_livro *lvr;
    lvr = encontrar_livro(livro);
    if (lvr == NULL) {
        return 1;
    } else if (lvr->matricula_aluno != 0){
        return 2;
    }else if (aluno == NULL){
        return 3;
    }else {
        lvr->matricula_aluno=aluno->matricula;
        return 0;
    }
}

int devolver_livro(char *titulo)

{
    tipo_livro *lvr;
    lvr = encontrar_livro(titulo);
    if (lvr != NULL) {
        lvr->matricula_aluno = 0;
       
    }
}

int *livro_emprestado(unsigned int matricula)

{
    int i;
    int procurar=0;
    for (i=0; i<5;i++){
        if (matricula==livros[i].matricula_aluno){
            procurar=1;
        }
    }
    if (procurar == 1) {
        return 4;
    }else {
        return NULL;
    }
}

int main() {

    unsigned mat1 = 155, mat2 = 167, mat3 = 313, mat4=211, mat5=417,mat6=888;
    int tst1, tst2,tst3,tst4,tst5;
    tst1 = emprestar_livro("Os Sertoes", &mat6);
    tst2 = emprestar_livro("Os Sertoes", &mat1);
    tst3 = emprestar_livro("Os Sertoes", &mat1);
    tst4 = devolver_livro("Os Sertoes");
    tst5= livro_emprestado(&mat1);

    return 0;
}
