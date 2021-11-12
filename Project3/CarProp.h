#pragma once
#include <math.h>

enum class Direction {
	NORTH, EAST, SOUTH, WEST, NOWHERE, WEST_E, EAST_W
};

enum class Color {
	RED, BLUE, YELLOW
};
enum class Ampel_Farbe {
	RED, YELLOW, GREEN, REDYELLOW
};
enum class Ampel_Seite {
	OBEN, RECHTS, UNTEN, LINKS
};