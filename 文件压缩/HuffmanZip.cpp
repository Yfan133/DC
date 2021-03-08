#include "HuffmanZip.hpp"
#pragma warning(disable : 4996)

////////////////////////////////////////////// ÿ���ַ��Ľṹ������
CharInf::CharInf(const ulg& times = 0)
	: _times(times)
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
	FILE* fpin = fopen(filePath.c_str(), "rb");
	if (fpin == nullptr)
	{
		std::cout << "���ļ�ʧ��" << std::endl;
	}
	uch buf[1024];
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

	FILE* fpout = fopen("Reduce.txt", "wb");
	WriteHeadInf(fpout, filePath);
////////////////////////////////////////////////////////////////////////////////

	uch bitCount = 0;	// ���ڼ���ÿ8λ(1�ֽ�)�����ļ�дһ��
	uch bitMap = 0;
	while (length = fread(buf, 1, 1024, fpin))
	{
		for (size_t i = 0; i < length; ++i)
		{
			std::string& Encode = ch_vec[buf[i]]._encode;
			for (size_t j = 0; j < Encode.size(); ++j)
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
	// ��������������ϢҲ������ѹ���ļ��У��Ա��ѹ���ؽ���
	// 1.�з��ļ���׺
	std::string fileStr;
	fileStr = filePath.substr(filePath.find("."));
	fileStr += "\n";
	
	// 2.��¼Ҷ�ڵ����
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

	// 3.�����д��ѹ���ļ�
	fwrite(fileStr.c_str(), 1, fileStr.size(), fpout);
	fwrite(chAppear.c_str(), 1, chAppear.size(), fpout);
}
void HuffmanZip::UnReduce(const std::string& filePath)
{
	// ��ѹ���ļ����н�ѹ������д���µ��ļ�
	// 1.���ļ���һ��һ�н��ж�ȡ
	FILE* fpin = fopen(filePath.c_str(), "rb");
	
	// ��ȡ�ļ���
	std::string filename("text2");
	GetLine(fpin, filename);

	// ��ȡ�ַ�����
	std::string size_str;
	GetLine(fpin, size_str);
	ulg ch_size = std::stoi(size_str);

	// ��ȡȫ���ַ�
	for (ulg i = 0; i < ch_size; i++)
	{
		// A,1
		std::string ch_str;
		GetLine(fpin, ch_str);
		if (ch_str == "")
		{
			ch_str += '\n'; 
			GetLine(fpin, ch_str);
		}
		ch_vec[uch(ch_str[0])]._times = std::stoi(ch_str.substr(2));
	}

	// 2.��������������file_size == ���ڵ��Ȩֵ
	HuffmanTree<CharInf> hft;
	HuffmanNode<CharInf>* root = hft.CreateTree(ch_vec, CharInf(0));

	// 3.ͨ�� ���λ & 0x80 ��������Ϊ1����cur�����ߣ����������ߣ��������Ҷ�ڵ����ַ�������ļ�
	ulg file_size = root->_val._times;
	FILE* fpout = fopen(filename.c_str(), "wb");

	uch buf[1024];
	HuffmanNode<CharInf>* cur = root;
	ulg length = 0;
	while (length = fread(buf, 1, 1024, fpin))
	{
		for (ulg i = 0; i < length; ++i)
		{
			uch charBit = buf[i];
			ulg bitCount = 8;
			while (bitCount)
			{
				if (charBit & 0x80)
					cur = cur->right;
				else
					cur = cur->left;
				if (cur->left == nullptr && cur->right == nullptr)
				{
					fputc(cur->_val._ch, fpout);
					cur = root;
					// 4.ÿ���һ�ξ��� file_size--����� file_sizeΪ0�����ı���λ�Ѿ���Ч������ѭ��
					if (--file_size == 0)
						break;
				}
				charBit <<= 1;
				bitCount--;
			}
		}
	}
	// 5.�ر��ļ���ָ��
	fclose(fpin);
	fclose(fpout);
}
void HuffmanZip::GetLine(FILE* fpin, std::string& buf)
{
	while (!feof(fpin))
	{
		uch ch = fgetc(fpin);
		if (ch == '\n')
			break;
		buf += ch;
	}
}
int main()
{
	HuffmanZip hfz;
	hfz.Reduce("text.txt");
	hfz.CheckVec();
	hfz.UnReduce("Reduce.txt");
	return 0;
}