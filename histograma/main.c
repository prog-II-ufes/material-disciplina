
#include <stdio.h>
#include "image.h"
#include "histogram.h"

int main() {
    char path[1024]; // nome do arquivo que contem a imagem
    int n_buckets;   // numero de intervalos

    Image *image;
    Histogram *histogram;

    scanf("%s", path);
    scanf("%d", &n_buckets);

    image = image_read(path);
    histogram = histogram_compute(image, n_buckets);
    histogram_show(histogram);
    histogram_destroy(histogram);

    return 0;
}