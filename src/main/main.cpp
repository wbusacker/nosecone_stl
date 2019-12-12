#include <stdio.h>
#include <stl_gen.h>

int main(void){

    std::vector<struct STL::Facet> lists;

    float top[3]        = {0, 0, 10};
    float corner_1[3]   = {-5, 5, 0};
    float corner_2[3]   = {5, 0, 0};
    float corner_3[3]   = {-5, -5, 0};

    struct STL::Facet fct;

    STL::build_facet(&fct, top, corner_1, corner_2);
    lists.push_back(fct);

    STL::build_facet(&fct, top, corner_2, corner_3);
    lists.push_back(fct);

    STL::build_facet(&fct, top, corner_3, corner_1);
    lists.push_back(fct);

    STL::build_facet(&fct, corner_3, corner_1, corner_2);
    lists.push_back(fct);

    make_stl_file(lists);

    return 0;
}