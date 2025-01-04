#include "sgg/graphics.h" 
#include "sgg/scancodes.h"
#include <stdio.h> 
#include <string>
#include "util.h"


//this is the NEW project
//
//
struct GameState {
	std::string m_asset_path = "assets\\";
	float m_canvas_width = 8.0f;
	float m_canvas_height = 8.0f;


	graphics::Brush m_br_background;
	graphics::Brush m_br_play1;
	float m_p1_x = m_canvas_width / 2.0f;
	float m_p1_y = m_canvas_height / 2.0f;
	float m_p1_size = 1.0f;

	graphics::Brush m_br_play2;
	float m_p2_x = (m_canvas_width / 2) + 1.0f;
	float m_p2_y = (m_canvas_height / 2) + 1.0f;
	float m_p2_size = 1.0f;

	float m_global_offset1_x = 0.0f;
	float m_global_offset1_y = 0.0f;

	float m_global_offset2_x = 0.0f;
	
};

GameState state;

void init() {

	//background
	SETCOLOR(state.m_br_background.fill_color, 1.0f, 1.0f, 1.0f);
	state.m_br_background.outline_opacity = 0.0f;
	state.m_br_background.texture = state.m_asset_path + "bg0.png";

	//setting up player 1
	state.m_br_play1.fill_color[0] = 0.9f;
	state.m_br_play1.fill_color[1] = 0.5f;
	state.m_br_play1.fill_color[2] = 0.1f;
	state.m_br_play1.fill_opacity = 0.5f;
	state.m_br_play1.outline_opacity = 0.0f;
	state.m_br_play1.texture = state.m_asset_path + "p1s0.png";

	//setting up player 2
	state.m_br_play2.fill_color[0] = 0.0f;
	state.m_br_play2.fill_color[1] = 0.0f;
	state.m_br_play2.fill_color[2] = 0.0f;
	state.m_br_play2.fill_opacity = 0.5f;
	state.m_br_play2.outline_opacity = 0.0f;
	state.m_br_play1.texture = state.m_asset_path + "p1s0.png";
	
	//setting up the background

	/*
	state.m_br_background.fill_color[0] = 1.0f;
	state.m_br_background.fill_color[1] = 1.0f;
	state.m_br_background.fill_color[2] = 1.0f;
	state.m_br_background.outline_opacity = 0.0f;
	*/


	


}


void draw() {

	graphics::drawRect(state.m_canvas_width / 2.0f, state.m_canvas_height / 2.0f, state.m_canvas_width, state.m_canvas_height, state.m_br_background); //background

	graphics::drawRect(state.m_p1_x, state.m_p1_y, state.m_p1_size, state.m_p1_size, state.m_br_play1); //player 1

	graphics::drawRect(state.m_p2_x, state.m_p2_y, state.m_p2_size, state.m_p2_size, state.m_br_play2); //player 2

}
void update(float dt) {

	// float p = 0.5 + fabs(cos(graphics::getGlobalTime()/ 512.0f));
	//state.m_br_background.fill_color[0] = p /2;
	//state.m_br_background.fill_color[1] = p;
	//state.m_br_background.fill_color[2] = p;

	float dtt = dt / 1000.0f;
	const float vel = 8.0f;

	// player 1 controls setup 
	if (graphics::getkeyState(graphics::SCANCODE_UP))
		state.m_p1_y += vel * dtt;

	if (graphics::getkeyState(graphics::SCANCODE_DOWN))
		state.m_p1_y -= vel * dtt;

	if (graphics::getkeyState(graphics::SCANCODE_LEFT))
		state.m_p1_x -= vel * dtt;

	if (graphics::getkeyState(graphics::SCANCODE_RIGHT))
		state.m_p1_x += vel * dtt;

	//player 2 controls setup
	
	if (graphics::getkeyState(graphics::SCANCODE_A))
		state.m_p2_x -= vel * dtt;

	if (graphics::getkeyState(graphics::SCANCODE_D))
		state.m_p2_x += vel * dtt;

	state.m_global_offset1_x = state.m_canvas_width / 2.0f - state.m_p1_x;
	state.m_global_offset1_y = state.m_canvas_height / 2.0f - state.m_p1_x;

	state.m_global_offset2_x = state.m_canvas_width / 2.0f - state.m_p2_x;




}

int main(int argc, char** argv) {

	graphics::createWindow(512, 512, "S p a c e d  O u t");
	init();
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);
	graphics::setCanvasSize(state.m_canvas_width, state.m_canvas_height);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
	graphics::startMessageLoop();


	return 0;
}