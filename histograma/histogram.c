
#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "histogram.h"

struct tHistogram {
    int *counts;
    int bucket_size;
    int n_buckets;
};

Histogram *histogram_compute(Image *img, int n_buckets) {
    int val;
    Histogram *hist = (Histogram *)calloc(1, sizeof(Histogram));
    hist->n_buckets = n_buckets;
    hist->bucket_size = 256 / n_buckets;

    if (256 % n_buckets != 0)
        hist->bucket_size += 1;

    hist->counts = (int *)calloc(hist->n_buckets, sizeof(int));

    for (int i = 0; i < get_height(img) * get_width(img); i++) {
        if (get_type(img) == INT)
            val = ((int *)get_data(img))[i];
        else
            val = (255 * ((float *)get_data(img))[i]);

        int idx = val / hist->bucket_size;

        hist->counts[idx]++;
    }

    return hist;
}

void histogram_show(Histogram *histogram) {
    int total_pixels = 0;
    for (int i = 0; i < histogram->n_buckets; i++)
    {
        printf("[%d, %d): %d\n",
               i * histogram->bucket_size,
               (i + 1) * histogram->bucket_size,
               histogram->counts[i]);
        total_pixels += histogram->counts[i];
    }

    // printf("total_pixels: %d\n", total_pixels);
}

void histogram_destroy(Histogram *histogram) {
    free(histogram->counts);
    free(histogram);
}