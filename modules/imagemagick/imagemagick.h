/* imagemagick.h */

#ifndef IMAGEMAGICK_H
#define IMAGEMAGICK_H

#include "core/object/ref_counted.h"

// include the ImageMagick library
#include <Magick++.h>


class ImageMagick : public RefCounted {
    GDCLASS(ImageMagick, RefCounted);

    protected:
        static void _bind_methods();

    public:
        // takes a card name, title, description, image path and output path
        void generate_card(const String &p_name, const String &p_title, const String &p_description, int life, int defense, const String &factions, const String &p_image_path, const String &p_output_path);

        //takes a list of card images and output path
        void generate_a4_page(const Array &p_images, const String &p_output_path);

        ImageMagick();
};

#endif // IMAGEMAGICK_H