#pragma once
#include <string>
#include "sgg/graphics.h"

class GameState {

private:
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

public:
	float m_global_offset1_x = 0.0f;
	float m_global_offset1_y = 0.0f;

	float m_global_offset2_x = 0.0f;

};