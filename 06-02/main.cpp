#include <Novice.h>
#include <atomic>
#include <fstream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

const char kWindowTitle[] = "LE2A_16_ミハラ_ユウタ_PG3_06_02";

// マップデータ
std::vector<std::vector<int>> mapData;
std::atomic<bool> isLoaded(false);
std::mutex mapMutex;

// CSV読み込み関数
void LoadCSV(const char* filename) {
	std::ifstream file(filename);
	std::string line;
	std::vector<std::vector<int>> temp;

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string cell;
		std::vector<int> row;
		while (std::getline(ss, cell, ',')) {
			row.push_back(std::stoi(cell));
		}
		temp.push_back(row);
	}

	// 排他処理
	{
		std::lock_guard<std::mutex> lock(mapMutex);
		mapData = std::move(temp);
	}

	isLoaded = true;
}

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	Novice::Initialize(kWindowTitle, 1280, 720);

	char keys[256] = {0};
	char preKeys[256] = {0};

	std::thread loader(LoadCSV, "./map.csv");

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// 描画処理
		if (isLoaded) {
			int tileSize = 32;
			std::lock_guard<std::mutex> lock(mapMutex); // 読み取り時もロック
			for (int y = 0; y < (int)mapData.size(); y++) {
				for (int x = 0; x < (int)mapData[y].size(); x++) {
					int id = mapData[y][x];
					if (id == 0) {
						Novice::DrawBox(x * tileSize, y * tileSize, 32, 32, 0.0f, WHITE, kFillModeSolid);
					} else {
						Novice::DrawBox(x * tileSize, y * tileSize, 32, 32, 0.0f, BLACK, kFillModeSolid);
					}
				}
			}
		}

		Novice::EndFrame();

		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	loader.join();
	Novice::Finalize();
	return 0;
}