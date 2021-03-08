#include "HuffmanZip.hpp"
#pragma warning(disable : 4996)

////////////////////////////////////////////// 每个字符的结构体类型
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
	FILE* fpin = fopen(filePath.c_str(), "rb");
	if (fpin == nullptr)
	{
		std::cout << "打开文件失败" << std::endl;
	}
	uch buf[1024];
	size_t length;
	while (length = fread(buf, 1, 1024, fpin))
	{
		for (size_t i = 0; i < length; i++)
			++ch_vec[buf[i]]._times;
	}

	// 2.用数组构造一棵哈夫曼树
	HuffmanTree<CharInf> hft;
	HuffmanNode<CharInf>* root = hft.CreateTree(ch_vec, CharInf(0));

	// 3.遍历哈夫曼树，找出每个字符的二进制编码
	std::string str;	// 用于存储哈夫曼树编码
	HuffmanEncode(root, str);

	// 4.用编码对源文件字符进行改写，并写入新文件
	
	rewind(fpin);			// 重新定位到文件首

	FILE* fpout = fopen("Reduce.txt", "wb");
	WriteHeadInf(fpout, filePath);
////////////////////////////////////////////////////////////////////////////////

	uch bitCount = 0;	// 用于计算每8位(1字节)，往文件写一次
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
	// 5.关闭文件流指针
	fclose(fpin);
	fclose(fpout);
}
void HuffmanZip::HuffmanEncode(HuffmanNode<CharInf>* root, std::string& str)
{
	// 到达叶子节点
	if (root->left == nullptr && root->right == nullptr)
	{
		// 直接给数组中的对应编码赋值
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
void HuffmanZip::WriteHeadInf(FILE* fpout, const std::string& filePath)
{
	// 将哈夫曼树的信息也保存在压缩文件中，以便解压缩重建树
	// 1.切分文件后缀
	std::string fileStr;
	fileStr = filePath.substr(filePath.find("."));
	fileStr += "\n";
	
	// 2.记录叶节点个数
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

	// 3.将结果写入压缩文件
	fwrite(fileStr.c_str(), 1, fileStr.size(), fpout);
	fwrite(chAppear.c_str(), 1, chAppear.size(), fpout);
}
void HuffmanZip::UnReduce(const std::string& filePath)
{
	// 将压缩文件进行解压缩，并写入新的文件
	// 1.打开文件，一行一行进行读取
	FILE* fpin = fopen(filePath.c_str(), "rb");
	
	// 读取文件名
	std::string filename("text2");
	GetLine(fpin, filename);

	// 读取字符数量
	std::string size_str;
	GetLine(fpin, size_str);
	ulg ch_size = std::stoi(size_str);

	// 读取全部字符
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

	// 2.建立哈夫曼树，file_size == 根节点的权值
	HuffmanTree<CharInf> hft;
	HuffmanNode<CharInf>* root = hft.CreateTree(ch_vec, CharInf(0));

	// 3.通过 最高位 & 0x80 ，如果结果为1，则cur往右走，否则往左走，如果到达叶节点则将字符输出到文件
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
					// 4.每输出一次就让 file_size--，如果 file_size为0则后面的比特位已经无效，跳出循环
					if (--file_size == 0)
						break;
				}
				charBit <<= 1;
				bitCount--;
			}
		}
	}
	// 5.关闭文件流指针
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