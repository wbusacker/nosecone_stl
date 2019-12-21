#ifndef NOSE_CONE_H
#define NOSE_CONE_H

#include <stl_gen.h>

namespace NC{

const float DISTANCE_PER_POINT = 0.1;

struct Ring{
    std::vector<struct STL::Point> points;
    float radius;
    float elevation;
};

class Nosecone{
    public:

    Nosecone();

    private:

        void build_cylinder(void);
        void build_ring(struct Ring *ring);

        void stitch_layers(void);
        
        std::vector<struct STL::Facet> facets;
        std::vector<struct NC::Ring> rings;

        float height;
        float airframe_od;
        float airframe_id;
        float shoulder_length;
        float noseone_length;

};

}

#endif