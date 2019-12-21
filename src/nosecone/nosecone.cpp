#include <nosecone.h>
#include <math.h>

namespace NC
{
    
Nosecone::Nosecone(){

    shoulder_length = 4 * 25.4;
    height = 0;
    airframe_id = 0;
    airframe_od = 0;
    noseone_length = 0;

    build_cylinder();
    stitch_layers();


}

} // namespace NC
