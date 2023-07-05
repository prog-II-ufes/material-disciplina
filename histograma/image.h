

#ifndef _IMAGE_H
#define _IMAGE_H

typedef enum {
    FLOAT = 0,
    INT = 1
} Type;

typedef struct tImage Image;

Image *image_read(const char *path);
void image_destroy(Image *img);
int get_height(Image *img);
int get_width(Image *img);
Type get_type(Image *img);
void *get_data(Image *img);

#endif