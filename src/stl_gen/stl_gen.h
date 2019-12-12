#ifndef STL_GEN_H
#define STL_GEN_H

#include <stdint.h>
#include <vector>

namespace STL{
    const uint8_t BYTES_IN_HEADER       = 80;

    struct Point{
        float x;
        float y;
        float z;
    };

    struct Normal{
        float i;
        float j;
        float k;
    };

    struct Spacial_vector{
        float x;
        float y;
        float z;
    };

    struct Facet{
        struct Normal   normal;
        struct Point    vertex_1;
        struct Point    vertex_2;
        struct Point    vertex_3;
        uint16_t        attribute;
    } __attribute__((packed));

    void normalize_facet(struct Facet *fct);
    void build_facet(struct Facet *fct, float p1[3], float p2[3], float p3[3]);
    void make_stl_file(std::vector<struct Facet> facets);

/* End Namespace */
};

#endif