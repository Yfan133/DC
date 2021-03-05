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
bool CharInf::operator!()
{
	return _times != 0;
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
	FILE* fp = fopen(filePath.c_str(), "r+");
	char buf[1024];
	size_t length;
	while (length = fread(buf, 1, 1024, fp))
	{
		for (size_t i = 0; i < length; i++)
			++ch_vec[buf[i]]._times;
	}

	// 2.�����鹹��һ�ù�������
	HuffmanTree<CharInf> hft;
	HuffmanNode<CharInf>* root = hft.CreateTree(ch_vec);

	// 3.���������������ҳ�ÿ���ַ��Ķ����Ʊ���
	std::string str;	// ���ڴ洢������������
	HuffmanEncode(root, str);

	// 4.�ر��ļ���ָ��
	fclose(fp);
}
void HuffmanZip::HuffmanEncode(HuffmanNode<CharInf>* root, std::string& str)
{
	// ����Ҷ�ӽڵ�
	if (root->left == nullptr && root->right == nullptr)
	{
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

int main()
{
	HuffmanZip hfz;
	hfz.Reduce("text.txt");
	hfz.CheckVec();
	return 0;
}