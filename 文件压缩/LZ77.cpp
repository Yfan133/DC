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
	// ����ļ�̫С���򲻽���ѹ��
	fseek(fIn, 0, SEEK_END);
	ulg fileSize = ftell(fIn);
	fseek(fIn, 0, SEEK_SET);
	if (fileSize < 3)
	{
		std:: cout << "" << std::endl;
		return;
	}
	// ��ȡһ�����ڴ�С
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
	// ��ʼ��ƥ�� �߲����ϣͰ
	while (true)
	{
		// �������ַ���λ�ò����ϣͰ
		_ht.Insert(hashAddr, _pWin[start + 2], start, matchHead);
		// 
		if (matchHead == 0)
		{
			// ˵���������ַ�û���ظ�������д���ļ�
			fputc(_pWin[start], fout);
			++start;
		}
		else
		{	// ˵���Ѿ����ظ���
			// ���ƥ��
			curMatchLength = LongestMatch(matchHead, start, curMatchDist);
			
			// ��<���ȣ�����>д��ѹ���ļ���
			fputc(curMatchLength - 3, fout);

			// ���⣺Ϊʲô���ﴫ��ush������
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
			// ȡ���ƥ��
			maxLength = curLength;
			curMatchDist = curDist;
		}

	} while (matchHead = _ht.GetNext(matchHead));
	// ��һ��ƥ��
	return maxLength;
}