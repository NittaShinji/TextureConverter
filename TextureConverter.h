#pragma once
#include <vector>
#include <string>

//テクスチャコンバーター
class TextureConverter
{

public:

	/// <summary>
	/// テクスチャをWICからDDSに変換する
	/// </summary>
	/// <param name="filepath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filepath);

private:

	/// <summary>
	/// テクスチャファイル読み込み
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	/// <summary>
	/// マルチバイト文字列をワイド文字列に変換
	/// </summary>
	/// <param name="mString">マルチバイト文字列</param>
	/// <returns>ワイド文字列</returns>
	static std::vector<wchar_t> ConvertMultiByteStringToWideString(const std::string& mString);

};

