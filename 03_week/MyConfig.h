#pragma once
struct _BufByte {
	char byteSpace; 
};

struct _Version {
	short Major = 0;
	short Minor = 0;
	short Revision = 0;
	_BufByte localBuff;
};

struct _WiFi {
	char SSID[50];
	_BufByte localBuf1;
	char Pswd[50];
	_BufByte localBuf2;
};

struct Config {
	_Version version;
	_WiFi wifi;
};