#include "HuffmanZip.hpp"
#pragma warning(disable : 4996)

////////////////////////////////////////////// 每个字符的结构体类型
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

////////////////////////////////////////////// 哈夫曼压缩的操作
HuffmanZip::HuffmanZip()
	: ch_vec(256)
{
	// ch_vec.resize(256);
	for (int i = 0; i < 256; i++)
		ch_vec[i]._ch = i;
}
void HuffmanZip::Reduce(const std::string& filePath)
{
	// 1.打开文件，并统计每个字符出现的次数
	FILE* fp = fopen(filePath.c_str(), "r+");
	char buf[1024];
	size_t length;
	while (length = fread(buf, 1, 1024, fp))
	{
		for (size_t i = 0; i < length; i++)
			++ch_vec[buf[i]]._times;
	}

	// 2.用数组构造一棵哈夫曼树
	HuffmanTree<CharInf> hft;
	HuffmanNode<CharInf>* root = hft.CreateTree(ch_vec);

	// 3.遍历哈夫曼树，找出每个字符的二进制编码
	std::string str;	// 用于存储哈夫曼树编码
	HuffmanEncode(root, str);

	// 4.关闭文件流指针
	fclose(fp);
}
void HuffmanZip::HuffmanEncode(HuffmanNode<CharInf>* root, std::string& str)
{
	// 到达叶子节点
	if (root->left == nullptr && root->right == nullptr)
	{
		ch_vec[root->_val._ch]._encode = str;
		return;
	}
	// 遍历左树
	if (root->left)
	{
		str.push_back('0');
		HuffmanEncode(root->left, str);
		str.pop_back();
	}
	// 遍历右树
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