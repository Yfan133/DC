#include "LZ77.h"

LZ77::LZ77()
	: _pWin(new uch[2 * WSIZE])
	, _ht(WSIZE)
{}
LZ77::~LZ77()
{

}
void LZ77::CompressLZ77(const string& filePath)
{
	FILE* fIn = fopen(filePath.c_str(), "rb");
	if (fIn == nullptr)
	{
		std::cout << "" << std::endl;
		return;
	}
	// 如果文件太小，则不进行压缩
	fseek(fIn, 0, SEEK_END);
	ulg fileSize = ftell(fIn);
	fseek(fIn, 0, SEEK_SET);
	if (fileSize < 3)
	{
		std:: cout << "" << std::endl;
		return;
	}
	// 读取一个窗口大小
	ulg lookahead = fread(_pWin, 1, 2 * WSIZE, fIn);
	ush hashAddr = 0;
	ush matchHead = 0;

	for (ush i = 0; i < MIN_MATCH - 1; ++i)
	{
		_ht.Insert(hashAddr, _pWin[i], i, matchHead);
	}

	FILE* fout = fopen("compress.txt", "wb");
	ush start = 0;
	ush curMatchLength = 0;
	ush curMatchDist = 0;
	// 开始边匹配 边插入哈希桶
	while (true)
	{
		// 将三个字符的位置插入哈希桶
		_ht.Insert(hashAddr, _pWin[start + 2], start, matchHead);
		// 
		if (matchHead == 0)
		{
			// 说明这三个字符没有重复过，则写入文件
			fputc(_pWin[start], fout);
			++start;
		}
		else
		{	// 说明已经有重复了
			// 找最长匹配
			curMatchLength = LongestMatch(matchHead, start, curMatchDist);
			
			// 将<长度，距离>写入压缩文件中
			fputc(curMatchLength - 3, fout);

			// 问题：为什么这里传入ush？？？
			fwrite(&curMatchDist, 2, 1, fout);
		}
	}


	fclose(fIn);
}

ush LZ77::LongestMatch(ush matchHead, ush start, ush& curMatchDist)
{
	ush maxLength = 0;
	do
	{
		uch* pScan = _pWin + matchHead;
		uch* pEnd = pScan + MIN_MATCH;
		uch* pStart = _pWin + start;

		ush curLength = 0;
		ush curDist = 0;

		while (pScan < pEnd && *pScan == *pStart)
		{
			++pScan;
			++pStart;
			++curLength;
		}
		curDist = start - matchHead;

		if (curLength > maxLength)
		{
			// 取最长的匹配
			maxLength = curLength;
			curMatchDist = curDist;
		}

	} while (matchHead = _ht.GetNext(matchHead));
	// 找一次匹配
	return maxLength;
}