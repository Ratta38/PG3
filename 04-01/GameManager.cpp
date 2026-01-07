#include "GameManager.h"
#include "InputManager.h"
#include "Novice.h"

const char kWindowTitle[] = "LE2A_16_ミハラ_ユウタ_PG3_04_01";

GameManager::GameManager() {
	// 各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<GameScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	// 初期シーンの設定
	currentSceneNo_ = TITLE;

	// 前のシーンの設定
	prevSceneNo_ = CLEAR;

	// インプットマネージャー
	input_ = std::make_unique<InputManager>();

	// 現在のシーンの初期化
	sceneArr_[currentSceneNo_]->Initialize(input_.get());
}

GameManager::~GameManager() {}

int GameManager::Run() {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		input_->Update();

		// シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize(input_.get());
		}

		// 更新処理
		sceneArr_[currentSceneNo_]->Update();

		// 描画処理
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (input_->IsTrigger(DIK_ESCAPE)) {
			break;
		}
	}

	return 0;
}