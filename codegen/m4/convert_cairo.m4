_CONVERSION(`const ::Cairo::RefPtr<Cairo::Path>&',`const cairo_path_t*',`($3)->cobj()')
_CONVERSION(`::Cairo::RefPtr<Cairo::Context>&',`cairo_t*',`($3)->cobj()')
_CONVERSION(`::Cairo::RefPtr< ::Cairo::Context >&',`cairo_t*',`($3)->cobj()')
_CONVERSION(`cairo_t*',`::Cairo::RefPtr< ::Cairo::Context >',`$2(new ::Cairo::Context ($3, true))')
_CONVERSION(`const cairo_font_options_t*',`::Cairo::FontOptions',`$2(const_cast<cairo_font_options_t*>($3), true)')
_CONVERSION(`const ::Cairo::FontOptions&',`const cairo_font_options_t*',`($3).cobj()')
