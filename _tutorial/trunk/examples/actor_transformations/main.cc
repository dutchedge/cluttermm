/*
 * Copyright (c) 2008 Openismus GmbH
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <cluttermm.h>

int main(int argc, char** argv)
{
  Clutter::init(&argc, &argv);

  // Get the stage and set its size and color:
  const Glib::RefPtr<Clutter::Stage> stage = Clutter::Stage::get_default();
  stage->set_size(200, 200);
  stage->set_color(Clutter::Color(0, 0, 0, 0xFF)); // black

  const Clutter::Color actor_color (0xff, 0xff, 0xff, 0x99);

  // Add a rectangle to the stage:
  const Glib::RefPtr<Clutter::Rectangle> rect = Clutter::Rectangle::create(actor_color);
  rect->set_size(100, 100);
  rect->set_position(20, 20);
  stage->add_actor(rect);
  rect->show();

  // Rotate it 20 degrees away from us around the x axis
  // (around its top edge):
  rect->set_rotation(Clutter::X_AXIS, -20, 0, 0, 0);

  // Add a label to the stage:
  const Glib::RefPtr<Clutter::Text> label =
      Clutter::Text::create("Sans 12", "Some Text", actor_color);
  label->set_size(500, 500);
  label->set_position(20, 150);
  stage->add_actor(label);
  label->show();

  // Scale it 300% along the x axis:
  label->set_scale(3.0, 1.0);

  // Move it up and to the right:
  label->move_by(10, -10);

  // Move it along the z axis, further from the viewer:
  label->set_depth(-20);

  // Show the stage:
  stage->show();

  // Start the main loop, so we can respond to events:
  Clutter::main();

  return 0;
}