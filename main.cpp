#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <DirectXTex.h>
#include "TextureConverter.h"

//コマンドライン引数
enum Argument
{
	kApplicationPath,	//アプリケーションのパス
	kFilePath,			//渡されたファイルのパス

	NumArgument
};

int main(int32_t argc, char* argv[])
{
	//assert(argc >= NumArgument);

	//コマンドライン引数指定なし
	if(argc < NumArgument)
	{
		//使い方を表示する
		TextureConverter::OutputUsage();
		return 0;
	}

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバータ
	TextureConverter converter;

	//オプションの数
	int numOptions = argc - NumArgument;
	//オプションの配列
	char** options = argv + NumArgument;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	//system("pause"); 
	return 0;
}