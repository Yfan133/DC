#include "HuffmanZip.hpp"
#pragma warning(disable : 4996)

////////////////////////////////////////////// ÿ���ַ��Ľṹ������
CharInf::CharInf(const ulg& times = 0)
	: _ch(0)
	, _times(times)
{}
CharInf CharInf::operator+(const CharInf& ch)const
{
	return CharInf(_times + ch._times);
}
bool CharInf::operator>(const CharInf& ch)const
{
	return _times > ch._times;
}
bool CharInf::operator!=(const CharInf& ch)const
{
	return _times != ch._times;
}

////////////////////////////////////////////// ������ѹ���Ĳ���
HuffmanZip::HuffmanZip()
	: ch_vec(256)
{
	// ch_vec.resize(256);
	for (int i = 0; i < 256; i++)
		ch_vec[i]._ch = i;
}
void HuffmanZip::Reduce(const std::string& filePath)
{
	// 1.���ļ�����ͳ��ÿ���ַ����ֵĴ���
	FILE* fpin = fopen(filePath.c_str(), "r+");
	if (fpin == nullptr)
	{
		std::cout << "���ļ�ʧ��" << std::endl;
	}
	char buf[1024];
	size_t length;
	while (length = fread(buf, 1, 1024, fpin))
	{
		for (size_t i = 0; i < length; i++)
			++ch_vec[buf[i]]._times;
	}

	// 2.�����鹹��һ�ù�������
	HuffmanTree<CharInf> hft;
	HuffmanNode<CharInf>* root = hft.CreateTree(ch_vec, CharInf(0));

	// 3.���������������ҳ�ÿ���ַ��Ķ����Ʊ���
	std::string str;	// ���ڴ洢������������
	HuffmanEncode(root, str);

	// 4.�ñ����Դ�ļ��ַ����и�д����д�����ļ�
	
	rewind(fpin);			// ���¶�λ���ļ���

	FILE* fpout = fopen("Reduce.txt", "w");
	WriteHeadInf(fpout, filePath);
////////////////////////////////////////////////////////////////////////////////

	uch bitCount = 0;	// ���ڼ���ÿ8λ(1�ֽ�)�����ļ�дһ��
	uch bitMap = 0;
	while (length = fread(buf, 1, 1024, fpin))
	{
		for (size_t i = 0; i < length; ++i)
		{
			std::string& Encode = ch_vec[buf[i]]._encode;
			for (int j = 0; j < Encode.size(); ++j)
			{
				bitMap <<= 1;
				if (Encode[j] == '1')
					bitMap |= 1;
				bitCount++;
				if (bitCount == 8)
				{
					fputc(bitMap, fpout);
					bitMap = 0;
					bitCount = 0;
				}
			}
		}
	}
	if (bitCount != 0)
	{
		bitMap <<= (8 - bitCount);
		fputc(bitMap, fpout);
	}
	// 5.�ر��ļ���ָ��
	fclose(fpin);
	fclose(fpout);
}
void HuffmanZip::HuffmanEncode(HuffmanNode<CharInf>* root, std::string& str)
{
	// ����Ҷ�ӽڵ�
	if (root->left == nullptr && root->right == nullptr)
	{
		// ֱ�Ӹ������еĶ�Ӧ���븳ֵ
		ch_vec[root->_val._ch]._encode = str;
		return;
	}
	// ��������
	if (root->left)
	{
		str.push_back('0');
		HuffmanEncode(root->left, str);
		str.pop_back();
	}
	// ��������
	if (root->right)
	{
		str.push_back('1');
		HuffmanEncode(root->right, str);
		str.pop_back();
	}
}
void HuffmanZip::WriteHeadInf(FILE* fpout, const std::string& filePath)
{
	std::string fileStr;
	fileStr = filePath.substr(filePath.find("."));
	fileStr += "\n";
	
	size_t length = 0;
	
	std::string chAppear;
	for (size_t i = 0; i < 256; i++)
	{
		if (ch_vec[i]._times != 0)
		{
			chAppear += ch_vec[i]._ch;
			chAppear += ",";
			chAppear += std::to_string(ch_vec[i]._times);
			chAppear += "\n";
			length++;
		}
	}
	fileStr += std::to_string(length);
	fileStr += "\n";

	fwrite(fileStr.c_str(), 1, fileStr.size(), fpout);
	fwrite(chAppear.c_str(), 1, chAppear.size(), fpout);
}

int main()
{
	HuffmanZip hfz;
	hfz.Reduce("text.txt");
	hfz.CheckVec();
	return 0;
}