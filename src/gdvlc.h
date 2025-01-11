// gdvlc.h
#ifndef GDVLC_H
#define GDVLC_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <vlc/vlc.h>

namespace godot {

class GDVLC : public Node {
    GDCLASS(GDVLC, Node)

private:
    libvlc_instance_t* vlc_instance;
    libvlc_media_player_t* media_player;
    libvlc_media_t* media;

protected:
    static void _bind_methods();

public:
    GDVLC();
    ~GDVLC();

    void load_media(const String& path);
    void play();
    void pause();
    void stop();
    float get_position() const;
    void set_position(float pos);
    float get_duration() const;
    bool is_playing() const;
};

}

#endif // GDVLC_H