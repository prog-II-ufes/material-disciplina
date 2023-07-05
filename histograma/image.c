
#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include <stdio.h>

struct tImage {
    int height;
    int width;
    Type type;
    void *data;
};

int get_height(Image *img) {
    return img->height;
}

int get_width(Image *img) {
    return img->width;
}

Type get_type(Image *img) {
    return img->type;
}

void *get_data(Image *img) {
    return img->data;
}

Image *image_read(const char *path) {
    FILE *f = fopen(path, "rb");

    if (f == NULL)
        exit(printf("Arquivo '%s' nao encontrado.\n", path));

    int pixel_size;
    Image *image = (Image *)calloc(1, sizeof(Image));

    fread(&image->height, 1, sizeof(int), f);
    fread(&image->width, 1, sizeof(int), f);
    fread(&image->type, 1, sizeof(int), f);

    // Debug
    // printf("alt: %d larg: %d tipo: %d total: %d\n",
    //        image->altura,
    //        image->largura,
    //        image->tipo,
    //        image->altura * image->largura);

    if (image->type == FLOAT)
        pixel_size = sizeof(float);
    else if (image->type == INT)
        pixel_size = sizeof(int);

    image->data = calloc(image->height * image->width, pixel_size);

    // o teste do tipo nao eh necessario aqui apenas porque floats e ints tem
    // o mesmo tamanho (4 bytes)
    fread(image->data, image->height * image->width, sizeof(float), f);

    fclose(f);

    return image;
}

void image_destroy(Image *img) {
    free(img->data);
    free(img);
}