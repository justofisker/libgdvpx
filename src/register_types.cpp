#include "register_types.h"

#include <godot/gdnative_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/resource_loader.hpp>

#include "video_stream_vpx.h"

using namespace godot;

static Ref<ResourceFormatLoaderVPX> resource_loader_vpx;

void initialize_vpx_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	resource_loader_vpx.instantiate();
	ResourceLoader::get_singleton()->add_resource_format_loader(resource_loader_vpx, true);

	GDREGISTER_CLASS(VideoStreamVPX);
	
}

void uninitialize_vpx_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ResourceLoader::get_singleton()->remove_resource_format_loader(resource_loader_vpx);
	resource_loader_vpx.unref();
}

extern "C" {
// Initialization.
GDNativeBool GDN_EXPORT vpx_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_initializer(initialize_vpx_module);
	init_obj.register_terminator(uninitialize_vpx_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
