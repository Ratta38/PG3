#include "SUV.h"
#include "Sedan.h"
#include <memory>

int main() {
	// インスタンス生成
	std::unique_ptr<SUV> suv = std::make_unique<SUV>();
	std::unique_ptr<Sedan> sedan = std::make_unique<Sedan>();

	// 初期化
	suv->Initialize("SUV");
	sedan->Initialize("Sedan");

	// 名前の出力
	suv->PrintName();
	sedan->PrintName();

	return 0;
}