# include "Game.hpp"

Game::Game(const InitData& init)
	: IScene{ init }
{
}

void Game::update()
{
	// ノートボタンを描く
	for (int i = 0; auto& note : notes) {
		++i;
		if (SimpleGUI::ButtonAt(note, Vec2{ i*90, 500 })) {
			slotNotes.push_back(note);
		}
			
	}

	for (auto& slot : slots) {
		slot.draw();
	}

	for (int i = 0;  auto& slotNote : slotNotes) {
		++i;
		FontAsset(U"Bold")(slotNote).draw(Arg::center = Vec2{ Scene::Width() / 4 * i, 300 }, Palette::Black);
		//font(slotNote).draw(slots[i-1], Palette::Black);
	}
}

void Game::draw() const
{
	Scene::SetBackground(ColorF{ 0.2 });

	
	// スコアを描く
	FontAsset(U"Bold")(100).draw(24, Vec2{ 400, 16 });
}
