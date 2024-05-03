/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"
#include "imagemagick.h"



void initialize_imagemagick_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
    ClassDB::register_class<ImageMagick>();

}

void uninitialize_imagemagick_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
