#ifndef VIDEO_STREAM_VPX_CLASS_H
#define VIDEO_STREAM_VPX_CLASS_H

#include <godot_cpp/classes/video_stream.hpp>
#include <godot_cpp/classes/resource_format_loader.hpp>

using namespace godot;

class VideoStreamVPX : public VideoStream {
	GDCLASS(VideoStreamVPX, VideoStream);

	String file;
	int audio_track;

protected:
	static void _bind_methods();

public:
	void set_file(const String &file);
	String get_file() { return file; };
	virtual void set_audio_track(int p_track) { audio_track = p_track; }

	VideoStreamVPX() { audio_track = 0; }
};

class ResourceFormatLoaderVPX : public ResourceFormatLoader {
public:
	virtual Ref<Resource> load(const String &p_path, const String &p_original_path = "", Error *r_error = nullptr, bool p_use_sub_threads = false, float *r_progress = nullptr, CacheMode p_cache_mode = CACHE_MODE_REUSE);
	virtual void get_recognized_extensions(List<String> *p_extensions) const;
	virtual bool handles_type(const String &p_type) const;
	virtual String get_resource_type(const String &p_path) const;
};

#endif // VIDEO_STREAM_VPX_CLASS_H
