#include "triangle.h"
#include "stdlib.h"

unsigned int perimeter(Triangle* self)
{
    return self->side_a + self->side_b + self->side_c;
}

//Triangle tri; //Nur Ein Dreieck kann erzeugt werden
Triangle* newTriangle(){
    //Triangle tri; //Dreieck ist nur lokal vorhanden und wird nach return gelöscht

    Triangle* pTri =(Triangle*) malloc(sizeof(Triangle));
    pTri->side_a = 2;
    pTri->side_b = 2;
    pTri->side_c = 2;
    pTri->func = perimeter;
    return pTri;
}