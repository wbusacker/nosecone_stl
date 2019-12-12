#include <stl_gen.h>

namespace STL{

void build_facet(struct Facet *fct, float p1[3], float p2[3], float p3[3]){
    fct->vertex_1.x = p1[0];
    fct->vertex_1.y = p1[1];
    fct->vertex_1.z = p1[2];

    fct->vertex_2.x = p2[0];
    fct->vertex_2.y = p2[1];
    fct->vertex_2.z = p2[2];

    fct->vertex_3.x = p3[0];
    fct->vertex_3.y = p3[1];
    fct->vertex_3.z = p3[2];

    fct->attribute  = 20083;

    normalize_facet(fct);

    return;
}

};