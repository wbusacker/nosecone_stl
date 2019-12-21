#include <nosecone.h>
#include <stdio.h>

namespace NC
{
    
void Nosecone::build_cylinder(void){

    /* Calculate number of layers */
    float layers = (shoulder_length / DISTANCE_PER_POINT);
    // float layers = 2;

    printf("Building %f Layers\n", layers);
    fflush(stdout);

    struct Ring ring;
    uint32_t i;
    uint32_t i_layers = (uint32_t)layers;
    for(i = 0; i < i_layers; i++){
        printf("\rBuilding Layer %d:%d", i, i_layers);
        ring.elevation  = i * DISTANCE_PER_POINT;
        ring.radius     = 4 * 25.4;
        build_ring(&ring);
        rings.push_back(ring);
    }
    printf("\n");

}

} // namespace NC
