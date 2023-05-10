//border defines
#define BORDER_TOP_BOTTOM 0xCD
#define BORDER_LEFT_RIGHT 0xBA
#define BORDER_UPPER_LEFT 0xC9
#define BORDER_UPPER_RIGHT 0xBB
#define BORDER_LOWER_LEFT 0xC8
#define BORDER_LOWER_RIGHT 0xBC
#define BORDER_HORIZONTAL 0xCD
#define BORDER_VERTICAL 0xBA
#define WIFI_ICON 0x7F //95+32
#define HORIZONTAL_LINE 0xB3
#define VERTICAL_LINE 0xC4

class font
{
private:
	unsigned char myFont16_[96][32] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // <space> 0
	{0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00},  // ! 1
	{0x03,0x30,0x03,0x30,0x03,0x30,0x03,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // " 2
	{0x00,0x00,0x00,0x00,0x0C,0x30,0x0C,0x30,0x3F,0xFC,0x3F,0xFC,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x3F,0xFC,0x3F,0xFC,0x0C,0x30,0x0C,0x30,0x00,0x00,0x00,0x00},  // # 3
	{0x03,0x00,0x03,0x00,0x3F,0xF0,0x3F,0xF0,0x33,0x00,0x33,0x00,0x3F,0xF0,0x3F,0xF0,0x03,0x30,0x03,0x30,0x3F,0xF0,0x3F,0xF0,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // $ 4
	{0x00,0x00,0x00,0x00,0x3C,0x0C,0x3C,0x0C,0x3C,0x30,0x3C,0x30,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x0C,0x3C,0x0C,0x3C,0x30,0x3C,0x30,0x3C,0x00,0x00,0x00,0x00},  // % 5
	{0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x0C,0xC0,0x0C,0xC0,0x03,0x00,0x03,0x00,0x0C,0xCC,0x0C,0xCC,0x30,0x30,0x30,0x30,0x0F,0xCC,0x0F,0xCC,0x00,0x00,0x00,0x00},  // & 6
	{0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // ' 7 
	{0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00},  // ( 8
	{0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // ) 9
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0xC0,0x0C,0xC0,0x03,0x00,0x03,0x00,0x3F,0xF0,0x3F,0xF0,0x03,0x00,0x03,0x00,0x0C,0xC0,0x0C,0xC0,0x00,0x00,0x00,0x00},  // * 10
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x3F,0xF0,0x3F,0xF0,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // + 11
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00},  // , 12
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // - 13
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xC0,0x00,0x00,0x00,0x00},  // . 14
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x0C,0x00,0x0C,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00},  // / 15

	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0xF0,0xC0,0xF0,0xC3,0x30,0xC3,0x30,0xCC,0x30,0xCC,0x30,0xF0,0x30,0xF0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // 0 16
	{0x00,0x00,0x00,0x00,0x3C,0x00,0x3C,0x00,0xCC,0x00,0xCC,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0xFF,0xC0,0xFF,0xC0,0x00,0x00,0x00,0x00},  // 1 17
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0x00,0x30,0x00,0x30,0x3F,0xC0,0x3F,0xC0,0xC0,0x00,0xC0,0x00,0xFF,0xF0,0xFF,0xF0,0x00,0x00,0x00,0x00},  // 2 18
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0x03,0xC0,0x03,0xC0,0x00,0x30,0x00,0x30,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // 3 19
	{0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x0F,0x00,0x0F,0x00,0x33,0x00,0x33,0x00,0xC3,0x00,0xC3,0x00,0xFF,0xF0,0xFF,0xF0,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // 4 20
	{0x00,0x00,0x00,0x00,0xFF,0xF0,0xFF,0xF0,0xC0,0x00,0xC0,0x00,0xFF,0xC0,0xFF,0xC0,0x00,0x30,0x00,0x30,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // 5 21
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x00,0xC0,0x00,0xFF,0xC0,0xFF,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // 6 22
	{0x00,0x00,0x00,0x00,0xFF,0xF0,0xFF,0xF0,0x00,0x30,0x00,0x30,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x00,0x00,0x00,0x00},  // 7 23
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // 8 24
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x3F,0xF0,0x3F,0xF0,0x00,0x30,0x00,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // 9 25
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00},  // : 26
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x0C,0x00,0x0C,0x00},  // ; 27
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x0C,0x00,0x0C,0x00,0x03,0x00,0x03,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00},  // < 28
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x00,0x00,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},  // = 29
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x0C,0x00,0x03,0x00,0x03,0x00,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x0C,0x00,0x0C,0x00,0x00,0x00,0x00,0x00},  // > 30
	{0x00,0x00,0x00,0x00,0x0F,0xF0,0x0F,0xF0,0x30,0x0C,0x30,0x0C,0x00,0x30,0x00,0x30,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00},  // ? 31

	{0x00,0x00,0x00,0x00,0x0F,0xF0,0x0F,0xF0,0x30,0xCC,0x30,0xCC,0x33,0x3C,0x33,0x3C,0x33,0xFC,0x33,0xFC,0x30,0x00,0x30,0x00,0x0F,0xF0,0x0F,0xF0,0x00,0x00,0x00,0x00},  // @ 32
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xFF,0xF0,0xFF,0xF0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x00,0x00,0x00,0x00},  // A 33
	{0x00,0x00,0x00,0x00,0xFF,0xC0,0xFF,0xC0,0xC0,0x30,0xC0,0x30,0xFF,0xC0,0xFF,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xFF,0xC0,0xFF,0xC0,0x00,0x00,0x00,0x00},  // B 34
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // C 35
	{0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0xC0,0xC0,0xC0,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0x00},  // D 36
	{0x00,0x00,0x00,0x00,0xFF,0xF0,0xFF,0xF0,0xC0,0x00,0xC0,0x00,0xFF,0xC0,0xFF,0xC0,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xFF,0xF0,0xFF,0xF0,0x00,0x00,0x00,0x00},  // E 37
	{0x00,0x00,0x00,0x00,0xFF,0xF0,0xFF,0xF0,0xC0,0x00,0xC0,0x00,0xFF,0xC0,0xFF,0xC0,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00},  // F 38 
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x00,0xC0,0x00,0xC3,0xF0,0xC3,0xF0,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // G 39
	{0x00,0x00,0x00,0x00,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xFF,0xF0,0xFF,0xF0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x00,0x00,0x00,0x00},  // H 40
	{0x00,0x00,0x00,0x00,0x3F,0xF0,0x3F,0xF0,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x00,0x00,0x00},  // I
	{0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // J
	{0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC3,0x00,0xC3,0x00,0xFC,0x00,0xFC,0x00,0xC3,0x00,0xC3,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0x30,0xC0,0x30,0x00,0x00,0x00,0x00},  // K
	{0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xFF,0xF0,0xFF,0xF0,0x00,0x00,0x00,0x00},  // L
	{0x00,0x00,0x00,0x00,0xC0,0x30,0xC0,0x30,0xF0,0xF0,0xF0,0xF0,0xCF,0x30,0xCF,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x00,0x00,0x00,0x00},  // M
	{0x00,0x00,0x00,0x00,0xC0,0x30,0xC0,0x30,0xF0,0x30,0xF0,0x30,0xCC,0x30,0xCC,0x30,0xC3,0x30,0xC3,0x30,0xC0,0xF0,0xC0,0xF0,0xC0,0x30,0xC0,0x30,0x00,0x00,0x00,0x00},  // N
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // O

	{0x00,0x00,0x00,0x00,0xFF,0xC0,0xFF,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xFF,0xC0,0xFF,0xC0,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00},  // P
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xCC,0x30,0xCC,0x30,0xC3,0x30,0xC3,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // Q
	{0x00,0x00,0x00,0x00,0xFF,0xC0,0xFF,0xC0,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xFF,0xC0,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x30,0xC0,0x30,0x00,0x00,0x00,0x00},  // R
	{0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0xC0,0x00,0xC0,0x00,0x3F,0xC0,0x3F,0xC0,0x00,0x30,0x00,0x30,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // S
	{0x00,0x00,0x00,0x00,0xFF,0xFC,0xFF,0xFC,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // T
	{0x00,0x00,0x00,0x00,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // U
	{0x00,0x00,0x00,0x00,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0x30,0xC0,0x30,0xC0,0x0F,0x00,0x0F,0x00,0x00,0x00,0x00,0x00},  // V
	{0x00,0x00,0x00,0x00,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xCF,0x30,0xCF,0x30,0x30,0xC0,0x30,0xC0,0x00,0x00,0x00,0x00},  // W
	{0x00,0x00,0x00,0x00,0xC0,0x30,0xC0,0x30,0x30,0xC0,0x30,0xC0,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x30,0xC0,0x30,0xC0,0xC0,0x30,0xC0,0x30,0x00,0x00,0x00,0x00},  // X
	{0x00,0x00,0x00,0x00,0xC0,0x0C,0xC0,0x0C,0x30,0x30,0x30,0x30,0x0C,0xC0,0x0C,0xC0,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // Y
	{0x00,0x00,0x00,0x00,0xFF,0xF0,0xFF,0xF0,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x0C,0x00,0x0C,0x00,0x30,0x00,0x30,0x00,0xFF,0xF0,0xFF,0xF0,0x00,0x00,0x00,0x00},  // Z
	{0x00,0x00,0x00,0x00,0x0F,0xC0,0x0F,0xC0,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0F,0xC0,0x0F,0xC0,0x00,0x00,0x00,0x00},  // [
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x0C,0x00,0x0C,0x00,0x03,0x00,0x03,0x00,0x00,0xC0,0x00,0xC0,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00},  // <backslash>
	{0x00,0x00,0x00,0x00,0x0F,0xC0,0x0F,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x0F,0xC0,0x0F,0xC0,0x00,0x00,0x00,0x00},  // ]
	{0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x0F,0xC0,0x0F,0xC0,0x33,0x30,0x33,0x30,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // ^
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0xFF,0xFC},  // _

	{0x0F,0xF0,0x0F,0xF0,0x30,0x0C,0x30,0x0C,0xC3,0xC3,0xC3,0xC3,0xCC,0x03,0xCC,0x03,0xCC,0x03,0xCC,0x03,0xC3,0xC3,0xC3,0xC3,0x30,0x0C,0x30,0x0C,0x0F,0xF0,0x0F,0xF0},  // `
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x0F,0xC0,0x00,0x30,0x00,0x30,0x0F,0xF0,0x0F,0xF0,0x30,0x30,0x30,0x30,0x0F,0xF0,0x0F,0xF0,0x00,0x00,0x00,0x00},  // a
	{0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x3F,0xC0,0x3F,0xC0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // b
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xF0,0x03,0xF0,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x03,0xF0,0x03,0xF0,0x00,0x00,0x00,0x00},  // c
	{0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x0F,0xF0,0x0F,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x0F,0xF0,0x0F,0xF0,0x00,0x00,0x00,0x00},  // d
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x0F,0xC0,0x30,0x30,0x30,0x30,0x3F,0xC0,0x3F,0xC0,0x30,0x00,0x30,0x00,0x0F,0xF0,0x0F,0xF0,0x00,0x00,0x00,0x00},  // e
	{0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0xF0,0x03,0x00,0x03,0x00,0x03,0xC0,0x03,0xC0,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // f
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFC,0x0F,0xFC,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x0F,0xFC,0x0F,0xFC,0x00,0x0C,0x00,0x0C,0x0F,0xF0,0x0F,0xF0},  // g
	{0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x3F,0xC0,0x3F,0xC0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00},  // h
	{0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00,0x03,0xC0,0x03,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x03,0xF0,0x03,0xF0,0x00,0x00,0x00,0x00},  // i
	{0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x0C,0x30,0x0C,0x30,0x03,0xC0,0x03,0xC0},  // j
	{0x00,0x00,0x00,0x00,0x18,0x00,0x18,0x00,0x19,0x80,0x19,0x80,0x1E,0x00,0x1E,0x00,0x1E,0x00,0x1E,0x00,0x19,0x80,0x19,0x80,0x18,0x60,0x18,0x60,0x00,0x00,0x00,0x00},  // k
	{0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0xF0,0x00,0xF0,0x00,0x00,0x00,0x00},  // l
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0xC0,0x3C,0xC0,0x33,0x30,0x33,0x30,0x33,0x30,0x33,0x30,0x33,0x30,0x33,0x30,0x33,0x30,0x33,0x30,0x00,0x00,0x00,0x00},  // m
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00},  // n
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x0F,0xC0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x0F,0xC0,0x0F,0xC0,0x00,0x00,0x00,0x00},  // o

	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3F,0xC0,0x3F,0xC0,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00},  // p
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x0F,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x0F,0xF0,0x0F,0xF0,0x00,0x30,0x00,0x30,0x00,0x3C,0x00,0x3C},  // q
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xF0,0x03,0xF0,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x00,0x00,0x00,0x00},  // r
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x0F,0xC0,0x30,0x00,0x30,0x00,0x0F,0xC0,0x0F,0xC0,0x00,0x30,0x00,0x30,0x3F,0xC0,0x3F,0xC0,0x00,0x00,0x00,0x00},  // s
	{0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x0F,0xC0,0x0F,0xC0,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0xF0,0x00,0xF0,0x00,0x00,0x00,0x00},  // t
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x0F,0xC0,0x0F,0xC0,0x00,0x00,0x00,0x00},  // u
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,0x0C,0xC0,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // v
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0x33,0x30,0x33,0x30,0x33,0x30,0x33,0x30,0x33,0x30,0x33,0x30,0x0C,0xC0,0x0C,0xC0,0x00,0x00,0x00,0x00},  // w
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0x0C,0xC0,0x0C,0xC0,0x03,0x00,0x03,0x00,0x0C,0xC0,0x0C,0xC0,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00},  // x
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x0F,0xF0,0x0F,0xF0,0x00,0x30,0x00,0x30,0x0F,0xC0,0x0F,0xC0},  // y
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0xC0,0x00,0xC0,0x03,0x00,0x03,0x00,0x0C,0x00,0x0C,0x00,0x3F,0xF0,0x3F,0xF0,0x00,0x00,0x00,0x00},  // z
	{0x00,0x00,0x00,0x00,0x03,0xF0,0x03,0xF0,0x03,0x00,0x03,0x00,0x3C,0x00,0x3C,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0xF0,0x03,0xF0,0x00,0x00,0x00,0x00},  // {
	{0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00},  // |
	{0x00,0x00,0x00,0x00,0x3F,0x00,0x3F,0x00,0x03,0x00,0x03,0x00,0x00,0xF0,0x00,0xF0,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x3F,0x00,0x3F,0x00,0x00,0x00,0x00,0x00},  // }
	{0x00,0x00,0x00,0x00,0x03,0x30,0x03,0x30,0x0C,0xC0,0x0C,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// ~
	{0x0F,0xF0,0x1F,0xF8,0x30,0x0C,0x60,0x06,0xC7,0xE3,0x8F,0xF1,0x18,0x18,0x30,0x0C,0x23,0xC4,0x07,0xE0,0x0C,0x30,0x08,0x10,0x00,0x00,0x01,0x80,0x03,0xC0,0x01,0x80}   // WIFI
};
	unsigned char myFont_[256][8] = 
{
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},	// Char 000 (.)}
    {0x7E, 0x81, 0xA5, 0x81, 0xBD, 0x99, 0x81, 0x7E},	// Char 001 (.)
	{0x7E, 0xFF, 0xDB, 0xFF, 0xC3, 0xE7, 0xFF, 0x7E},	// Char 002 (.)
	{0x6C, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x10, 0x00},	// Char 003 (.)
	{0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x10, 0x00},	// Char 004 (.)
	{0x38, 0x7C, 0x38, 0xFE, 0xFE, 0x7C, 0x38, 0x7C},	// Char 005 (.)
	{0x10, 0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x7C},	// Char 006 (.)
	{0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00},	// Char 007 (.)
	{0xFF, 0xFF, 0xE7, 0xC3, 0xC3, 0xE7, 0xFF, 0xFF},	// Char 008 (.)
	{0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00},	// Char 009 (.)
	{0xFF, 0xC3, 0x99, 0xBD, 0xBD, 0x99, 0xC3, 0xFF},	// Char 010 (.)
	{0x0F, 0x07, 0x0F, 0x7D, 0xCC, 0xCC, 0xCC, 0x78},	// Char 011 (.)
	{0x3C, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x7E, 0x18},	// Char 012 (.)
	{0x3F, 0x33, 0x3F, 0x30, 0x30, 0x70, 0xF0, 0xE0},	// Char 013 (.)
	{0x7F, 0x63, 0x7F, 0x63, 0x63, 0x67, 0xE6, 0xC0},	// Char 014 (.)
	{0x99, 0x5A, 0x3C, 0xE7, 0xE7, 0x3C, 0x5A, 0x99},	// Char 015 (.)
	{0x80, 0xE0, 0xF8, 0xFE, 0xF8, 0xE0, 0x80, 0x00},	// Char 016 (.)
	{0x02, 0x0E, 0x3E, 0xFE, 0x3E, 0x0E, 0x02, 0x00},	// Char 017 (.)
	{0x18, 0x3C, 0x7E, 0x18, 0x18, 0x7E, 0x3C, 0x18},	// Char 018 (.)
	{0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x00},	// Char 019 (.)
	{0x7F, 0xDB, 0xDB, 0x7B, 0x1B, 0x1B, 0x1B, 0x00},	// Char 020 (.)
	{0x3C, 0x66, 0x38, 0x6C, 0x6C, 0x38, 0xCC, 0x78},	// Char 021 (.)
	{0x00, 0x00, 0x00, 0x00, 0x7E, 0x7E, 0x7E, 0x00},	// Char 022 (.)
	{0x18, 0x3C, 0x7E, 0x18, 0x7E, 0x3C, 0x18, 0xFF},	// Char 023 (.)
	{0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00},	// Char 024 (.)
	{0x18, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00},	// Char 025 (.)
	{0x00, 0x18, 0x0C, 0xFE, 0x0C, 0x18, 0x00, 0x00},	// Char 026 (.)
	{0x00, 0x30, 0x60, 0xFE, 0x60, 0x30, 0x00, 0x00},	// Char 027 (.)
	{0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xFE, 0x00, 0x00},	// Char 028 (.)
	{0x00, 0x24, 0x66, 0xFF, 0x66, 0x24, 0x00, 0x00},	// Char 029 (.)
	{0x00, 0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x00, 0x00},	// Char 030 (.)
	{0x00, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x00},	// Char 031 (.)
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},	// Char 032 ( )
	{0x30, 0x78, 0x78, 0x30, 0x30, 0x00, 0x30, 0x00},	// Char 033 (!)
	{0x6C, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00},	// Char 034 (")
	{0x6C, 0x6C, 0xFE, 0x6C, 0xFE, 0x6C, 0x6C, 0x00},	// Char 035 (#)
	{0x30, 0x7C, 0xC0, 0x78, 0x0C, 0xF8, 0x30, 0x00},	// Char 036 ($)
	{0x00, 0xC6, 0xCC, 0x18, 0x30, 0x66, 0xC6, 0x00},	// Char 037 (%)
	{0x38, 0x6C, 0x38, 0x76, 0xDC, 0xCC, 0x76, 0x00},	// Char 038 (&)
	{0x60, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00},	// Char 039 (')
	{0x18, 0x30, 0x60, 0x60, 0x60, 0x30, 0x18, 0x00},	// Char 040 (()
	{0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00},	// Char 041 ())
	{0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00},	// Char 042 (*)
	{0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x00, 0x00},	// Char 043 (+)
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60},	// Char 044 (,)
	{0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00},	// Char 045 (-)
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00},	// Char 046 (.)
	{0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x80, 0x00},	// Char 047 (/)
	{0x7C, 0xC6, 0xCE, 0xDE, 0xF6, 0xE6, 0x7C, 0x00},	// Char 048 (0)
	{0x30, 0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00},	// Char 049 (1)
	{0x78, 0xCC, 0x0C, 0x38, 0x60, 0xC0, 0xFC, 0x00},	// Char 050 (2)
	{0x78, 0xCC, 0x0C, 0x38, 0x0C, 0xCC, 0x78, 0x00},	// Char 051 (3)
	{0x1C, 0x3C, 0x6C, 0xCC, 0xFE, 0x0C, 0x0C, 0x00},	// Char 052 (4)
	{0xFC, 0xC0, 0xF8, 0x0C, 0x0C, 0xCC, 0x78, 0x00},	// Char 053 (5)
	{0x38, 0x60, 0xC0, 0xF8, 0xCC, 0xCC, 0x78, 0x00},	// Char 054 (6)
	{0xFC, 0x0C, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00},	// Char 055 (7)
	{0x78, 0xCC, 0xCC, 0x78, 0xCC, 0xCC, 0x78, 0x00},	// Char 056 (8)
	{0x78, 0xCC, 0xCC, 0x7C, 0x0C, 0x18, 0x70, 0x00},	// Char 057 (9) 
	{0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00},	// Char 058 (:)
	{0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x60},	// Char 059 (;)
	{0x18, 0x30, 0x60, 0xC0, 0x60, 0x30, 0x18, 0x00},	// Char 060 (<)
	{0x00, 0x00, 0xFC, 0x00, 0x00, 0xFC, 0x00, 0x00},	// Char 061 (=)
	{0x60, 0x30, 0x18, 0x0C, 0x18, 0x30, 0x60, 0x00},	// Char 062 (>)
	{0x78, 0xCC, 0x0C, 0x18, 0x30, 0x00, 0x30, 0x00},	// Char 063 (?)
	{0x7C, 0xC6, 0xDE, 0xDE, 0xDE, 0xC0, 0x78, 0x00},	// Char 064 (@)
	{0x18, 0x3C, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x00},	// Char 065 (A)
	{0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x7C, 0x00},	// Char 066 (B)
	{0x3C, 0x66, 0xC0, 0xC0, 0xC0, 0x66, 0x3C, 0x00},	// Char 067 (C)
	{0x78, 0x6C, 0x66, 0x66, 0x66, 0x6C, 0x78, 0x00},	// Char 068 (D)
	{0x7E, 0x60, 0x60, 0x78, 0x60, 0x60, 0x7E, 0x00},	// Char 069 (E)
	{0x7E, 0x60, 0x60, 0x78, 0x60, 0x60, 0x60, 0x00},	// Char 070 (F)
	{0x3C, 0x66, 0xC0, 0xC0, 0xCE, 0x66, 0x3E, 0x00},	// Char 071 (G)
	{0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00},	// Char 072 (H)
	{0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00},	// Char 073 (I)
	{0x06, 0x06, 0x06, 0x06, 0x66, 0x66, 0x3C, 0x00},	// Char 074 (J)
	{0x66, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0x66, 0x00},	// Char 075 (K)
	{0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x00},	// Char 076 (L)
	{0xC6, 0xEE, 0xFE, 0xFE, 0xD6, 0xC6, 0xC6, 0x00},	// Char 077 (M)
	{0xC6, 0xE6, 0xF6, 0xDE, 0xCE, 0xC6, 0xC6, 0x00},	// Char 078 (N)
	{0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00},	// Char 079 (O)
	{0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60, 0x60, 0x00},	// Char 080 (P)
	{0x3C, 0x66, 0x66, 0x66, 0x6E, 0x3C, 0x0E, 0x00},	// Char 081 (Q)
	{0x7C, 0x66, 0x66, 0x7C, 0x6C, 0x66, 0x66, 0x00},	// Char 082 (R)
	{0x3C, 0x66, 0x70, 0x38, 0x0E, 0x66, 0x3C, 0x00},	// Char 083 (S)
	{0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00},	// Char 084 (T)
	{0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3E, 0x00},	// Char 085 (U)
	{0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x00},	// Char 086 (V)
	{0xC6, 0xC6, 0xC6, 0xD6, 0xFE, 0xEE, 0xC6, 0x00},	// Char 087 (W)
	{0x66, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x66, 0x00},	// Char 088 (X)
	{0x66, 0x66, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x00},	// Char 089 (Y)
	{0xFE, 0x06, 0x0C, 0x18, 0x30, 0x60, 0xFE, 0x00},	// Char 090 (Z)
	{0x78, 0x60, 0x60, 0x60, 0x60, 0x60, 0x78, 0x00},	// Char 091 ([)
	{0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x02, 0x00},	// Char 092 (\)
	{0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00},	// Char 093 (])
	{0x10, 0x38, 0x6C, 0xC6, 0x00, 0x00, 0x00, 0x00},	// Char 094 (^)
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},	// Char 095 (_)
	{0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00},	// Char 096 (`)
	{0x00, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x3A, 0x00},	// Char 097 (a)
	{0x60, 0x60, 0x60, 0x7C, 0x66, 0x66, 0x5C, 0x00},	// Char 098 (b)
	{0x00, 0x00, 0x3C, 0x66, 0x60, 0x66, 0x3C, 0x00},	// Char 099 (c)
	{0x06, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3A, 0x00},	// Char 100 (d)
	{0x00, 0x00, 0x3C, 0x66, 0x7E, 0x60, 0x3C, 0x00},	// Char 101 (e)
	{0x1C, 0x36, 0x30, 0x78, 0x30, 0x30, 0x30, 0x00},	// Char 102 (f)
	{0x00, 0x00, 0x3A, 0x66, 0x66, 0x3E, 0x06, 0x3C},	// Char 103 (g)
	{0x60, 0x60, 0x6C, 0x76, 0x66, 0x66, 0x66, 0x00},	// Char 104 (h)
	{0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00},	// Char 105 (i)
	{0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78},	// Char 106 (j)
	{0x60, 0x60, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0x00},	// Char 107 (k)
	{0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00},	// Char 108 (l)
	{0x00, 0x00, 0xC6, 0xEE, 0xFE, 0xD6, 0xC6, 0x00},	// Char 109 (m)
	{0x00, 0x00, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x00},	// Char 110 (n)
	{0x00, 0x00, 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x00},	// Char 111 (o)
	{0x00, 0x00, 0x5C, 0x66, 0x66, 0x7C, 0x60, 0x60},	// Char 112 (p)
	{0x00, 0x00, 0x3A, 0x66, 0x66, 0x3E, 0x06, 0x06},	// Char 113 (q)
	{0x00, 0x00, 0x5C, 0x76, 0x60, 0x60, 0x60, 0x00},	// Char 114 (r)
	{0x00, 0x00, 0x3E, 0x60, 0x3C, 0x06, 0x7C, 0x00},	// Char 115 (s)
	{0x30, 0x30, 0x7C, 0x30, 0x30, 0x34, 0x18, 0x00},	// Char 116 (t)
	{0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3A, 0x00},	// Char 117 (u)
	{0x00, 0x00, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x00},	// Char 118 (v)
	{0x00, 0x00, 0xC6, 0xD6, 0xFE, 0xFE, 0x6C, 0x00},	// Char 119 (w)
	{0x00, 0x00, 0xC6, 0x6C, 0x38, 0x6C, 0xC6, 0x00},	// Char 120 (x)
	{0x00, 0x00, 0x66, 0x66, 0x66, 0x3E, 0x06, 0x3C},	// Char 121 (y)
	{0x00, 0x00, 0x7E, 0x0C, 0x18, 0x30, 0x7E, 0x00},	// Char 122 (z)
	{0x1C, 0x30, 0x30, 0xE0, 0x30, 0x30, 0x1C, 0x00},	// Char 123 ({)
	{0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00},	// Char 124 (|)
	{0xE0, 0x30, 0x30, 0x1C, 0x30, 0x30, 0xE0, 0x00},	// Char 125 (})
	{0x76, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},	// Char 126 (~)
	{0x00, 0x10, 0x38, 0x6C, 0xC6, 0xC6, 0xFE, 0x00},	// Char 127 (.)
	{0x0E, 0x1E, 0x36, 0x66, 0x7E, 0x66, 0x66, 0x00},	// Char 128 (.)
	{0x7C, 0x60, 0x60, 0x7C, 0x66, 0x66, 0x7C, 0x00},	// Char 129 (.)
	{0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x7C, 0x00},	// Char 130 (.)
	{0x7E, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x00},	// Char 131 (.)
	{0x1C, 0x3C, 0x6C, 0x6C, 0x6C, 0x6C, 0xFE, 0xC6},	// Char 132 (.)
	{0x7E, 0x60, 0x60, 0x7C, 0x60, 0x60, 0x7E, 0x00},	// Char 133 (.)
	{0xDB, 0xDB, 0x7E, 0x3C, 0x7E, 0xDB, 0xDB, 0x00},	// Char 134 (.)
	{0x3C, 0x66, 0x06, 0x1C, 0x06, 0x66, 0x3C, 0x00},	// Char 135 (.)
	{0x66, 0x66, 0x6E, 0x7E, 0x76, 0x66, 0x66, 0x00},	// Char 136 (.)
	{0x3C, 0x66, 0x6E, 0x7E, 0x76, 0x66, 0x66, 0x00},	// Char 137 (.)
	{0x66, 0x6C, 0x78, 0x70, 0x78, 0x6C, 0x66, 0x00},	// Char 138 (.)
	{0x0E, 0x1E, 0x36, 0x66, 0x66, 0x66, 0x66, 0x00},	// Char 139 (.)
	{0xC6, 0xEE, 0xFE, 0xFE, 0xD6, 0xD6, 0xC6, 0x00},	// Char 140 (.)
	{0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00},	// Char 141 (.)
	{0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00},	// Char 142 (.)
	{0x7E, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00},	// Char 143 (.)
	{0x7C, 0x66, 0x66, 0x66, 0x7C, 0x60, 0x60, 0x00},	// Char 144 (.)
	{0x3C, 0x66, 0x60, 0x60, 0x60, 0x66, 0x3C, 0x00},	// Char 145 (.)
	{0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00},	// Char 146 (.)
	{0x66, 0x66, 0x66, 0x3E, 0x06, 0x66, 0x3C, 0x00},	// Char 147 (.)
	{0x7E, 0xDB, 0xDB, 0xDB, 0x7E, 0x18, 0x18, 0x00},	// Char 148 (.)
	{0x66, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x66, 0x00},	// Char 149 (.)
	{0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7F, 0x03},	// Char 150 (.)
	{0x66, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x06, 0x00},	// Char 151 (.)
	{0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xFF, 0x00},	// Char 152 (.)
	{0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xFF, 0x03},	// Char 153 (.)
	{0xE0, 0x60, 0x60, 0x7C, 0x66, 0x66, 0x7C, 0x00},	// Char 154 (.)
	{0xC6, 0xC6, 0xC6, 0xF6, 0xDE, 0xDE, 0xF6, 0x00},	// Char 155 (.)
	{0x60, 0x60, 0x60, 0x7C, 0x66, 0x66, 0x7C, 0x00},	// Char 156 (.)
	{0x78, 0x8C, 0x06, 0x3E, 0x06, 0x8C, 0x78, 0x00},	// Char 157 (.)
	{0xCE, 0xDB, 0xDB, 0xFB, 0xDB, 0xDB, 0xCE, 0x00},	// Char 158 (.)
	{0x3E, 0x66, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x00},	// Char 159 (.)
	{0x00, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x3A, 0x00},	// Char 160 (.)
	{0x00, 0x3C, 0x60, 0x3C, 0x66, 0x66, 0x3C, 0x00},	// Char 161 (.)
	{0x00, 0x00, 0x7C, 0x66, 0x7C, 0x66, 0x7C, 0x00},	// Char 162 (.)
	{0x00, 0x00, 0x7E, 0x60, 0x60, 0x60, 0x60, 0x00},	// Char 163 (.)
	{0x00, 0x00, 0x1C, 0x3C, 0x6C, 0x6C, 0xFE, 0x82},	// Char 164 (.)
	{0x00, 0x00, 0x3C, 0x66, 0x7E, 0x60, 0x3C, 0x00},	// Char 165 (.)
	{0x00, 0x00, 0xDB, 0x7E, 0x3C, 0x7E, 0xDB, 0x00},	// Char 166 (.)
	{0x00, 0x00, 0x3C, 0x66, 0x0C, 0x66, 0x3C, 0x00},	// Char 167 (.)
	{0x00, 0x00, 0x66, 0x6E, 0x7E, 0x76, 0x66, 0x00},	// Char 168 (.)
	{0x00, 0x18, 0x66, 0x6E, 0x7E, 0x76, 0x66, 0x00},	// Char 169 (.)
	{0x00, 0x00, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0x00},	// Char 170 (.)
	{0x00, 0x00, 0x0E, 0x1E, 0x36, 0x66, 0x66, 0x00},	// Char 171 (.)
	{0x00, 0x00, 0xC6, 0xFE, 0xFE, 0xD6, 0xD6, 0x00},	// Char 172 (.)
	{0x00, 0x00, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x00},	// Char 173 (.)
	{0x00, 0x00, 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x00},	// Char 174 (.)
	{0x00, 0x00, 0x7E, 0x66, 0x66, 0x66, 0x66, 0x00},	// Char 175 (.)
	{0x11, 0x44, 0x11, 0x44, 0x11, 0x44, 0x11, 0x44},	// Char 176 (.)
	{0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA},	// Char 177 (.)
	{0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77, 0xDD, 0x77},	// Char 178 (.)
	{0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},	// Char 179 (.)
	{0x18, 0x18, 0x18, 0xF8, 0x18, 0x18, 0x18, 0x18},	// Char 180 (.)
	{0x18, 0xF8, 0x18, 0xF8, 0x18, 0x18, 0x18, 0x18},	// Char 181 (.)
	{0x36, 0x36, 0x36, 0xF6, 0x36, 0x36, 0x36, 0x36},	// Char 182 (.)
	{0x00, 0x00, 0x00, 0xFE, 0x36, 0x36, 0x36, 0x36},	// Char 183 (.)
	{0x00, 0xF8, 0x18, 0xF8, 0x18, 0x18, 0x18, 0x18},	// Char 184 (.)
	{0x36, 0xF6, 0x06, 0xF6, 0x36, 0x36, 0x36, 0x36},	// Char 185 (.)
	{0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36},	// Char 186 (.)
	{0x00, 0xFE, 0x06, 0xF6, 0x36, 0x36, 0x36, 0x36},	// Char 187 (.)
	{0x36, 0xF6, 0x06, 0xFE, 0x00, 0x00, 0x00, 0x00},	// Char 188 (.)
	{0x36, 0x36, 0x36, 0xFE, 0x00, 0x00, 0x00, 0x00},	// Char 189 (.)
	{0x18, 0xF8, 0x18, 0xF8, 0x00, 0x00, 0x00, 0x00},	// Char 190 (.)
	{0x00, 0x00, 0x00, 0xF8, 0x18, 0x18, 0x18, 0x18},	// Char 191 (.)
	{0x18, 0x18, 0x18, 0x1F, 0x00, 0x00, 0x00, 0x00},	// Char 192 (.)
	{0x18, 0x18, 0x18, 0xFF, 0x00, 0x00, 0x00, 0x00},	// Char 193 (.)
	{0x00, 0x00, 0x00, 0xFF, 0x18, 0x18, 0x18, 0x18},	// Char 194 (.)
	{0x18, 0x18, 0x18, 0x1F, 0x18, 0x18, 0x18, 0x18},	// Char 195 (.)
	{0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00},	// Char 196 (.)
	{0x18, 0x18, 0x18, 0xFF, 0x18, 0x18, 0x18, 0x18},	// Char 197 (.)
	{0x18, 0x1F, 0x18, 0x1F, 0x18, 0x18, 0x18, 0x18},	// Char 198 (.)
	{0x36, 0x36, 0x36, 0x37, 0x36, 0x36, 0x36, 0x36},	// Char 199 (.)
	{0x36, 0x37, 0x30, 0x3F, 0x00, 0x00, 0x00, 0x00},	// Char 200 (.)
	{0x00, 0x3F, 0x30, 0x37, 0x36, 0x36, 0x36, 0x36},	// Char 201 (.)
	{0x36, 0xF7, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00},	// Char 202 (.)
	{0x00, 0xFF, 0x00, 0xF7, 0x36, 0x36, 0x36, 0x36},	// Char 203 (.)
	{0x36, 0x37, 0x30, 0x37, 0x36, 0x36, 0x36, 0x36},	// Char 204 (.)
	{0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00},	// Char 205 (.)
	{0x36, 0xF7, 0x00, 0xF7, 0x36, 0x36, 0x36, 0x36},	// Char 206 (.)
	{0x18, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00},	// Char 207 (.)
	{0x36, 0x36, 0x36, 0xFF, 0x00, 0x00, 0x00, 0x00},	// Char 208 (.)
	{0x00, 0xFF, 0x00, 0xFF, 0x18, 0x18, 0x18, 0x18},	// Char 209 (.)
	{0x00, 0x00, 0x00, 0xFF, 0x36, 0x36, 0x36, 0x36},	// Char 210 (.)
	{0x36, 0x36, 0x36, 0x3F, 0x00, 0x00, 0x00, 0x00},	// Char 211 (.)
	{0x18, 0x1F, 0x18, 0x1F, 0x00, 0x00, 0x00, 0x00},	// Char 212 (.)
	{0x00, 0x1F, 0x18, 0x1F, 0x18, 0x18, 0x18, 0x18},	// Char 213 (.)
	{0x00, 0x00, 0x00, 0x3F, 0x36, 0x36, 0x36, 0x36},	// Char 214 (.)
	{0x36, 0x36, 0x36, 0xFF, 0x36, 0x36, 0x36, 0x36},	// Char 215 (.)
	{0x18, 0xFF, 0x18, 0xFF, 0x18, 0x18, 0x18, 0x18},	// Char 216 (.)
	{0x18, 0x18, 0x18, 0xF8, 0x00, 0x00, 0x00, 0x00},	// Char 217 (.)
	{0x00, 0x00, 0x00, 0x1F, 0x18, 0x18, 0x18, 0x18},	// Char 218 (.)
	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},	// Char 219 (.)
	{0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},	// Char 220 (.)
	{0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0},	// Char 221 (.)
	{0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F},	// Char 222 (.)
	{0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00},	// Char 223 (.)
	{0x00, 0x00, 0x7C, 0x66, 0x66, 0x7C, 0x60, 0x00},	// Char 224 (.)
	{0x00, 0x00, 0x3C, 0x66, 0x60, 0x66, 0x3C, 0x00},	// Char 225 (.)
	{0x00, 0x00, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00},	// Char 226 (.)
	{0x00, 0x00, 0x66, 0x66, 0x3E, 0x06, 0x7C, 0x00},	// Char 227 (.)
	{0x00, 0x00, 0x7E, 0xDB, 0xDB, 0x7E, 0x18, 0x00},	// Char 228 (.)
	{0x00, 0x00, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x00},	// Char 229 (.)
	{0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x7F, 0x03},	// Char 230 (.)
	{0x00, 0x00, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x00},	// Char 231 (.)
	{0x00, 0x00, 0xDB, 0xDB, 0xDB, 0xDB, 0xFF, 0x00},	// Char 232 (.)
	{0x00, 0x00, 0xDB, 0xDB, 0xDB, 0xDB, 0xFF, 0x03},	// Char 233 (.)
	{0x00, 0x00, 0xE0, 0x60, 0x7C, 0x66, 0x7C, 0x00},	// Char 234 (.)
	{0x00, 0x00, 0xC6, 0xC6, 0xF6, 0xDE, 0xF6, 0x00},	// Char 235 (.)
	{0x00, 0x00, 0x60, 0x60, 0x7C, 0x66, 0x7C, 0x00},	// Char 236 (.)
	{0x00, 0x00, 0x7C, 0x06, 0x3E, 0x06, 0x7C, 0x00},	// Char 237 (.)
	{0x00, 0x00, 0xCE, 0xDB, 0xFB, 0xDB, 0xCE, 0x00},	// Char 238 (.)
	{0x00, 0x00, 0x3E, 0x66, 0x3E, 0x36, 0x66, 0x00},	// Char 239 (.)
	{0x00, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00},	// Char 240 (.)
	{0x10, 0x10, 0x7C, 0x10, 0x10, 0x00, 0x7C, 0x00},	// Char 241 (.)
	{0x00, 0x30, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x30},	// Char 242 (.)
	{0x00, 0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C},	// Char 243 (.)
	{0x0E, 0x1B, 0x1B, 0x18, 0x18, 0x18, 0x18, 0x18},	// Char 244 (.)
	{0x18, 0x18, 0x18, 0x18, 0x18, 0xD8, 0xD8, 0x70},	// Char 245 (.)
	{0x00, 0x18, 0x18, 0x00, 0x7E, 0x00, 0x18, 0x18},	// Char 246 (.)
	{0x00, 0x76, 0xDC, 0x00, 0x76, 0xDC, 0x00, 0x00},	// Char 247 (.)
	{0x00, 0x38, 0x6C, 0x6C, 0x38, 0x00, 0x00, 0x00},	// Char 248 (.)
	{0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00},	// Char 249 (.)
	{0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00},	// Char 250 (.)
	{0x03, 0x02, 0x06, 0x04, 0xCC, 0x68, 0x38, 0x10},	// Char 251 (.)
	{0x3C, 0x42, 0x99, 0xA1, 0xA1, 0x99, 0x42, 0x3C},	// Char 252 (.)
	{0x30, 0x48, 0x10, 0x20, 0x78, 0x00, 0x00, 0x00},	// Char 253 (.)
	{0x00, 0x00, 0x7C, 0x7C, 0x7C, 0x7C, 0x00, 0x00},	// Char 254 (.)
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x7E, 0x00}	// Char 255 (.)
};

public:
	font();
	~font();
	bool charToPixels8(char letter, char * instring);
	bool charToPixels16(char letter, char * instring);
};
