#include "windows.h"
#include <iostream>
#include <string.h>
void base64_decode_s(const unsigned char *code, std::string& outstr, long* lpBufLen)
{
	//根据base64表，以字符找到对应的十进制数据  
	int table[]={0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,62,0,0,0,
		63,52,53,54,55,56,57,58,
		59,60,61,0,0,0,0,0,0,0,0,
		1,2,3,4,5,6,7,8,9,10,11,12,
		13,14,15,16,17,18,19,20,21,
		22,23,24,25,0,0,0,0,0,0,26,
		27,28,29,30,31,32,33,34,35,
		36,37,38,39,40,41,42,43,44,
		45,46,47,48,49,50,51
	};  
	long len;  
	long str_len;   
	int i,j;  


	len = strlen((const char*)code);  
	if(strstr((const char*)code,"=="))  
		str_len=len/4*3-2;  
	else if(strstr((const char*)code,"="))  
		str_len=len/4*3-1;  
	else  
		str_len=len/4*3;  

	if (NULL != lpBufLen) {
		*lpBufLen = str_len;
	}

	outstr.resize(sizeof(unsigned char)*len+1);


	//以4个字符为一位进行解码  
	for(i=0,j=0;i < len-2;j+=3,i+=4)  
	{  
		outstr[j]=((unsigned char)table[code[i]])<<2 | (((unsigned char)table[code[i+1]])>>4); //取出第一个字符对应base64表的十进制数的前6位与第二个字符对应base64表的十进制数的后2位进行组合  
		outstr[j+1]=(((unsigned char)table[code[i+1]])<<4) | (((unsigned char)table[code[i+2]])>>2); //取出第二个字符对应base64表的十进制数的后4位与第三个字符对应bas464表的十进制数的后4位进行组合  
		outstr[j+2]=(((unsigned char)table[code[i+2]])<<6) | ((unsigned char)table[code[i+3]]); //取出第三个字符对应base64表的十进制数的后2位与第4个字符进行组合  
	}  


/*
安卓群控
stf
minicap
AndroidControl
adb shell
投屏
群控
*/
	return; 
}
