#include "imageinfo.h"
#include "stdlib.h"

ImageInfo* newImageInfo()
{
    ImageInfo* info = (ImageInfo*)malloc(sizeof(ImageInfo));
    return info;
}
unsigned int getWidth(ImageInfo* self)
{
    return self->width;
}
unsigned int getHeight(ImageInfo* self)
{
    return self->height;
}