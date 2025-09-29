#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

int main() {
	// 学籍番号リスト
	std::vector<std::string> studentNumbers = {
	    "k024g1017@g.neec.ac.jp", "k024g0033@g.neec.ac.jp", "k024g0057@g.neec.ac.jp", "k024g0020@g.neec.ac.jp", "k024g0109@g.neec.ac.jp", "k024g1031@g.neec.ac.jp", "k024g0004@g.neec.ac.jp",
	    "k024g0027@g.neec.ac.jp", "k024g0058@g.neec.ac.jp", "k022g0113@g.neec.ac.jp", "k024g0007@g.neec.ac.jp", "k024g0083@g.neec.ac.jp", "k024g0110@g.neec.ac.jp", "k024g0066@g.neec.ac.jp",
	    "k023g0029@g.neec.ac.jp", "k024g1030@g.neec.ac.jp", "k024g0106@g.neec.ac.jp", "k024g0089@g.neec.ac.jp", "k024g0101@g.neec.ac.jp", "k024g0035@g.neec.ac.jp", "k024g1025@g.neec.ac.jp",
	    "k024g0059@g.neec.ac.jp", "k024g0006@g.neec.ac.jp", "k023g0122@g.neec.ac.jp", "k024g0028@g.neec.ac.jp", "k024g1024@g.neec.ac.jp", "k024g0108@g.neec.ac.jp", "k024g0061@g.neec.ac.jp",
	    "k024g0104@g.neec.ac.jp", "k024g0038@g.neec.ac.jp", "k024g0032@g.neec.ac.jp", "k024g0026@g.neec.ac.jp", "k024g0001@g.neec.ac.jp", "k024g0009@g.neec.ac.jp", "k024g0112@g.neec.ac.jp",
	    "k024g0011@g.neec.ac.jp", "k024g0085@g.neec.ac.jp", "k024g0111@g.neec.ac.jp", "k024g0045@g.neec.ac.jp", "k024g0103@g.neec.ac.jp", "k024g1002@g.neec.ac.jp", "k024g0078@g.neec.ac.jp",
	    "k024g0044@g.neec.ac.jp", "k024g0008@g.neec.ac.jp", "k024g0075@g.neec.ac.jp", "k024g0091@g.neec.ac.jp", "k024g0064@g.neec.ac.jp", "k024g0051@g.neec.ac.jp", "k024g0093@g.neec.ac.jp",
	    "k024g0024@g.neec.ac.jp"};

	// ラベル
	std::cout << "ソート前" << std::endl;

	// 学籍番号一覧表示
	for (auto student : studentNumbers) {
		std::cout << student << std::endl;
	}

	// 改行
	std::cout << "\n\n\n";

	// ソート
	std::sort(studentNumbers.begin(), studentNumbers.end());

	// ラベル
	std::cout << "ソート後" << std::endl;

	// ソート後学籍番号一覧表示
	for (auto student : studentNumbers) {
		std::cout << student << std::endl;
	}

	return 0;
}