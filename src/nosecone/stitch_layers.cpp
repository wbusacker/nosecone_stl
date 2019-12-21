#include <nosecone.h>
#include <stdio.h>

namespace NC
{
    
void Nosecone::stitch_layers(void){

    /* Iterate through all adjacent layer pairs */
    uint32_t bottom_layer_index;
    struct NC::Ring *bl;
    struct NC::Ring *tl;
    uint32_t bl_index = 0;
    uint32_t tl_index = 0;
    struct STL::Facet fct;

    for(bottom_layer_index = 0; bottom_layer_index < (rings.size() - 1); bottom_layer_index++){
        printf("\rStiching Layer %d:%d", bottom_layer_index, (rings.size() - 1));
        fflush(stdout);
        uint32_t top_layer_index = bottom_layer_index + 1;

        bl  = &(rings[bottom_layer_index]);
        tl  = &(rings[top_layer_index]);

        /* Stitch bottom to top */
        for(bl_index = 0; bl_index < bl->points.size(); bl_index++){
            // printf("\rStiching Layer %d:%d | bl %d:%ld", bottom_layer_index, (rings.size() - 1), bl_index,(bl->points.size() - 1) );
            // fflush(stdout);
            float p1[3];
            float p2[3];
            float p3[3];

            uint32_t second_bl_index = (bl_index + 1 ) % bl->points.size();

            p1[0] = bl->points[bl_index].x;
            p1[1] = bl->points[bl_index].y;
            p1[2] = bl->points[bl_index].z;

            p2[0] = tl->points[tl_index].x;
            p2[1] = tl->points[tl_index].y;
            p2[2] = tl->points[tl_index].z;

            p3[0] = bl->points[second_bl_index].x;
            p3[1] = bl->points[second_bl_index].y;
            p3[2] = bl->points[second_bl_index].z;

            // printf("Stitching\n");
            // printf("Bottom %d ", bl_index);
            // printf("{%7.3f, %7.3f, %7.3f}\t", p1[0], p1[1], p1[2]);
            
            // printf("Top %d ", tl_index);
            // printf("{%7.3f, %7.3f, %7.3f}\t", p2[0], p2[1], p2[2]);
            
            // printf("Bottom %d ", second_bl_index);
            // printf("{%7.3f, %7.3f, %7.3f}\t", p3[0], p3[1], p3[2]);
            // printf("\n");
            // fflush(stdout);

            STL::build_facet(&fct, p1, p2, p3);
            facets.push_back(fct);

            if(tl_index < tl->points.size()){
                tl_index++;
            }
        }

        bl_index = 1;
        tl_index = 0;

        /* Stitch top to bottom */
        for(tl_index = 0; tl_index < tl->points.size(); tl_index++){
            // printf("\rStiching Layer %d:%d | tl %d:%ld", bottom_layer_index, (rings.size() - 1), tl_index,(tl->points.size() - 1) );
            // fflush(stdout);
            float p1[3];
            float p2[3];
            float p3[3];

            uint32_t second_tl_index = (tl_index + 1 ) % tl->points.size();

            // printf("Stitching Top %d -> Bottom %d -> Top %d\n", tl_index, bl_index, second_tl_index);
            fflush(stdout);


            p1[0] = tl->points[tl_index].x;
            p1[1] = tl->points[tl_index].y;
            p1[2] = tl->points[tl_index].z;

            p2[0] = bl->points[bl_index].x;
            p2[1] = bl->points[bl_index].y;
            p2[2] = bl->points[bl_index].z;

            p3[0] = tl->points[second_tl_index].x;
            p3[1] = tl->points[second_tl_index].y;
            p3[2] = tl->points[second_tl_index].z;

            // printf("Stitching\n");
            // printf("Top %d ", tl_index);
            // printf("{%7.3f, %7.3f, %7.3f}\t", p1[0], p1[1], p1[2]);
            
            // printf("Bottom %d ", bl_index);
            // printf("{%7.3f, %7.3f, %7.3f}\t", p2[0], p2[1], p2[2]);
            
            // printf("Top %d ", second_tl_index);
            // printf("{%7.3f, %7.3f, %7.3f}\t", p3[0], p3[1], p3[2]);
            // printf("\n");
            // fflush(stdout);

            STL::build_facet(&fct, p1, p2, p3);
            facets.push_back(fct);

            bl_index = (bl_index + 1 ) % bl->points.size();
            
        }
    }
    printf("\n");

    bl  = &(rings[0]);
    tl  = &(rings[rings.size() - 1]);

    /* Do a special stich on the end layers */
    for(bl_index = 0; bl_index < (bl->points.size()); bl_index++){
        // printf("\rStiching Layer %d:%d | bl %d:%ld", bottom_layer_index, (rings.size() - 1), bl_index,(bl->points.size() - 1) );
        // fflush(stdout);
        float p1[3];
        float p2[3];
        float p3[3];
        
        uint32_t second_bl_index = (bl_index + 1 ) % bl->points.size();

        p1[0] = bl->points[bl_index].x;
        p1[1] = bl->points[bl_index].y;
        p1[2] = bl->points[bl_index].z;

        p2[0] = 0;
        p2[1] = 0;
        p2[2] = 0;

        p3[0] = bl->points[second_bl_index].x;
        p3[1] = bl->points[second_bl_index].y;
        p3[2] = bl->points[second_bl_index].z;

        STL::build_facet(&fct, p1, p2, p3);
        facets.push_back(fct);
    }
    for(tl_index = 0; tl_index < (tl->points.size()); tl_index++){
        // printf("\rStiching Layer %d:%d | tl %d:%ld", bottom_layer_index, (rings.size() - 1), tl_index,(tl->points.size() - 1) );
        // fflush(stdout);
        float p1[3];
        float p2[3];
        float p3[3];

        uint32_t second_tl_index = (tl_index + 1 ) % tl->points.size();

        p1[0] = tl->points[tl_index].x;
        p1[1] = tl->points[tl_index].y;
        p1[2] = tl->points[tl_index].z;

        p2[0] = 0;
        p2[1] = 0;
        p2[2] = tl->elevation;

        p3[0] = tl->points[second_tl_index].x;
        p3[1] = tl->points[second_tl_index].y;
        p3[2] = tl->points[second_tl_index].z;

        STL::build_facet(&fct, p1, p2, p3);
        facets.push_back(fct);
    }


    STL::make_stl_file(facets);


}

} // namespace NC
