#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
	printf("\n --- MCAutoSprint ---\n\nwキーを押したら作動します(自動)\n");

	// 初期化
	bool iskeydown, tempdown;
	std::fstream settings;
	std::string minecraft = "Minecraft";
	std::string configfile = "setting.txt";
	// 設定ファイル
	settings.open(configfile);

	// キー設定
	int dashkey;
	settings >> dashkey;
	printf("\nダッシュキー 仮想コード : %d で読み込まれました。\nCtrl、Deleteキーを同時押しするとexeが終了します。\n", dashkey);

	while (1)
	{

		// メインウィンドウ確認
		char window_title[500];
		HWND foreground = GetForegroundWindow();
		GetWindowText(foreground, window_title, sizeof(window_title));
		if (minecraft != window_title)
		{
		}

		// wasd移動
		else if (GetAsyncKeyState('W'))
		{
			iskeydown = true;
		}
		else if (GetAsyncKeyState('A'))
		{
			iskeydown = true;
		}
		else if (GetAsyncKeyState('S'))
		{
			iskeydown = true;
		}
		else if (GetAsyncKeyState('D'))
		{
			iskeydown = true;
		}
		else
		{
			iskeydown = false;
		}

		// 押されたら
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

		// ctrl+delで終了する
		if (GetAsyncKeyState(VK_DELETE) && GetAsyncKeyState(VK_CONTROL))
		{
			keybd_event(dashkey, 0x00, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			break;
		}
		Sleep(10);
	}
	return 0;
}