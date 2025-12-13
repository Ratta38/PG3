#include <iostream>
#include <list>

/// <summary>
/// 駅のリストを出力する関数
/// </summary>
/// <param name="stations">駅名のリスト</param>
void PrintStations(const char* number, const std::list<const char*>& stations) {
	// 年数
	std::cout << number << "\n";

	for (auto station : stations) {
		std::cout << station << "\n";
	}

	// 改行
	std::cout << "\n";
}

/// <summary>
/// 指定した駅の前に新しい駅を追加
/// </summary>
/// <param name="stations">駅名のリスト</param>
/// <param name="target">挿入する位置</param>
/// <param name="newStation">追加する駅名</param>
void InsertBefore(std::list<const char*>& stations, const char* target, const char* newStation) {
	for (auto itr = stations.begin(); itr != stations.end(); ++itr) {
		if (std::strcmp(*itr, target) == 0) {
			stations.insert(itr, newStation); // 西日暮里の追加
			return;
		}
	}
}

int main() {
	// 山手線駅名リスト
	std::list<const char*> stations = { "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu", "Gotanda", "Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho" };

	// 1970年
	PrintStations("1920年", stations);

	// 2019年
	InsertBefore(stations, "Tabata", "Nishi-Nippori");
	PrintStations("2019年", stations);

	// 2022年
	InsertBefore(stations, "Tamachi", "Takanawa Gateway");
	PrintStations("2022年", stations);

	return 0;
}