// gdvlc.cpp
#include "gdvlc.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void GDVLC::_bind_methods() {
    ClassDB::bind_method(D_METHOD("load_media", "path"), &GDVLC::load_media);
    ClassDB::bind_method(D_METHOD("play"), &GDVLC::play);
    ClassDB::bind_method(D_METHOD("pause"), &GDVLC::pause);
    ClassDB::bind_method(D_METHOD("stop"), &GDVLC::stop);
    ClassDB::bind_method(D_METHOD("get_position"), &GDVLC::get_position);
    ClassDB::bind_method(D_METHOD("set_position", "pos"), &GDVLC::set_position);
    ClassDB::bind_method(D_METHOD("get_duration"), &GDVLC::get_duration);
    ClassDB::bind_method(D_METHOD("is_playing"), &GDVLC::is_playing);
}

GDVLC::GDVLC() {
    vlc_instance = libvlc_new(0, nullptr);
    media_player = nullptr;
    media = nullptr;
}

GDVLC::~GDVLC() {
    if (media_player) {
        libvlc_media_player_release(media_player);
    }
    if (media) {
        libvlc_media_release(media);
    }
    if (vlc_instance) {
        libvlc_release(vlc_instance);
    }
}

void GDVLC::load_media(const String& path) {
    if (media_player) {
        libvlc_media_player_release(media_player);
    }
    if (media) {
        libvlc_media_release(media);
    }

    media = libvlc_media_new_path(vlc_instance, path.utf8().get_data());
    if (!media) {
        UtilityFunctions::print_error("Failed to load media: " + path);
        return;
    }

    media_player = libvlc_media_player_new_from_media(media);
}

void GDVLC::play() {
    if (media_player) {
        libvlc_media_player_play(media_player);
    }
}

void GDVLC::pause() {
    if (media_player) {
        libvlc_media_player_pause(media_player);
    }
}

void GDVLC::stop() {
    if (media_player) {
        libvlc_media_player_stop(media_player);
    }
}

float GDVLC::get_position() const {
    if (media_player) {
        return libvlc_media_player_get_position(media_player);
    }
    return 0.0f;
}

void GDVLC::set_position(float pos) {
    if (media_player) {
        libvlc_media_player_set_position(media_player, pos);
    }
}

float GDVLC::get_duration() const {
    if (media_player) {
        return libvlc_media_player_get_length(media_player) / 1000.0f;
    }
    return 0.0f;
}

bool GDVLC::is_playing() const {
    if (media_player) {
        return libvlc_media_player_is_playing(media_player);
    }
    return false;
}