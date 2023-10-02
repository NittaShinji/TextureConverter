#include "TextureConverter.h"
#include <DirectXTex.h>

void TextureConverter::ConvertTextureWICToDDS(const std::string& filepath)
{
	//�e�N�X�`���t�@�C����ǂݍ���
	LoadWICTextureFromFile(filepath);
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//�t�@�C���p�X�����C�h������ɕϊ�
	std::vector<wchar_t> wfilePath = ConvertMultiByteStringToWideString(filePath);
}

std::vector<wchar_t> TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	////���C�h������ɕϊ������ۂ̕�����o�b�t�@�T�C�Y���v�Z
	//int32_t filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	////���C�h������
	//std::wstring wString;
	//wString.resize(filePathBufferSize);

	////���C�h������ɕϊ�
	//MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	//���C�h������ɕϊ������ۂ̕�����o�b�t�@�T�C�Y���v�Z
	int32_t filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//���C�h������ɕϊ�
	std::vector<wchar_t> wfilePath(filePathBufferSize);
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, wfilePath.data(), filePathBufferSize);


	return wfilePath;
}
