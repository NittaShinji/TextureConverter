#pragma once
#include <vector>
#include <string>

//�e�N�X�`���R���o�[�^�[
class TextureConverter
{

public:

	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�����
	/// </summary>
	/// <param name="filepath">�t�@�C���p�X</param>
	void ConvertTextureWICToDDS(const std::string& filepath);

private:

	/// <summary>
	/// �e�N�X�`���t�@�C���ǂݍ���
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	/// <summary>
	/// �}���`�o�C�g����������C�h������ɕϊ�
	/// </summary>
	/// <param name="mString">�}���`�o�C�g������</param>
	/// <returns>���C�h������</returns>
	static std::vector<wchar_t> ConvertMultiByteStringToWideString(const std::string& mString);

};

