/* imagemagick.cpp */

#include "imagemagick.h"
using namespace Magick; 

void ImageMagick::_bind_methods() {
    ClassDB::bind_method(D_METHOD("generate_card", "name", "title", "description", "life", "defense", "factions", "image_path", "output_path"), &ImageMagick::generate_card);
    ClassDB::bind_method(D_METHOD("generate_a4_page", "images", "output_path"), &ImageMagick::generate_a4_page);
}

void ImageMagick::generate_a4_page(const Array &p_images, const String &p_output_path) {
    //the a4 page is structured as followed: overall width is 2480px, height is 3508px, the images are 682x955px, the images are placed in a 2x2 grid, the images are placed in the center of the page

    // create a new image
    Image page("2480x3508", "white");

    // create a new image
    Image image("500x700", "white");

    // loop through the images
    for (int i = 0; i < p_images.size(); i++) {
        // load the image
        image.read(p_images[i].operator String().utf8().get_data());

        // composite the image
        page.composite(image, (i % 2) * 500, (i / 2) * 700);
    }

    // write the image
    page.write(p_output_path.utf8().get_data());

    // exit
    return;
}

void ImageMagick::generate_card(const String &p_name, const String &p_title, const String &p_description, int life, int defense, const String &factions, const String &p_image_path, const String &p_output_path) {
    //the card is structured as followed: overall width is 682px, height is 955px, the image is 500x500px the title is generated using imagemagick with a local font named "comic-book-cartunia.regular.ttf", same with the description. in the bottom the card has the life and description respecively

    // create a new image
    Image card("682x955", "white");

    // load the image
    Image image;
    image.read(p_image_path.utf8().get_data());

    // resize the image
    image.resize("500x500");

    // composite the image
    card.composite(image, 91, 91);

    // create the title
    Image title = Image(Geometry(500, 50), "white");

    // write the image
    card.write(p_output_path.utf8().get_data());

    // exit
    return;
}

ImageMagick::ImageMagick() {
    //initialize the ImageMagick library
    InitializeMagick(NULL);
}
