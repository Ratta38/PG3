#include "InputHandler.h"
#include "Player.h"
#include <Novice.h>

const char kWindowTitle[] = "LE2A_16_ミハラ_ユウタ_PG3_05_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	ICommand* iCommand = nullptr;
	std::unique_ptr<InputHandler> inputHandler = std::make_unique<InputHandler>();

	// プレイヤー生成・初期化
	std::unique_ptr<Player> player = std::make_unique<Player>();
	player->Initialize();

	inputHandler->AssignMoveRightCommand2PressKeyD();
	inputHandler->AssignMoveLeftCommand2PressKeyA();

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		// get input
		iCommand = inputHandler->HandleInput();

		// set command
		if (iCommand) {
			iCommand->Exec(*player);
		}

		// プレイヤー更新
		player->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// プレイヤー描画
		player->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
