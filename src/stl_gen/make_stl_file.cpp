#include <stl_gen.h>
#include <stdlib.h>
#include <stdio.h>

namespace STL{

void make_stl_file(std::vector<struct Facet> facets){

    if(facets.size() > 0xFFFFFFFF){
        printf("Warning! Too many points for STL file!\n");
        fflush(stdout);
        exit(-1);
    }

    FILE *fp;

    fp = fopen("output.stl", "w");

    char header[STL::BYTES_IN_HEADER];

    uint32_t i;
    for(i = 0; i < STL::BYTES_IN_HEADER; i++){
        header[i] = ' ';
    }
    
    sprintf(header, "STLB ATF 8.12.0.6 COLOR=ddd} Built by RRSE");

    fwrite(header, 1, STL::BYTES_IN_HEADER, fp);



    uint32_t num_facets = facets.size();
    fwrite(&num_facets, 1, sizeof(num_facets), fp);

    for(i = 0; i <facets.size(); i++){

        /* Only print every 100 facets */
        if((i % 100) == 0){
            printf("\rSaving Facet %d:%d", i, facets.size());
            fflush(stdout);
        }

        fwrite(&(facets[i]), 1, sizeof(struct STL::Facet), fp);
    }

    fclose(fp);

    printf("\n");

    return;

}

}