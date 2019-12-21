#include <nosecone.h>
#include <math.h>
#include <stdio.h>

namespace NC
{
    
void Nosecone::build_ring(struct Ring *ring){

    /* Calculate the number of points in the ring */
    float circumference = 2 * ring->radius * M_PI;
    uint16_t points_in_ring = (uint16_t)(circumference / DISTANCE_PER_POINT);

    float radians_per_point = (2 * M_PI) / points_in_ring;

    /* Begin populating the Ring */
    ring->points.clear();

    uint16_t i;
    struct STL::Point p;
    for(i = 0; i < points_in_ring; i++){
        p.x = cos(i * radians_per_point);
        p.y = sin(i * radians_per_point);
        p.z = ring->elevation;

        ring->points.push_back(p);
    }

}

} // namespace NC
