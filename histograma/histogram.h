
#ifndef _HISTOGRAM_H
#define _HISTOGRAM_H

#include "image.h"

typedef struct tHistogram Histogram;

Histogram *histogram_compute(Image *image, int n_buckets);
void histogram_show(Histogram *histogram);
void histogram_destroy(Histogram *histogram);

#endif