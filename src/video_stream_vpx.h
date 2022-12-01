/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#ifndef VIDEO_STREAM_VPX_CLASS_H
#define VIDEO_STREAM_VPX_CLASS_H

// We don't need windows.h in this example plugin but many others do, and it can
// lead to annoying situations due to the ton of macros it defines.
// So we include it and make sure CI warns us if we use something that conflicts
// with a Windows define.
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/video_stream.hpp>

#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class VideoStreamVPX : public VideoStream {
	GDCLASS(VideoStreamVPX, VideoStream);

protected:
	static void _bind_methods();

	void _notification(int p_what);
	bool _set(const StringName &p_name, const Variant &p_value);
	bool _get(const StringName &p_name, Variant &r_ret) const;
	void _get_property_list(List<PropertyInfo> *p_list) const;
	bool _property_can_revert(const StringName &p_name) const;
	bool _property_get_revert(const StringName &p_name, Variant &r_property) const;

	String _to_string() const;

private:
	String file_name;

public:
	VideoStreamVPX();
	~VideoStreamVPX();

	// Functions.
	void set_file(const String &file);
	String get_file();
};

#endif // VIDEO_STREAM_VPX_CLASS_H
