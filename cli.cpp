#include <iostream>
#include <chrono>

#include "joaat.h"

const size_t testSize = 18;

struct TestSet {
	const char* input;
	const uint32_t hash;
};

TestSet testSet[testSize] = {
	{ "cc", 2193593802 },
	{ "41fb", 427943258 },
	{ "1f877c", 2476386184 },
	{ "c1ecfdfc", 4028977317 },
	{ "21f134ac57", 1500422415 },
	{ "c6f50bb74e29", 3596548375 },
	{ "119713cc83eeef", 3710655541 },
	{ "4a4f202484512522", 2183836142 },
	{ "1f66ab4185ed9b6375", 2987977443 },
	{ "eed7422227613b6f53c9", 381315942 },
	{ "eaeed5cdffd89dece455f1", 1295542225 },
	{ "5be43c90f22902e4fe8ed2d3", 2883495410 },
	{ "a746273228122f381c3b46e4f1", 2237030721 },
	{ "3c5871cd619c69a63b540eb5a625", 4188214433 },
	{ "fa22874bcc068879e8ef11a69f0722", 3821195912 },
	{ "52a608ab21ccdd8a4457a57ede782176", 3289897992 },
	{ "82e192e4043ddcd12ecf52969d0f807eed", 1004271045 },
	{ "75683dcb556140c522543bb6e9098b21a21e", 1930789292 },
};

void test() {
	auto start = std::chrono::high_resolution_clock::now();

	JOAAT joaat;
	int mismatches = 0;

	for (int i = 0; i < testSize; i++) {
		if (testSet[i].hash != joaat.hash(testSet[i].input)) {
			std::cout << "[WARNING] Missmatch while hashing with JOAAT" << std::endl;
			std::cout << "- INPUT: " << testSet[i].input << std::endl;
			std::cout << "- EXCEPTED: " << testSet[i].hash << std::endl;
			std::cout << "- GOT: " << joaat.hash(testSet[i].input) << std::endl << std::endl;
			mismatches++;
		}
	}

	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

	std::cout << "Runned a test with total " << mismatches << " missmatches with a test size of " << testSize << " after " << microseconds << " microseconds" << std::endl;
}

int main(int argc, char* argv[]) {
	JOAAT joaat;
	std::string input;

	int outputFormat = 0;

	std::cout << "JOAAT Hasher Console" << std::endl << std::endl
		<< "Options: " << std::endl
		<< " - exit > Exists the Console (1921928004)" << std::endl
		<< " - hex > Changes the Output Format to Hexadecimal (3544636510)" << std::endl
		<< " - decimal > Changes the Output Format to Decimal (152940477)" << std::endl
		<< " - test > Runs a test if hasher is correct (1064684737)" << std::endl
		<< " - clear > Clears the Console (916995460)" << std::endl << std::endl;

	while (true) {
		std::cout << "$ ";
		std::getline(std::cin, input);

		int command = 0;
		if (strcmp(input.c_str(), "exit") == 0) command = 1;
		if (strcmp(input.c_str(), "hex") == 0) command = 2;
		if (strcmp(input.c_str(), "decimal") == 0) command = 3;
		if (strcmp(input.c_str(), "clear") == 0) command = 4;
		if (strcmp(input.c_str(), "test") == 0) command = 5;

		switch (command) {
			case 1:
				exit(0);
				break;
			case 2:
				outputFormat = 1;
				break;
			case 3:
				outputFormat = 0;
				break;
			case 4:
				system("cls");
				break;
			case 5:
				test();
				break;
			default:
				if (outputFormat == 0) {
					std::cout << joaat.hash(input) << std::endl;
				}
				else {
					std::cout << std::hex << std::showbase << joaat.hash(input) << std::endl;
				}
		}
	}

	return EXIT_SUCCESS;
}
