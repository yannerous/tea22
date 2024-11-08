#ifndef TRIANGLE_H
#define TRIANGLE_H
struct Triangle{
    unsigned int side_a;
    unsigned int side_b;
    unsigned int side_c;
    unsigned int (*func)(Triangle*);
};

Triangle* newTriangle();
unsigned int perimeter(Triangle*);
#endif //TRIANGLE_H