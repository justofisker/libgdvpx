#include "video_stream_vpx.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void VideoStreamVPX::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_file", "file"), &VideoStreamVPX::set_file);
    ClassDB::bind_method(D_METHOD("get_file"), &VideoStreamVPX::get_file);
    BIND_VIRTUAL_METHOD(VideoStreamVPX, set_audio_track) // Unsure if this is the correct method of doing this
}

void VideoStreamVPX::set_file(const String &file) {
    this->file = file;
}
