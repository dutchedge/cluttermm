// -*- c++ -*-
#ifndef _LIBCLUTTERMM_MAIN_H
#define _LIBCLUTTERMM_MAIN_H
/*
 * Copyright 2008 Jonathon Jongsma
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glibmm.h>
#include <cluttermm/actor.h>

namespace Clutter
{

/** Starts the Clutter mainloop.
 */
void main();

/** Terminates the Clutter mainloop.
 */
void main_quit();

/** Retrieves the depth of the Clutter mainloop.
 * @return The level of the mainloop.
 */
int main_level();

#ifndef CLUTTERMM_DISABLE_DEPRECATED
/** Check if clutter has debugging turned on.
 * @return true if debugging is turned on, false otherwise.
 *
 * @deprecated
 */
bool get_debug_enabled();

/** Returns whether Clutter should print out the frames per second on the
 * console. You can enable this setting either using the CLUTTER_SHOW_FPS
 * environment variable or passing the --clutter-show-fps command line
 * argument.
 * @return true if Clutter should show the FPS.
 *
 * @deprecated Use the environment variable or the configuration file to determine whether Clutter should print out the FPS counter on the console.
 */
bool get_show_fps();

/** Returns the approximate number of microseconds passed since clutter was
 * intialised.
 * @return Number of microseconds since clutter_init() was called.
 *
 * @deprecated Use Glib::Timer or g_get_monotonic_time() for a proper timing source.
 */
gulong get_timestamp();

/** Retrieves the Actor with id.
 * @param id an Actor ID.
 * @return the actor with the passed id or a NULL RefPtr.
 *
 * @deprecated The id is not used any longer.
 */
Glib::RefPtr<Actor> get_actor_by_gid(guint32 id);

/** Sets the default frame rate to be used when creating Timeline objects.
 * @param frames_per_sec the new default frame rate.
 *
 * @deprecated This function does not do anything any more.
 */
void set_default_frame_rate(guint frames_per_sec);
#endif //CLUTTERMM_DISABLE_DEPRECATED

/** Retrieves the default frame rate used when creating ClutterTimelines.
 *
 * This value is also used to compute the default frequency of motion events.
 * @return the default frame rate
 */
guint get_default_frame_rate();

#ifndef CLUTTERMM_DISABLE_DEPRECATED
/** Sets whether per-actor motion events should be enabled or not
 * (the default is to enable them).
 *
 * If enable is false the following events will not work:
 *
 * <ul>
 *  <li>ClutterActor::motion-event, unless on the ClutterStage</li>
 *  <li>ClutterActor::enter-event</li>
 *  <li>ClutterActor::leave-event</li>
 * </ul>
 *
 * @param enable true to enable per-actor motion events.
 *
 * @deprecated Use Stage::set_motion_events_enabled() instead.
 */
void set_motion_events_enabled(bool enable);

/** Gets whether the per-actor motion events are enabled.
 * @return true if the motion events are enabled.
 *
 * @deprecated Use Stage::get_motion_events_enabled() instead.
 */
bool get_motion_events_enabled();

/** Clears the internal cache of glyphs used by the Pango renderer. This will
 * free up some memory and GL texture resources. The cache will be
 * automatically refilled as more text is drawn.
 *
 * @deprecated Use get_font_map() and cogl_pango_font_map_clear_glyph_cache() instead.
 */
void clear_glyph_cache();

//TODO: Documentation:

/**
 * @deprecated Use Backend::set_font_options() and the cairo_font_option_t API.
 */
void set_font_flags(FontFlags flags);

/**
 * @deprecated Use Backend::get_font_options() and the cairo_font_option_t API.
 */
FontFlags get_font_flags();
#endif //CLUTTERMM_DISABLE_DEPRECATED

Glib::RefPtr<Pango::FontMap> get_font_map();

/** Queries the current keyboard grab of clutter.
 * @return the actor currently holding the keyboard grab, or an empty
 * Glib::RefPtr if there is no grab.
 */
Glib::RefPtr<Actor> get_keyboard_grab();

/** Queries the current pointer grab of clutter.
 * @return the actor currently holding the pointer grab, or am empty
 * Glib::RefPtr if there is no grab.
 */
Glib::RefPtr<Actor> get_pointer_grab();

/** Grabs keyboard events, after the grab is done keyboard events
 * ("key-press-event" and "key-release-event") are delivered to this actor
 * directly. The source set in the event will be the actor that would have
 * received the event if the keyboard grab was not in effect.
 * @param actor An Actor
 */
void grab_keyboard(const Glib::RefPtr<Actor>& actor);

/** Grabs pointer events, after the grab is done all pointer related events
 * (press, motion, release, enter, leave and scroll) are delivered to this
 * actor directly. The source set in the event will be the actor that would
 * have received the event if the pointer grab was not in effect.
 *
 * If you wish to grab all the pointer events for a specific input device,
 * you should use grab_pointer_for_device().
 * @param actor An Actor
 */
void grab_pointer(const Glib::RefPtr<Actor>& actor);

/** Removes an existing grab of the keyboard.
 */
void ungrab_keyboard();

/** Removes an existing grab of the pointer.
 */
void ungrab_pointer();

#ifndef CLUTTERMM_DISABLE_DEPRECATED
/** Grabs all the pointer events coming from the device id for actor.
 *
 * If id is -1 then this function is equivalent to grab_pointer().
 *
 * @param actor An Actor.
 * @param id a device id, or -1
 *
 * @deprecated Use InputDevice::grab() instead.
 */
void grab_pointer_for_device(const Glib::RefPtr<Actor>& actor, int id);

/** Removes an existing grab of the pointer events for device id.
 *
 * @param a device id
 *
 * @deprecated Use InputDevice::ungrab() instead.
 */
void ungrab_pointer_for_device(int id);
#endif //CLUTTERMM_DISABLE_DEPRECATED

#if 0
// As this function should never be used by applications, we don't wrap it
// until someone really needs it.
/** Processes an event. This function should never be called by applications.
 * @param event An Event.
 */
void do_event(Event* event);
#endif

} //namespace Clutter

#endif //_LIBCLUTTERMM_MAIN_H

