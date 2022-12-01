#ifndef VIDEO_STREAM_VPX_CLASS_H
#define VIDEO_STREAM_VPX_CLASS_H

#include <godot_cpp/classes/video_stream.hpp>

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

#endif // VIDEO_STREAM_VPX_CLASS_H
