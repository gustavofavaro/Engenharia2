#include "meansd.h"

double mean_calculation(List* values){
    double sum = 0;
    Node* current_value = values->first;

    for(int i = 0; i < values->size; i++){
        sum += current_value->value;
        current_value = node_get_next(current_value);
    }

    return (double)(sum/values->size);
}

double sd_calculation(List* values){
    double mean = mean_calculation(values);
    double sum = 0;
    Node* current_value = values->first;

    for(int i = 0; i < values->size; i++){
        sum += pow((current_value->value - mean), 2);
        current_value = node_get_next(current_value);
    }

    return sqrt((double)sum/(values->size - 1));
}
