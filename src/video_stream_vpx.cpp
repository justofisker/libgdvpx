/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "video_stream_vpx.h"

#include <godot_cpp/core/class_db.hpp>

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void VideoStreamVPX::_notification(int p_what) {
	UtilityFunctions::print("Notification: ", String::num(p_what));
}

bool VideoStreamVPX::_set(const StringName &p_name, const Variant &p_value) {
	return false;
}

bool VideoStreamVPX::_get(const StringName &p_name, Variant &r_ret) const {
	return false;
}

String VideoStreamVPX::_to_string() const {
	return "[ GDExtension::Example <--> Instance ID:" + uitos(get_instance_id()) + " ]";
}

void VideoStreamVPX::_get_property_list(List<PropertyInfo> *p_list) const {
	// Nothing
}

bool VideoStreamVPX::_property_can_revert(const StringName &p_name) const {
	return false;
};

bool VideoStreamVPX::_property_get_revert(const StringName &p_name, Variant &r_property) const {
	return false;
};

void VideoStreamVPX::_bind_methods() {
	// Methods.


    ClassDB::bind_method(D_METHOD("set_file", "file"), &VideoStreamVPX::set_file);
    ClassDB::bind_method(D_METHOD("get_file"), &VideoStreamVPX::get_file);
}

VideoStreamVPX::VideoStreamVPX() {
	UtilityFunctions::print("Constructor.");
}

VideoStreamVPX::~VideoStreamVPX() {
	UtilityFunctions::print("Destructor.");
}

// Methods.

String VideoStreamVPX::get_file() {
    return file_name;
}

void VideoStreamVPX::set_file(const String &file) {
    file_name = file;
}