#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
	printf("\n --- MCAutoSprint ---\n\nPress the WASD key to automatically Sprint.\n");

	bool iskeydown, tempdown;
	std::fstream settings;
	std::string minecraft = "Minecraft";
	// 設定ファイル
	std::string configfile = "setting.txt";
	settings.open(configfile);

	// キー設定
	int dashkey;
	settings >> dashkey;
	printf("\nSprint Key (Virtual-Key) is set to %d\nSimultaneous pressing of Ctrl and Delete key will exit.\n", dashkey);

	while (1)
	{

		// メインウィンドウ
		char window_title[500];
		HWND foreground = GetForegroundWindow();
		GetWindowText(foreground, window_title, sizeof(window_title));
		if (minecraft != window_title)
		{
		}

		// wasd移動
		else if (GetAsyncKeyState('W') || GetAsyncKeyState('A') || GetAsyncKeyState('S') || GetAsyncKeyState('D'))
		{
			iskeydown = true;
		}
		else
		{
			iskeydown = false;
		}

		// 押したら
		if (iskeydown && !tempdown)
		{
			keybd_event(dashkey, 0x00, KEYEVENTF_EXTENDEDKEY | 0, 0);
			tempdown = true; // 押し保存
		}
		// 離したら
		if (!iskeydown && tempdown)
		{
			keybd_event(dashkey, 0x00, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			tempdown = false; // 離し保存
		}

		// 終了する
		if (GetAsyncKeyState(VK_DELETE) && GetAsyncKeyState(VK_CONTROL))
		{
			keybd_event(dashkey, 0x00, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			break;
		}
		Sleep(10);
	}
	return 0;
}