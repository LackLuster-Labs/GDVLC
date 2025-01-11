// register_types.h
#ifndef GDVLC_REGISTER_TYPES_H
#define GDVLC_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void initialize_gdvlc_module(ModuleInitializationLevel p_level);
void uninitialize_gdvlc_module(ModuleInitializationLevel p_level);

#endif // GDVLC_REGISTER_TYPES_H