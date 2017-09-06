#pragma once

#define CONFIG_FILE_SIZE	100*1024
typedef struct config_struct{
	int ledSelect;
}configStruct;

const char configFileContentDefault[10][100]	=
{
	"ledSelect=[0]",
	"fonstSelect=[Î¢ÈíÑÅºÚ]",
};
