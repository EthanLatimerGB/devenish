#include <pebble.h>
#include "home.h"

static Window *s_window;
static TextLayer *s_text_layer;

int main(void)
{
	h_init();

	APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p",
		s_window);
	app_event_loop();

	h_destroy();
}
