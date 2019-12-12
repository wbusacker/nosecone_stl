#include <stl_gen.h>
#include <math.h>

namespace STL{

void normalize_facet(struct Facet *fct)
{
    /* Create two vectors */
    struct STL::Spacial_vector vector_1;
    struct STL::Spacial_vector vector_2;

    vector_1.x  = fct->vertex_1.x - fct->vertex_2.x;
    vector_1.y  = fct->vertex_1.y - fct->vertex_2.y;
    vector_1.z  = fct->vertex_1.z - fct->vertex_2.z;

    vector_2.x  = fct->vertex_1.x - fct->vertex_3.x;
    vector_2.y  = fct->vertex_1.y - fct->vertex_3.y;
    vector_2.z  = fct->vertex_1.z - fct->vertex_3.z;

    /* Take the cross product */
    struct STL::Spacial_vector normal;

    normal.x    = (vector_1.y * vector_2.z) - (vector_1.z - vector_2.y);
    normal.y    = (vector_1.z * vector_2.x) - (vector_1.x - vector_2.z);
    normal.z    = (vector_1.x * vector_2.y) - (vector_1.y - vector_2.x);

    /* Normalize the Normal */
    float length;
    length = sqrt((normal.x * normal.x) + (normal.y * normal.y) + (normal.z * normal.z));

    fct->normal.i = normal.x / length;
    fct->normal.j = normal.y / length;
    fct->normal.k = normal.z / length;
}

};