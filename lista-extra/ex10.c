#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define SUCESS 1;
#define FAILURE -1;

typedef struct Circle* CirclePointer;

typedef struct Circle Circle;

struct Circle{
    double x; // coordenada x do centro do cí
    double y; // coordenada y do centro do cí
    double radius; // raio
    unsigned int lineColor; // código RGB da cor da linha
    unsigned int areaColor; // código RGB da cor de preench
    bool visible; // O círculo é, ou não, visível};
};


// prototipos das funcoes:
int createCircle (CirclePointer* c, Circle p);
int destroyCircle (CirclePointer* c);
int putLineColor (CirclePointer* c, unsigned int color);
int putFillColor (CirclePointer* c, unsigned int color);
int turnVisible (CirclePointer* c);
int turnInvisible (CirclePointer* c);
int getCircleCenter (CirclePointer c, double *x, double *y);
int getLineColor (CirclePointer c, unsigned int *color);
int getAreaColor (CirclePointer c, unsigned int *color);
int showCircle (CirclePointer c);
int getRelativePosition (CirclePointer c1, CirclePointer c2, unsigned int * position);

// implementacao das funcoes
int createCircle(CirclePointer* c, Circle p) {
    // Aloca memória para a estrutura Circle
    *c = (CirclePointer)malloc(sizeof(Circle));

    // Verifica se a alocação foi bem-sucedida
    if (*c == NULL) {
        return FAILURE;
    }
    else{
        // Preenche os campos da estrutura com os valores fornecidos
    (*c)->x = p.x;
    (*c)->y = p.y;
    (*c)->radius = p.radius;
    (*c)->lineColor = p.lineColor;
    (*c)->areaColor = p.areaColor;
    (*c)->visible = p.visible;

    // Retorna sucesso
    return SUCESS;
    }
}

int destroyCircle (CirclePointer* c){
    if (*c != NULL){
        free((*c));
        (*c) = NULL;
        return SUCESS;
    }
    else{
        return FAILURE;
    }
}

int putLineColor (CirclePointer* c, unsigned int color){
    if (*c != NULL){
        (*c)->lineColor = color;
        return SUCESS;
    }
    else
        return FAILURE;
}

int putFillColor (CirclePointer* c, unsigned int color){
    if (*c != NULL){
        (*c)->areaColor = color;
        return SUCESS;
    }
    else
        return FAILURE;
}

int turnVisible (CirclePointer* c){
    if (*c != NULL){
        (*c)->visible = true;
        return SUCESS;
    }
    else
        return FAILURE;
}

int turnInvisible (CirclePointer* c){
    if (*c != NULL){
        (*c)->visible = false;
        return SUCESS;
    }
    else
        return FAILURE;
}

int getCircleCenter (CirclePointer c, double *x, double *y){
    if (c != NULL){
        (*x) = c->x;
        (*y) = c->y;
        return SUCESS;
    }
    else
        return FAILURE;
}

int getLineColor (CirclePointer c, unsigned int *color){
    if (c != NULL){
        (*color) = c->lineColor;
        return SUCESS;
    }
    else
        return FAILURE;
}

int getAreaColor (CirclePointer c, unsigned int *color){
    if (c != NULL){
        (*color) = c->areaColor;
        return SUCESS;
    }
    else
        return FAILURE;
}

int showCircle (CirclePointer c){
    char visible[20];
    
    if (c != NULL){
        if (c->visible == true){
            strcpy(visible, "true");    
            printf ("%.6f; %.6f; %.6f; %u; %u; %s", c->x, c->y, c->radius, c->lineColor, c->areaColor, visible);
        }
        else{
            strcpy(visible, "false"); 
            printf ("%.6f; %.6f; %.6f; %u; %u; %s", c->x, c->y, c->radius, c->lineColor, c->areaColor, visible);
        }
        return SUCESS;
    }
    else
        return FAILURE;
}

int getRelativePosition (CirclePointer c1, CirclePointer c2, unsigned int * position){
    if (c1->x == c2->x && c1->y == c2->y && c1->radius > c2->radius){
        
    }
        
}


void menu(){
    printf("*****---MENU---*****\n");
    printf("1 - createCircle\n");
    printf("2 - destroyCircle\n");
    printf("3 - putLineColor\n");
    printf("4 - putFillColor\n");
    printf("5 - turnVisible\n");
    printf("6 - turnInvisible\n");
    printf("7 - getCircleCenter\n");
    printf("8 - getLineColor\n");
    printf("9 - getAreaColor\n");
    printf("10 - showCircle\n");
    printf("11 - getRelativePosition\n");
    printf("0 - sair\n");
}

void imprimeResultado(int resultado){
    if(resultado == 1){
        printf("OPERACAO REALIZADA\n");
        return;
    }
    printf("NAO FOI POSSIVEL REALIZAR A OPERACAO");
}

int main()
{
    int escolha;
    CirclePointer cp;
    Circle c;
    int resultado;
    unsigned int color;
    double x, y;

    do{
        menu();
        printf("Digite sua escolha: ");
        scanf("%d",&escolha);

        switch (escolha)
        {
        case 1:
            resultado = createCircle(&cp, c);
            imprimeResultado(resultado);
        break;
        case 2:
            resultado = destroyCircle(&cp);
            imprimeResultado(resultado);
        break;
        case 3:
            printf("DIGITE O COD DA COR: ");
            scanf("%u",&color);
            resultado = putLineColor(&cp, color);
            imprimeResultado(resultado);
        break;
        case 4:
            printf("DIGITE O COD DA COR DA AREA: ");
            scanf("%u",&color);
            resultado = putFillColor(&cp, color);
            imprimeResultado(resultado);
        break;
        case 5:
            resultado = turnVisible(&cp);
            imprimeResultado(resultado);
        break;
        case 6:
            resultado = turnInvisible(&cp);
            imprimeResultado(resultado);
        break;
        case 7:
            resultado = getCircleCenter(cp,&x,&y);
            imprimeResultado(resultado);
        break;
        case 8:
            resultado = getLineColor(cp,&color);
            imprimeResultado(resultado);
        break;
        case 9:
            resultado = getAreaColor(cp,&color);
            imprimeResultado(resultado);
        break;
        case 10:
            resultado = showCircle(cp);
            imprimeResultado(resultado);
        break;
        case 11:
            imprimeResultado(0);
        break;
        
        default:
            break;
        }

    }while(escolha!=0);

    return 0;
}
