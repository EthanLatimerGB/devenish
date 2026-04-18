#include <pebble.h>
#include "home.h"

static Window *h_window;

// Labels
static TextLayer *h_time;
static TextLayer *h_lab_conn_status;
static TextLayer *h_lab_blood_sugar;
static TextLayer *h_lab_last_updated;

const bool animated = true;

const GColor color_background = GColorCadetBlue;
const GColor color_on_background = GColorWhite;

/*
 * Window Layer Configuration
*/
static void h_click_configuration(void *context)
{
	// window_single_click_subscribe(BUTTON_ID_SELECT, prv_select_click_handler);
	// window_single_click_subscribe(BUTTON_ID_UP, prv_up_click_handler);
	// window_single_click_subscribe(BUTTON_ID_DOWN, prv_down_click_handler);
}

static void h_window_load(Window *window)
{
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_bounds(window_layer);

	// Creating TextLayers
	h_time = text_layer_create(GRect(0, 0, bounds.size.w, 20));
	h_lab_blood_sugar = text_layer_create(GRect(0, 20, bounds.size.w, 20));
	h_lab_last_updated = text_layer_create(GRect(0, 40, bounds.size.w, 20));
	h_lab_conn_status = text_layer_create(GRect(0, 60, bounds.size.w, 20));

	// Setting Text
	text_layer_set_text(h_time, "12:43");
	text_layer_set_text(h_lab_blood_sugar, "6.7");
	text_layer_set_text(h_lab_last_updated, "2 minutes ago");
	text_layer_set_text(h_lab_conn_status, "LIVE");

	// Alignment
	text_layer_set_text_alignment(h_lab_blood_sugar, GTextAlignmentCenter);

	// Adding Children
	layer_add_child(window_layer, text_layer_get_layer(h_time));
	layer_add_child(window_layer, text_layer_get_layer(h_lab_blood_sugar));
	layer_add_child(window_layer, text_layer_get_layer(h_lab_last_updated));
	layer_add_child(window_layer, text_layer_get_layer(h_lab_conn_status));
}

static void h_window_destroy(Window *window)
{
	text_layer_destroy(h_time);
	text_layer_destroy(h_lab_blood_sugar);
	text_layer_destroy(h_lab_last_updated);
	text_layer_destroy(h_lab_conn_status);
}

/*
 * Window Configuration
*/
void h_init(void)
{
	h_window = window_create();

	window_set_background_color(h_window, color_background);
	window_set_click_config_provider(h_window, h_click_configuration);
	window_set_window_handlers(h_window, (WindowHandlers) {
				   .load = h_window_load,.unload =
				   h_window_destroy,});

	window_stack_push(h_window, animated);
}

void h_destroy(void)
{
	window_destroy(h_window);
}
