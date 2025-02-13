/*************************************************************************/
/*  register_types.cpp                                                   */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"
#include "hbnative_singleton.h"
#include "ph_audio_stream_editor.h"
#include "ph_audio_stream_preview.h"

static PHAudioStreamPreviewGenerator *ph_ptr = NULL;
static HBNativeSingleton *hbnative_ptr = NULL;

void register_hbnative_types() {
	ph_ptr = memnew(PHAudioStreamPreviewGenerator);
	ClassDB::register_class<PHAudioStreamPreviewGenerator>();
	ClassDB::register_class<PHAudioStreamEditor>();
	ClassDB::register_class<PHAudioStreamPreview>();
	Engine::get_singleton()->add_singleton(Engine::Singleton("PHAudioStreamPreviewGenerator", PHAudioStreamPreviewGenerator::get_singleton()));
	hbnative_ptr = memnew(HBNativeSingleton);
	ClassDB::register_class<HBNativeSingleton>();
	Engine::get_singleton()->add_singleton(Engine::Singleton("HBNativeSingleton", HBNativeSingleton::get_singleton()));
}

void unregister_hbnative_types() {
	memdelete(ph_ptr);
	memdelete(hbnative_ptr);
}
