#include "TextureConverter.h"

using namespace DirectX;

void TextureConverter::ConvertTextureWICToDDS(const std::string& filepath)
{
	//テクスチャファイルを読み込む
	LoadWICTextureFromFile(filepath);
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//ファイルパスをワイド文字列に変換
	std::vector<wchar_t> wfilePath = ConvertMultiByteStringToWideString(filePath);

	//WICテクスチャのロード
	HRESULT result = LoadFromWICFile(wfilePath.data(), WIC_FLAGS_NONE, &metadata_, scratchImage_);

	assert(SUCCEEDED(result));
}

std::vector<wchar_t> TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換した際の文字列バッファサイズを計算
	int32_t filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列に変換
	std::vector<wchar_t> wfilePath(filePathBufferSize);
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, wfilePath.data(), filePathBufferSize);

	return wfilePath;
}
