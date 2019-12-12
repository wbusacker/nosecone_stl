#include <stl_gen.h>
#include <stdlib.h>
#include <stdio.h>

namespace STL{

void make_stl_file(std::vector<struct Facet> facets){

    FILE *fp;

    fp = fopen("output.stl", "w");

    char header[STL::BYTES_IN_HEADER];

    uint16_t i;
    for(i = 0; i < STL::BYTES_IN_HEADER; i++){
        header[i] = ' ';
    }
    
    sprintf(header, "STLB ATF 8.12.0.6 COLOR=ddd\0 Built by RRSE");

    fwrite(header, 1, STL::BYTES_IN_HEADER, fp);

    uint32_t num_facets = facets.size();
    fwrite(&num_facets, 1, sizeof(num_facets), fp);

    for(i = 0; i <facets.size(); i++){
        fwrite(&(facets[i]), 1, sizeof(struct STL::Facet), fp);
    }

    fclose(fp);

    return;

}

}