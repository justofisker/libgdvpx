#include "video_stream_vpx.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/file_access.hpp>

using namespace godot;

void VideoStreamVPX::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_file", "file"), &VideoStreamVPX::set_file);
    ClassDB::bind_method(D_METHOD("get_file"), &VideoStreamVPX::get_file);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "file", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NO_EDITOR | PROPERTY_USAGE_INTERNAL), "set_file", "get_file");
    BIND_VIRTUAL_METHOD(VideoStreamVPX, set_audio_track) // Unsure if this is the correct method of doing this
}

void VideoStreamVPX::set_file(const String &file) {
    this->file = file;
}

////////////

Ref<Resource> ResourceFormatLoaderVPX::load(const String &p_path, const String &p_original_path, Error *r_error, bool p_use_sub_threads, float *r_progress, CacheMode p_cache_mode) {
	Ref<FileAccess> f = FileAccess::open(p_path, FileAccess::READ);
	if (f.is_null()) {
		if (r_error) {
			*r_error = ERR_CANT_OPEN;
		}
		return Ref<Resource>();
	}

	VideoStreamVPX *stream = memnew(VideoStreamVPX);
	stream->set_file(p_path);

	Ref<VideoStreamVPX> vpx_stream = Ref<VideoStreamVPX>(stream);

	if (r_error) {
		*r_error = OK;
	}

	return vpx_stream;
}

void ResourceFormatLoaderVPX::get_recognized_extensions(List<String> *p_extensions) const {
	p_extensions->push_back("webm");
}

bool ResourceFormatLoaderVPX::handles_type(const String &p_type) const {
    return p_type == "VideoStream" || p_type == "VideoStreamVPX";
    // Don't have access to this function
	//return ClassDB::is_parent_class(p_type, "VideoStream");
}

String ResourceFormatLoaderVPX::get_resource_type(const String &p_path) const {
	String el = p_path.get_extension().to_lower();
	if (el == "webm") {
		return "VideoStreamVPX";
	}
	return "";
}
