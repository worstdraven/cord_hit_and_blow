# pragma once
# include "Common.hpp"

// ゲームシーン
class Game : public App::Scene
{
public:

	Game(const InitData& init);

	void update() override;

	void draw() const override;

private:
	Font font{ 12, Typeface::CJK_Regular_JP };

	Array<String> notes{
		U"C",
		U"D",
		U"E",
		U"F",
		U"G",
		U"H",
		U"A",
		U"B",
	};

	Array<Rect> slots{
		Rect{ Arg::center(Scene::Width() / 4, 300), 80, 80},
		Rect{ Arg::center(Scene::Width() / 4 * 2, 300), 80, 80},
		Rect{ Arg::center(Scene::Width() / 4 * 3, 300), 80, 80},
	};

	Array<String> slotNotes;

	// ブロックを壊したときの効果音
	Audio m_brickSound{ GMInstrument::Woodblock, PianoKey::C5, 0.2s, 0.1s };
};
