#include "Common.h"

#if 0
UINT16 maksBlockInfo[32]
UINT16 MaskBlock(char *pMask)
{
	char *maskBitsVal = pMask;
	UINT16 maskBlockNum = 0;
	while()
	{
		if(pMask[0] == 0x55)
		{
			maskBlockNum++;
			pMask = pMask + 4
		}

	}

}
#endif




void AnalyMask(const char *path)
{
	FILE *fp=NULL;
	char *pMask = NULL;
	UINT16 ret = 0;
	if(path == NULL)
	{
		return ERROR;
	}

	fp = fopen(path,r);
	if(fp == NULL)
	{
		PRT("");
		return ERROR;
	}

	pMask=  malloc(MASKLENGTH);
	if(fp == NULL)
	{
		PRT("");
		return ERROR;
	}
	
	ret = fread(pMask,1,MASKLENGTH,fp);
	if(fp == NULL)
	{
		PRT("");
		free(pMask);
		return ERROR;
	}
	
	for()

	

}























