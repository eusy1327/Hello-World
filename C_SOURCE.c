/*   예제 LIST
66. 문자열 에서 문자열의 갯수 구하기
65. 무빙 윈도우 (필터없음)
64. ASCII <-> UNICODE 변환
63. base64 인코딩과 디코딩 구현
62. C++에서 IO 방법 std::
61. Endian
60. do while
59. 랜덤함수
58. 문자열 연결 함수 strcat
57. 포인터를 이용해 문자열 바꿔치기
56. 문자열 검색시 null 값이 섞여 있을때
55. CheckSumCalculator
54. Median 필터
53. CIB 유량계산 프로토타입
52. Segment (활꼴 면적 구하기)
51. PrefixUnit 누적유량같은 큰 값을 lcd에 표현하기 위한 함수
50. 문자열 토큰 처리
49. 인자로 받은 정수값을 포인터를 이용해 바꾸기
48. 2중 포인터
47. 2진수로 출력
46. XOR 연산 (두 값중 변화된 비트만 검출 )
45. 비트 마스크 2 (bit mask)
44. 비트 마스크 1 (bit mask)
43 . 함수 리턴값을 인자로 받기
42 . 시간갱신 코드
41 . 문자열 포인터에서 문자열의 갯수 구하기
40 . 구조체의 컨텐츠 갯수 구하기
39 . HexToBin
38 . Integer To Float
37 . 바이너리로 출력
36 . 폰트(arry) 90도 회전
35 . 시리얼 포트로 데이터 출력
34 . 4~20mA 계산과정함수
33 . scanf
32 . 이중포인터 or 다중포인터
31 . 함수인자로 포인터사용
30 . 매닝공식 계산과정
29 . itoa
28 . ASC TO HEX 로 변환
27 . itoa
26 . ASC TO HEX 로 변환
25 . ASC TO HEX 로 변환
24 . sprintf함수를 이용해 Hex <-> Ascii 변환
23 . %연산자 동작시험
22 . 연산자 동작시험
21 . 헥사로 채워진 배열의 위치찾기
20 . 포인터로 2개의 변수값연결
19 . 2차배열의 크기확인
18 . strtok 함수를 이용해 문자열토크처리
17 . 문자열 검색함수 strstr
16 . 문자열과 문자열을 연결시키는 포인터
15 . 버퍼값 rotation 시킨후 다른버퍼에 저장
14 . printf 2진수로 출력
13 . 자동 캘리브레이션
11 . 구조체에서 포인터 역참조

10 . 링버퍼
9 . Float To String 함수

7 . 주어진 문자열에서 원하는 문자를 찾는함수
6 . 정해진 주기마다 시간 갱신
5 . 문자열에서 스페이스로 구분하기
4 . 근사값 찾기
3 . itoa 정수를 문자열로
2 . MINIMUM 근사값찾기
1 . 콘솔창 한곳에서 printf하기

이클립스에서 구글 주소록.csv 파일 읽을때 이클립스 설정
	Window > Preferences > General > Workspace 에서 Text file encoding 를 Default 에서 Other(UTF-8) 로 설정 하면
	유니코드로 되어있는 파일을 볼 수 있다.

*/

// Alt+F8 누르면 소스코드 자동정렬.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h> // Sleep(1000)
#include <tchar.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <sys/types.h>
#include <errno.h>

//#include <iostream>       // std::cin, std::cout, std::boolalpha
//#include <bitset>         // std::bitset
#ifndef DEBUG
#define DEBUG   // <<-- 요기를 주석처리한후 실행해보세요!!
// Sleep(1000);	1초 딜레이 함수
// printf("%s\r\nbuffer.buf);디버깅할때 사용

//====================== 67. SFM-500 체크섬   ================
// SFM-500 체크섬   ########  unsigned char 연산에 주의 !!!!!!!
unsigned int get_checksum(unsigned char *data_ptr, unsigned int length)
{
    unsigned int i;
    unsigned int checksum;

    checksum = 0;
    if(length>512){
        length = 0;
    }
    for(i=0;i<length;i++){
        checksum += *data_ptr++;
    }
    return checksum;
}

int main(void) {
	unsigned int checksum;

	unsigned char test_sum1[] = {
	/*0x55,0x55,*/0xF0,0x14,0x00,0x25,0x00,0x34,0x35,0x38,
	0x30,0x30,0x32,0x30,0x30,0x35,0x35,0x30,0x77,0x01,
	0x01,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00/*,0x03,0xD1,0xF0,0xF0*/};

	while (1) {
		checksum = get_checksum(test_sum1, sizeof(test_sum1));
		printf("=====> 0x%04x  ,  %d\r\n",checksum, (unsigned int)sizeof(test_sum1));
		while(1);
	}
}
#if 0
====================== 66. 문자열 에서 문자열의 갯수 구하기 ================
char arr[][10] = {
		"111",
		"222",
		"333",
};

int main(void) {
	int i = 0;

	while (arr[i][0] != NULL) i++;

	printf("===> %d\r\n", i); // 어떤 컴파일러에서는 arr[] = { "" } 값만으로도 10 byte 를 점유하기도 한다!!!
	while (1);
	return 0;
}

====================== 65. 무빙 윈도우 (필터없음)   ================
int main(int argc, char *argv[])
{
  int i = 0;
  // a sample array of numbers. The represent "readings" from a sensor over time
  int sample[] = {50, 10, 20, 18, 20, 100, 18, 10, 13, 500, 50, 40, 10};
  // the size of this array represents how many numbers will be used
  // to calculate the average
  int arrNumbers[5] = {0};

  int pos = 0;
  int newAvg = 0;
  long sum = 0;
  int len = sizeof(arrNumbers) / sizeof(int);
  int count = sizeof(sample) / sizeof(int);

  for(i = 0; i < count; i++){
    newAvg = movingAvg(arrNumbers, &sum, pos, len, sample[i]);
    printf("The new average is %d\n", newAvg);
    pos++;
    if (pos >= len){
      pos = 0;
    }
  }
  while(1);
  return 0;
}

====================== 64. ASCII <-> UNICODE 변환   ================
int main( )
{
    CHAR  strChar[10]   = "abcdefghi";
    CHAR  strResult[10] = "";
    WCHAR strWChar[10];

    // MULTIBYTE CODE - > UNICODE
    MultiByteToWideChar(CP_ACP, 0, strChar,  -1, strWChar, 10*2);
    // UNICODE -> MULTIBYTE CODE
    WideCharToMultiByte(CP_ACP, 0, strWChar, -1, strResult,  10, NULL, FALSE);

    Sleep(100000);
	return 0;
}
====================== 63. base64 인코딩과 디코딩 구현  ================

//------ Base64 Encoding Table ------
static const char MimeBase64[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};
//------ Base64 Decoding Table ------
static int DecodeMimeBase64[256] = {
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  // 00-0F
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  // 10-1F
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,63,  // 20-2F
    52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-1,-1,-1,  // 30-3F
    -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,  // 40-4F
    15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,  // 50-5F
    -1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,  // 60-6F
    41,42,43,44,45,46,47,48,49,50,51,-1,-1,-1,-1,-1,  // 70-7F
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  // 80-8F
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  // 90-9F
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  // A0-AF
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  // B0-BF
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  // C0-CF
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  // D0-DF
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  // E0-EF
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1   // F0-FF
    };
int base64_decode(char *text, unsigned char *dst, int numBytes )
{
  const char* cp;
  int space_idx = 0, phase;
  int d, prev_d = 0;
  unsigned char c;
    space_idx = 0;
    phase = 0;
    for ( cp = text; *cp != '\0'; ++cp ) {
        d = DecodeMimeBase64[(int) *cp];
        if ( d != -1 ) {
            switch ( phase ) {
                case 0:
                    ++phase;
                    break;
                case 1:
                    c = ( ( prev_d << 2 ) | ( ( d & 0x30 ) >> 4 ) );
                    if ( space_idx < numBytes )
                        dst[space_idx++] = c;
                    ++phase;
                    break;
                case 2:
                    c = ( ( ( prev_d & 0xf ) << 4 ) | ( ( d & 0x3c ) >> 2 ) );
                    if ( space_idx < numBytes )
                        dst[space_idx++] = c;
                    ++phase;
                    break;
                case 3:
                    c = ( ( ( prev_d & 0x03 ) << 6 ) | d );
                    if ( space_idx < numBytes )
                        dst[space_idx++] = c;
                    phase = 0;
                    break;
            }
            prev_d = d;
        }
    }
    return space_idx;
}
int base64_encode(const char *text, int numBytes, char **encodedText)
{
  unsigned char input[3]  = {0,0,0};
  unsigned char output[4] = {0,0,0,0};
  int   index, i, j, size;
  const char *p, *plen;
  plen           = text + numBytes - 1;
  size           = (4 * (numBytes / 3)) + (numBytes % 3? 4 : 0) + 1;
  (*encodedText) = (char*)malloc(size);
  j              = 0;
    for  (i = 0, p = text;p <= plen; i++, p++) {
        index = i % 3;
        input[index] = *p;
        if (index == 2 || p == plen) {
            output[0] = ((input[0] & 0xFC) >> 2);
            output[1] = ((input[0] & 0x3) << 4) | ((input[1] & 0xF0) >> 4);
            output[2] = ((input[1] & 0xF) << 2) | ((input[2] & 0xC0) >> 6);
            output[3] = (input[2] & 0x3F);
            (*encodedText)[j++] = MimeBase64[output[0]];
            (*encodedText)[j++] = MimeBase64[output[1]];
            (*encodedText)[j++] = index == 0? '=' : MimeBase64[output[2]];
            (*encodedText)[j++] = index <  2? '=' : MimeBase64[output[3]];
            input[0] = input[1] = input[2] = 0;
        }
    }
    (*encodedText)[j] = '\0';
    return size;
}

int _tmain(int argc, _TCHAR* argv[])
{
 const char* plain_text = "테스트Test`1234567890-=\[];',./";
 char* b64encoded_text = NULL;
 printf("plain text\n");
 printf("%s\n\n", plain_text);
 // base 64 인코딩
 // base64_encode(평문을 가리키는 포인터, 평문 길이, b64 인코딩 결과문을 가리키는 포인터)
 // 3번째 인자는 이중 포인터임에 유의해야하며, base64_encode 함수 내부에서 메모리가 할당되므로, 외부에서 꼭 해제 시켜야 한다.
 int len_b64_encoded = base64_encode(plain_text, strlen(plain_text)+1, &b64encoded_text);
 printf("b64 encoded text\n");
 printf("%s\n\n", b64encoded_text);
 // base 64 디코딩
 // 적절한 길이의 메모리 공간을 확보하고
 // 해당 공간에 디코딩된 결과를 받습니다.
 unsigned char *dst = (unsigned char*)malloc(1000);
 int len_b64 = base64_decode(b64encoded_text,dst,1000);
 printf("b64 decoded tex\n");
 printf("%s\n\n", dst);
 if(dst != NULL) free(dst);
 if(b64encoded_text != NULL) free(b64encoded_text);
 getchar();
 return 0;
}



====================== 62. C++에서 IO 방법 std::  ================
int main()
{
    int ch;
    std::cin >> ch;
    std::cout << (char)ch;

	return 0;
}

====================== 61. Endian     ================
int main(void)
{
	#define SWAP16(s)    (((((s) & 0xff) << 8) | (((s) >> 8) & 0xff)))
	#define SWAP32(l)    ( ((((l) & 0xff000000) >> 24) | (((l) & 0x00ff0000) >> 8)  | (((l) & 0x0000ff00) << 8)  | (((l) & 0x000000ff) << 24)))
	#define dSWAP32(l)   ( ((((l) & 0xffff0000) >> 16) | (((l) & 0x0000ffff) << 16)))
	short int t = 0x1234;
	int i = 0xABCD5678;
	while(1)
	{
		printf("0x%4x\r\n0x%4x\r\n\r\n0x%8x\r\n0x%8x\r\n\r\n0x%8x\r\n0x%8x\r\n",t,SWAP16(t), i, SWAP32(i), i, dSWAP32(i));
		Beep( 750, 300 );
		Sleep(100);
	}
	return 0;
}

====================== 60. do while     ================
int main(void)
{
	char i = 0;

	do
	{
		printf("===>\r\n");
		Sleep(1000);
	}
	while(0);

	return 0;
}

====================== 59. 랜덤함수     ================
int main(void)
{
	while(1)
   {
		printf("===> %d\r\n",rand()%9);
		Sleep(1000);
   }
	return 0;
}

====================== 58. 문자열 연결 함수 strcat      ================
int main(void)
{
	char str[] = {"abc0967"};
	char ptr[] = {"AAA"};
	const char * p[] = {"BBB"};

  	while(1)
   {
		strcat(str,ptr);
		strcat(str,*p);
		printf("%s\r\n",str);
		Sleep(1000);
   }

}

====================== 57. 포인터를 이용해 문자열 바꿔치기 ================
unsigned char get_system_inform(char *system_inform)
{
	char sys_inform[50]={0,};
    sprintf(sys_inform,"%f\r\n%s\r\n", 	12.5,			// 밧데리
    									"wrms-1000"		// 버젼
			);
	strcpy(system_inform,sys_inform); ///<
    if(strlen(system_inform)){
        return 0;
    }
    else{
        return 1;
    }
}

int main(void)
{
	char bbb[50] = "123456789";

	while(1)
	{
		get_system_inform(bbb);
		printf("%s\r\n",bbb);// 짝수 일경우 2.5
		Sleep(1000);
	}
}


====================== 56.  문자열 검색시 null 값이 섞여 있을때   ========================
#define MAX_BUF_SIZE	128
int main()
{
	const char str[] = {0x5b,0x5b,0x00,0x24,0x43,0x30,0x44,0x52,0x5b,0x5b,0x5b,0x5b,0x5b};
	const char * p = "$C0D";
	int ix;


   if(!strstr(str,p))
   {
   		for(ix=0; ix<MAX_BUF_SIZE; ix++)
   		{
   			if(str[ix] == 0x00)
   				break;
   		}
   		printf("====>1%s\r\n",strstr(&str[ix+1],p));
	}
   	else
	   printf("====>2%s\r\n",strstr(str,p));

   while(1);

    return 0;
}
====================== 55. CheckSumCalculator   ========================
char CheckSumCalculator(char type, int size, char * p)
{
	char i, rtn = 0;

	switch(type)
{
	case 0:
	for(i = 0; i<size; i++)
{
	rtn ^= (char)p[i];
}
	break;
	case 1:
	break;
	default:
	break;
}
	return rtn;
}

int main(void)
{
	char data[] = {0x43,0x30,0x44,0x52,0x00,0x1B};

	printf("CheckSum = 0x%x\r\n",CheckSumCalculator(0,sizeof(data),data));// 짝수 일경우 2.5

	return 0;
}

====================== 54. Median 필터   ===============================

float CalMedianAvg(int samples, float sourceValue[]) {
	float temp;
	float values[32];
	int i, j;

	for (i = 0; i < samples; i++)
	values[i] = sourceValue[i];

// the following two loops sort the array x in ascending order
	for (i = 0; i < samples - 1; i++) {
	for (j = i + 1; j < samples; j++) {
	if (values[j] < values[i]) {
// swap elements
	temp = values[i];
	values[i] = values[j];
	values[j] = temp;
}
}
}

	if (samples % 2 == 0) {
// if there is an even number of elements, return mean of the two elements in the middle
	return ((values[samples / 2] + values[samples / 2 - 1]) / 2.0);
} else {
// else return the element in the middle
	return values[samples / 2];
}
}

int main(void)
{
	float rtn=0;
//float p[5] = {0,4,1,2,3};// 홀수일 경우
	float p[6] = {2,1,5,0,3,4};// 짝수일 경우

  while(1)
  {


//printf("%f\r\n",CalMedianAvg(5,p));// 홀수 일경우 2.0
	printf("%f\r\n",CalMedianAvg(6,p));// 짝수 일경우 2.5
	Sleep(500);
  }
}


====================== 53. CIB 유량계산 프로토타입   ===============================

typedef enum
{
//  유량 연산방식
	FlowCalcMclavisMoment = 0,
	FlowCalcMclavisAccum,
	FlowCalcManning,
	FlowCalcPolynomal,

// 개수로 타입
	ShapeRectangular = 0,///< 국내 현장에서 실제 사용될 타입
	ShapeTrapezoidal,
	ShapeTriangular,
	ShapeCircular,///< KTL 시험용
	ShapeParabolic,

}FlowCalc_t;

typedef struct
{
	double		total_flow;///< 적산유량, 시스템 리셋이 걸려도 적산값 저장

	float		gzf;///< 수위가 있으나 유속이 0 m/s 인 경우의 수위 값
	unsigned char 	estimate_type;///< 유량계산 방식( 0=유속센서_순간유량, 1=유속센서_누적유량, 2=매닝,  3=다항식 )
	unsigned char 	asign;///< 디지털 센서로 들어오는 측정 아이템중 유량으로 계산할 아이템 번호 선택 ( 물리센서포트 , 채널번호 )
	float		asperity;///< 조도계수( 수로 단면의 거칠기 )
	float		width;///< 수로폭
	float		slope;///< 수로 경사도

	float		r;///< 원형관경
	int		UnitConv;///< 단위변환값
	int		channel_type;///< 원형, 사각, V

	float		qr1;///< 시간당최저유량
	float		qr2;///< 시간당최고유량

	float		V1;///< 최저유속
	float		V2;///< 최고유속
	float		h1;///< 최저수위
	float		h2;///< 최고수위

	double		b;  ///< 유량옵셋값
	double		a; ///< 유량보정계수
}__attribute__((packed)) FLOWMETA_T;

static FLOWMETA_T gst_meta =
{
	0.12,// total_flow

	0.0,                                     // gzf
// estimate_type( 0=FlowCalcMclavisMoment, 1=FlowCalcMclavisAccum, 2=FlowCalcManning, 3=FlowCalcPolynomal )
	FlowCalcMclavisMoment,
	1,// asign

	0.2,// asperity
	0.15,// width
	1,                                      // slope

	0.15,                                   // 관경

	3600,                                   // 단위변환값
	ShapeCircular,                // 원형, 사각, V

	15.0/3600,                                     // 시간당최저유량
	25.0/3600,                                     // 시간당최고유량
	0.213,                                  // 최저유속
	0.277,                                  // 최고유속
	0.0963,                                 // 최저수위
	0.1155,                                 // 최고수위

	0,                                      // 유량옵셋값
	0.85	// 유량보정계수
};

static float GetY(float x1, float y1, float x2, float y2, float xvalue);
static float SegmentAreaCalc(float r_radius, float h_level);
static float FlowGetArea(float level);







// 4~20mA 캘리브리에션 함수
static float GetY(float x1, float y1, float x2, float y2, float xvalue)
{
	float yvalue;

	if(y2 >= y1)
	yvalue = ((y2-y1)/(x2-x1))*(xvalue-x1)+y1;
	else if(y2 < y1)
	yvalue = ((y1-y2)/(x1-x2))*(xvalue-x2)+y2;

	return yvalue;
}

// 활꼴의 면적 구하기
static float SegmentAreaCalc(float r_radius, float h_level)
{
	float c,e,l;
	float s = 0.0;
	int mode = 0;

	if(h_level > r_radius) {
	mode = 1;
//h_level = 2 * r_radius - h_level;
	h_level = h_level - r_radius;
}

// c값
	c = 2.0*sqrt( (2.0*r_radius*h_level) - pow(h_level,2) );

// angle값
//e = 180.0*c/(M_PI*r_radius);
	e = 2.0*asin(c/(2.0*r_radius));

// l값
//l = (M_PI*r_radius*e)/180.0;
	l = r_radius*e;

// A 면적값
	s = ((r_radius*l)-(c*(r_radius-h_level)))/2.0;

	if(mode==1){
	s = M_PI * r_radius * r_radius - s;
}

//printf("\r\n===> %f  %f	%f	%f",c,e,l,A_area);
	return s;
}

static float FlowGetArea(float level)
{
	float s = 0.0;

	switch(gst_meta.channel_type)
{
	case ShapeRectangular:
// 8 . 현재유량면적- 현재수위에 따라 계산된 유량 면적
	if(level > gst_meta.gzf)
	s = gst_meta.width * level;
	break;
	case ShapeTrapezoidal:
	break;
	case ShapeTriangular:
	break;

	case ShapeCircular:
// 8 . 현재유량면적- 현재수위에 따라 계산된 유량 면적
	s = SegmentAreaCalc(gst_meta.r, level);
	break;

	case ShapeParabolic:
	break;
	default:
	break;
}

	return s;
}




void FlowSetChannel_Rectangular(float value)
{
	gst_meta.channel_type = ShapeRectangular;
	gst_meta.width = value;
	gst_meta.r = value;
}

void FlowSetChannel_Circular(float value)
{
	gst_meta.channel_type = ShapeCircular;
	gst_meta.r = value;
}

void FlowSetRefrence(int type, float level, double veloc, double flow)
{
	if(type == 1){
	gst_meta.h1 = 	level;
	gst_meta.V1 = veloc;
	gst_meta.qr1 = flow;
}
	else if(type == 2){
	gst_meta.h2 = 	level;
	gst_meta.V2 = veloc;
	gst_meta.qr2 = flow;
}
}

void FlowCalibration(void)
{
	float s1;
	float s2;
	float qt1, qt2;
	float qr1, qr2;

	s1 = FlowGetArea(gst_meta.h1);
	s2 = FlowGetArea(gst_meta.h2);

	qt1 = s1 * gst_meta.V1;
	qt2 = s2 * gst_meta.V2;

	qr1 = gst_meta.qr1;
	qr2 = gst_meta.qr2;

	gst_meta.a = (qr2 - qr1) / (qt2 - qt1);

	gst_meta.b = gst_meta.qr1 - (gst_meta.a * s1 * gst_meta.V1);
//printf("===> %f	%f	%f	%f	%f	%f      %f      %f\r\n",s1,s2,qt1,qt2,qr1,qr2,gst_meta.a,gst_meta.b);
}


void FlowDoCalibration(void)
{
#if 1
	FlowSetRefrence(1, 0.0963, 0.213, 15.0 / gst_meta.UnitConv);
	FlowSetRefrence(2, 0.1155, 0.277, 25.0 / gst_meta.UnitConv);
//FlowSetRefrence(2, 0.1155, 0.277, 25.0 / gst_meta.UnitConv);
#else
	FlowSetRefrence(1, 0.0963, 0.213, 15.0 / gst_meta.UnitConv);
	FlowSetRefrence(2, 0.1855, 0.277, 25.0 / gst_meta.UnitConv);
#endif
	FlowCalibration();
}


float DoMeasure(char format, float level, float veloc)
{
	float Qx;
	float va;
	float s;

	s = FlowGetArea(level);
	va = s * veloc;
	Qx = gst_meta.a * va  + gst_meta.b;

	if(format)
	Qx = Qx * gst_meta.UnitConv;
    if(Qx < 0)
        Qx = 0.0;

	printf("%f %f %f %f %f\r\n", level, veloc, s, va, Qx);

	return Qx;
}





int main(void)
{
	float rtn=0;


	rtn = GetY(0,15, 1, 25,0);   // ex)  최소값 4mA일때 0미터  최대값 8mA일때 2미터인 개도계 , 만약 6mA가 입력된다면 1미터여야 한다.


	FlowSetChannel_Circular(0.15);
	FlowDoCalibration();


	float h_step, v_step, h, v;
	int ix;

	h_step = (gst_meta.h2  - gst_meta.h1) / 10;
	v_step = (gst_meta.V2  - gst_meta.V1) / 10;
	for(ix=0; ix<=10; ix++) {
	h= gst_meta.h1 + h_step*ix;
	v= gst_meta.V1 + v_step*ix;
	DoMeasure(1, h, v);
//printf("%f %f %f\r\n", h, v, DoMeasure(1, h, v));
}

//printf("%f %f %f\r\n", 0.098, 0.0, DoMeasure(1, 0.098, 0.0));
//printf("%f\r\n",FlowCorrection(1,0.0963,0.213));
//printf("%f\r\n",FlowCorrection(1,0.1155,0.277));

	return rtn;
}

// 52. Segment (활꼴 면적 구하기)
==================================================================================================
    FUNCTION: Segment (활꼴 면적 구하기)

    DESCRIPTION:
-자동유량계가 비만관 원형 파이프에서 유량 단면적 계산시 사용

    IMPORTANT NOTES:
	input
	r_radius	:파이프 관경[m]
	h_level	: 수위 [m]

	return
	A_area	:유량계산시 사용될 단면적 [m^2]
==================================================================================================
float SegmentAreaCalc(float r_radius, float h_level)
{
	float c,e,l;
	float A_area = 0;

// c값
	c = 2*sqrt((2*r_radius*h_level)-pow(h_level,2));
// angle값
	e = (180*c)/(M_PI*r_radius);
// l값
	l = (M_PI*r_radius*e)/180;
// A 면적값
	A_area = ((r_radius*l)-(c*(r_radius-h_level)))/2;

	printf("\r\n===> %f  %f	%f	%f",c,e,l,A_area);
	return A_area;
}


int main()
{
	SegmentAreaCalc(5,0.17);
	Sleep(1000);

	return 0;
}

==================================================================================================
    FUNCTION: PrefixUnit

    DESCRIPTION:
-SMS 나 LCD에 누적량과 같은 값을 9999.999 자릿수 이내로 표현하기 위한 함수
-EX) 253012000 m3의 경우 235.012 k.m3 와 같이 표시 한다.

    IMPORTANT NOTES:
Multiples          	Prefix name                  deca     hecto    kilo      mega    giga     tera      peta     exa       zetta           yotta
                    Prefix symbol                da        h         k         M        G         T         P         E         Z           Y
                    Factor              10^0     10^1     10^2     10^3     10^6     10^9     10^12   	10^15   10^18   	10^21       10^24

Submultiples      	Prefix name               	deci       centi     milli      micro    nano    pico      femto    atto      zepto      yocto
                    Prefix symbol                d         c         m        μ         n         p         f          a         z         	y
                    Factor              10^0     10^-1   10^-2   	10^-3   10^-6   	10^-9   10^-12 	10^-15 	10^-18 	10^-21    10^-24


==================================================================================================
const char * PrefixUnit(double * val)
{
	const char * strPrefixUnit[] = {"k.","M.","G.","T."};
	const char * rtn;
	char cue = 0;
	float limit = 9999.999;
	float div = 1000;

	if(*val >= limit)
{*val /= div;	cue = 0;}
	if(*val >= limit)
{*val /= div;	cue = 1;}
	if(*val >= limit)
{*val /= div;	cue = 2;}
	if(*val >= limit)
{*val /= div;	cue = 3;}
	if(*val >= limit)
{
	printf("\r\nUnexpect Case in %s.",__FUNCTION__);
*val = limit;
}
	rtn = strPrefixUnit[cue];
	return rtn;
}

int main()
{
	double in = 9665554443332.123;
	double * disp_val;
	const char * prefix_unit;

*disp_val = in;
	prefix_unit = PrefixUnit(disp_val);
	printf("\r\n===> %f [%s%s]",*disp_val,prefix_unit,"m^3");
	Sleep(1000);

	return 0;
}


====================== 50. 문자열 토큰 처리
int main()
{
	char s[] = "My.Name is - Yang Ju,Jong";
	char * tok;

	printf("%s\r\n",s);
	tok = strtok(s," ,.-");
   while(tok != NULL)
    {
	Sleep(100);
   	printf("%s\r\n",tok);
	tok = strtok(NULL," ,.-");
    }

    return 0;
}

====================== 49. 인자로 받은 정수값을 포인터를 이용해 바꾸기
void * aaa(int * i, int * b)
{
*i += 1;
//	c = *b;
//*i = c * (*b);
*i *= *b;
}
int main()
{

	int i = 0 , b = 1;

   while(1)
    {
	Sleep(100);

	aaa((int *)&i,(int *)&b);
   	printf("====>%d\r\n",i);
    }

    return 0;
}

====================== 48. 2중 포인터 ===============================
void RcvMax3100(char ** q)
{
	char * pro = "abcdefg";
*q = pro;
}

int main()
{
	unsigned char rx_data[255]={"xxx"};
	char * p ="zzz";

   RcvMax3100(&p);
   printf("====>%s\r\n",p);
   Sleep(100);

   memcpy(rx_data,p,strlen(p));
   printf("====>%s\r\n",rx_data);

   while(1);

    return 0;
}

====================== 47. 2진수로 출력 ===============================

int main() {
   int i = 0,a = 0;
   int refer = 0x00000000;
   int input = 128;

    i = refer ^ input;
   printf("====>0x%x\r\n",i);
   for(a=(sizeof(int)*8);  a!=0; a--)
   {
   	if(i&(0x01<<a)) printf("1");
	else printf("0");
   }


   while(1);

    return 0;
}


====================== 46. XOR 연산 (두 값중 변화된 비트만 검출 ) ===============================
int main()
{
   int i = 0;
   int refer = 0x00110000;
   int input = 0x10110010;

   i = refer ^ input;
   printf("====>0x%x",i);

   while(1);

    return 0;
}

====================== 45. 비트 마스크 2 (bit mask) ============================================
    AUTHOR : 서기대
    DESCRIPTION	:시스템 상태를 각 비트에 담아 정보 처리에 활용 (DKB로 전달할때 활용)
    DATE	: 	2018-01-22
    PRECONDITION:없음
Input
[Name][Default][Range][Usage]
 	cmd		bOK	해당 기능 정상으로 기록
 	bErr	해당 기능 에러로 기록
 	bChk	해당 기능  상태 확인
 	bit		bSD		bSD ~ bEnd	상태 모니터링할 전체 항목 중 하나
 *rtn_value		0x01 ~ 0xFFFFFFFF	리턴값의 포인터 주소반환
 	shift		0		0~1	리턴값을 좌우로 시프트 시킬때 사용
Output
	Err		Err
	OK

    IMPORTANT NOTES:
        ---
==================================================================================================
typedef enum
{
	bOK	= 0,
	bErr,
	bChk,
	bMask	= 1,
	bInit = 0,
	bSD = 0,
	bSD_OP,
	bSIB,
	bIOB,
	bModemLocCmd,
// 여기에 상태 모니터링할 항목 추가
	bEnd	= 31
}BITS_SEQ;

int BitsOperate(char cmd, int bit,int * rtn_value, int in_value)
{
    char i;
	int rtn = 0;

   	if(cmd == bOK) 	in_value |=  (bMask<<bit); // OK 기록
   	else if(cmd == bErr) 	in_value &= ~(bMask<<bit);// ERROR 기록
   	else	// 상태 조회
{
	if(bit<32 && (in_value&(0x1 << bit)))rtn = 1;
	else rtn = 0;
}
    for(i=(sizeof(unsigned int)*8)-1; i>=0; i--)
    {
  (in_value&(1u<<i))?putchar('1'):putchar('0');
}
//in_value&(1u<<i);
*rtn_value = in_value;
    printf("\n");
    return rtn;
}

int main()
{
    int BootSeq = 0x0, shift = 0;// shift 값을 바꾸면 전체적으로한 비트씩 밀린다.
    int * value;


     printf("====>%d\r\n",BootSeq);
	shift = BitsOperate(bOK, 0, value, BootSeq >> shift);
   printf("====>%d   %d",*value,bModemLocCmd);


   while(1);

    return 0;
}

====================== 44. 비트 마스크 1 (bit mask) ============================================

//선언
int btchk(int orig, int target);
int bton(int orig, int target);
int btoff(int orig, int target);
int bttrn(int orig, int target);
void printb(int bit);
int main();

int main(){//메인
	int a,b;
	printf("정수를 입력해주세요.");
	scanf("%d",&a);
	printf("\n원본\n");
	printb(a);
	printf("\n몇번째에 있는 스위치를 확인할까요?");
	scanf("%d",&b);
	if(btchk(a,b) == 1)printf("\n켜져있습니다\n");
	else printf("\n꺼져있습니다.\n");
	printf("몇번째에 있는 스위치를 켤까요?");
	scanf("%d",&b);
	a = bton(a,b);
	printf("\n결과\n");
	printb(a);
	printf("\n몇번째에 있는 스위치를 끌까요?");
	scanf("%d",&b);
	a = btoff(a,b);
	printf("\n결과\n");
	printb(a);
	printf("\n몇번째에 있는 스위치의 상태를 변경할까요?");
	scanf("%d",&b);
	a = bttrn(a,b);
	printf("\n결과\n");
	printb(a);
	printf("\n");
	system("PAUSE");
}

int btchk(int orig, int target){//비트 체크(on되있으면 true 반환)
	if(target<32 && (orig&(0x1 << target)))return 1;
	else return 0;
}

int bton(int orig, int target){ //비트 온
	if(target<32)return orig|(0x1 << target);
	else return orig;
}

int btoff(int orig, int target){//비트 오프
	if(target<32)return orig&(~(0x1 << target));
	else return orig;
}

int bttrn(int orig, int target){//비트 스위치
	if(target<32)return orig^(0x1 << target);
	else return orig;
}

void printb(int bit){//32비트형 2진수 출력
	int i, j = 8 * sizeof(bit), bit_level = 0x1 << (8 * sizeof(bit) - 1);

	for(i = 0; i < j; ++i){
	if((i%4) == 0)printf(" ");//단위자르기
	if(bit & bit_level)printf("1");
	else printf("0");
	bit = bit << 1;
}
}

====================== 43. 함수 리턴값을 인자로 받기 ============================================

void BitsOperate(char cmd, unsigned int * rtn_value, unsigned int shift)
{
    char i;


    for(i=(sizeof(unsigned int)*8)-1; i>=0; i--)
    {
  (shift&(1u<<i))?putchar('1'):putchar('0');
  //shift&(1u<<i);
}
    *rtn_value = shift;

    printf("\n");
}

int main()
{
    unsigned int BootSeq = 72, shift = 1;// shift 값을 바꾸면 한 비트씩 밀린다.
    unsigned int * value;


     printf("====>%d\r\n",BootSeq);
	BitsOperate(0, value, BootSeq >> shift);
   printf("====>%d",*value);


   while(1);




    return 0;
}



====================== 42. 시간갱신 코드 .===================

typedef struct
{
	short int year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char min;
	unsigned char sec;
}Date;

void gotoxy(int x, int y){
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main(void)

{
	time_t rawtime;
   	struct tm *info;
   	struct tm gtime;
   	char buffer[17]={0,};// 00/00/00 00:00:00  월/일/년 시:분:초
   	Date date ={0,};
   	char * token;

	while(1)
{
	gotoxy(2,4);
	time( &rawtime );
   	info = localtime( &rawtime );

   	strftime(buffer,80,"%c", info);// 시간을 버퍼에 문자열로 저장할때 사용  참조 http://blog.naver.com/sycho019/20099857191

   	date.year = atoi(&buffer[6])+2000;// 시간을 구조체에 값으로 저장할때 사용
   	date.month = atoi(&buffer[0]);
   	date.day = atoi(&buffer[3]);
   	date.hour = atoi(&buffer[9]);
   	date.min = atoi(&buffer[12]);
   	date.sec = atoi(&buffer[15]);

	printf("%s      /       %04d-%02d-%02d %02d:%02d:%02d\r\n", buffer, date.year,date.month,date.day,date.hour,date.min,info->tm_sec);// 포인터의 -> 를 활용해 바로 써도 된다.

	Sleep(1000);
}
	return 0;
}


====================== 41. 문자열 포인터에서 문자열의 갯수 구하기 .===================

const char * arr[] = {"봉화배수장 흡입	4423040002 	1 	442304000201	WRMS	2016-08-22	012-2015-0012",
"봉화배수장 토출	4423040002 	2 	442304000202	WRMS	2016-08-23	012-2006-0971",
"사포배수장 흡입	4423040016 	1 	442304001601	WRMS	2016-08-23	012-2017-0873",
"사포배수장 토출	4423040016 	2 	442304001602	WRMS	2016-08-23	012-2005-0971",
"장구2배수장 흡입	4423040019 	1 	442304001901	WRMS	2016-08-23	012-2013-0873",
};

int main(void)
{
	int i = 0;

	while(arr[i]!=NULL){
	i++;
}

	printf("===> %d\r\n",i);// 어떤 컴파일러에서는 arr[] = { "" } 값만으로도 10 byte 를 점유하기도 한다!!!

	while(1);
	return 0;
}

====================== 40. 구조체의 컨텐츠 갯수 구하기 .====================
typedef struct {
	char *	name;
	char *	value;
	char *	id;
	char *	pass;
	unsigned int ops;
}__attribute__((packed))	APN_PARM_ADD;

 int main(void)
 {
 APN_PARM_ADD  apn_parm_add[9];
 while(1)
 {
 Sleep(1000);
 printf("%d\r\n",sizeof(apn_parm_add)/sizeof(APN_PARM_ADD));
 }
 return 0;
 }

====================== 39. HexToBinPrint 함수 .===============================
// 주의 ! 반드시 hex값으로만 넣을것! 문자입력시 아스키코드상에 0x20 ~ 반영필요
void HexToBin(char * buf, char * in)
{
	int i;
	int len = strlen(in)*7;

	for(i=len; i>=0; i--)
{
	if((int)in[i]&(0x01<<i)) buf[len-i] = '1';
	else buf[len-i] = '0';
}
}

int main(void)
{
	char arry[30]={0,};

   while(1)
   {

	HexToBin(arry,arry);
	printf("%s\r\n",arry);
	Sleep(1000);
   }


}



====================== 38. Integer To Float 함수 .===============================

int main(void)
{
	char buf [33];
	unsigned char adc_code;
	int value = 12050;
	float volt = 0;

	while(1)
{
	Sleep(1000);
// itoa(value,buf,10);
	sprintf(buf,"%d",value);
	volt = atof(buf)*0.001;

	printf("%f\r\n",volt);

    }
	return 0;
}






========================37 . 바이너리로 출력  ============

int main(void)
{
	unsigned char w_data[10]={1,};
	char buffer [33];
	unsigned char adc_code;


	while(1)
{

	Sleep(1000);

	w_data[0] = w_data[0]<<1;
	itoa ( w_data[0],buffer,2);
	printf("%08s\r\n",buffer);


    }
	return 0;
}



=====================36 . 폰트(arry) 90도 회전   ============

void displayMatrix(unsigned int const *p, unsigned int r, unsigned int c)
{
    unsigned int row, col;
    printf("\n\n");

    for(row = 0; row < r; row++)
    {
        for(col = 0; col < c; col++)
        {
            //printf("%d\t *(p + row * c + col));
        }
        printf("\n");
    }

    printf("\n\n");
}

void rotate(unsigned int *pS, unsigned int *pD, unsigned int row, unsigned int col)
{
    unsigned int r, c;
    for(r = 0; r < row; r++)
    {
        for(c = 0; c < col; c++)
        {
            *(pD + c * row + (row - r - 1)) = *(pS + r * col + c);
        }
    }
}

int main()
{
    // declarations
    unsigned int image[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    unsigned int *pSource;
    unsigned int *pDestination;
    unsigned int m, n;

    // setting initial values and memory allocation
    m = 3, n = 4, pSource = (unsigned int *)image;
    pDestination = (unsigned int *)malloc(sizeof(int)*m*n);

    // process each buffer
    displayMatrix(pSource, m, n);

    rotate(pSource, pDestination, m, n);

    displayMatrix(pDestination, n, m);

    free(pDestination);

    getchar();
    return 0;
}



=====================35 . 시리얼 포트로 데이터 출력   ============

void PrintCommState(DCB dcb)
{
    //  Print some of the DCB structure values
    _tprintf( TEXT("\nBaudRate = %d, ByteSize = %d, Parity = %d, StopBits = %d\n"),
              dcb.BaudRate,
              dcb.ByteSize,
              dcb.Parity,
              dcb.StopBits );
}


int _tmain( int argc, TCHAR *argv[] )
{
   DCB dcb;
   HANDLE hCom;
   BOOL fSuccess;
   TCHAR *pcCommPort = TEXT("COM5"); //  Most systems have a COM1 port

   //  Open a handle to the specified com port.
   hCom = CreateFile( pcCommPort,
                      GENERIC_READ | GENERIC_WRITE,
                      0,      //  must be opened with exclusive-access
                      NULL,   //  default security attributes
                      OPEN_EXISTING, //  must use OPEN_EXISTING
                      0,      //  not overlapped I/O
                      NULL ); //  hTemplate must be NULL for comm devices

   if (hCom == INVALID_HANDLE_VALUE)
   {
       //  Handle the error.
       printf ("CreateFile failed with error %d.\n", GetLastError());
       return (1);
   }

   //  Initialize the DCB structure.
   SecureZeroMemory(&dcb, sizeof(DCB));
   dcb.DCBlength = sizeof(DCB);

   //  Build on the current configuration by first retrieving all current
   //  settings.
   fSuccess = GetCommState(hCom, &dcb);

   if (!fSuccess)
   {
      //  Handle the error.
      printf ("GetCommState failed with error %d.\n", GetLastError());
      return (2);
   }

   PrintCommState(dcb);       //  Output to console

   //  Fill in some DCB values and set the com state:
   //  57,600 bps, 8 data bits, no parity, and 1 stop bit.
   dcb.BaudRate = CBR_57600;     //  baud rate
   dcb.ByteSize = 8;             //  data size, xmit and rcv
   dcb.Parity   = NOPARITY;      //  parity bit
   dcb.StopBits = ONESTOPBIT;    //  stop bit

   fSuccess = SetCommState(hCom, &dcb);

   if (!fSuccess)
   {
      //  Handle the error.
      printf ("SetCommState failed with error %d.\n", GetLastError());
      return (3);
   }

   //  Get the comm config again.
   fSuccess = GetCommState(hCom, &dcb);

   if (!fSuccess)
   {
      //  Handle the error.
      printf ("GetCommState failed with error %d.\n", GetLastError());
      return (2);
   }

   PrintCommState(dcb);       //  Output to console

   _tprintf (TEXT("Serial port %s successfully reconfigured.\n"), pcCommPort);

   while(1)
   {
   	Sleep(1000);
   	_tprintf (TEXT("Serial port %s successfully reconfigured.\n"), pcCommPort);

   }
   return (0);

}

//=====================34 . 4~20mA 계산과정함수  ============
/**
 *@brief	두점을 지나는 직선에서 x의 값이 value일 때 y의 값을 구한다.
 *@brief	전류보정 및 4~20mA 입력을 설정된 단위로 변환
 *@param	adc_set	ADC 설정값
 *@param	x1	점1의 x좌표
 *@param	y1	점1의 y좌표
 *@param	x2	점2의 x좌표
 *@param	y2	점2의 y좌표
 *@param	xvalue	4~20mA 측정되는 입력전류값
 *@return	xvalue 에 대한 y값
 */
/*
float GetY(float x1, float y1, float x2, float y2, float xvalue)
{
float yvalue;

if(y2 >= y1)
	yvalue = ((y2-y1)/(x2-x1))*(xvalue-x1)+y1;
else if(y2 < y1)
	yvalue = ((y1-y2)/(x1-x2))*(xvalue-x2)+y2;

return yvalue;
}

int main(void)
{
float rtn=0;

  while(1)
  {
	rtn = GetY(4,0,20,2,7);   // ex)  최소값 4mA일때 0미터  최대값 8mA일때 2미터인 개도계 , 만약 6mA가 입력된다면 1미터여야 한다.
	rtn = rtn * (16/3);

	printf("%f\r\nrtn);
	Sleep(500);
  }
}

=====================33 . scanf  ============
int main(void)
{
  char i = 0;
  char buf[10] = {0,};


  while(1)
  {
	scanf("%sbuf);
	printf("%s\r\nbuf);
	Sleep(1000);
  }
}

=====================32 . 이중포인터 or 다중포인터  ============
int main(void)
{
  char i = 3;
  char * p = &i;
  char ** p1 = &p;
  char *** p2 = &p1;

  while(1)
  {
	printf("%d\r\n",***p2 = **p1+1);
	Sleep(1000);
  }
}

=====================31 . 함수인자로 포인터사용  ============
void fun(char * a){*a += 1;}

int main(void)
{
  char val=3;

  while(1)
  {

	printf("%d\r\nval);
	Sleep(1000);
	fun(&val);
  }
}

=====================30 . 매닝공식 계산과정  ============
double value;
float gzf;
double n,A,R,S,eR,eS;
double fun[5] = {0,2.0,0.0016667,};
float level = 1.25;


int main(void)
{
n = 0.015;
A = level*fun[1];
   R = level*fun[1]/(2*level+fun[1]);
   S = fun[2];
   eR = 2.0/3.0;
   eS = 1.0/2.0;
   value = 1/n*A*pow(R,eR)*pow(S,eS);

while(1)
  {


Sleep(1000);
  }
}

=====================29 . itoa ============

int main(void)
{

char str[20] = {0,};
float value =25000;

while(1)
  {
itoa( value, str, 10 ); //10진 문자열로 변환
printf("%s\r\nstr);

Sleep(1000);
  }
}

=====================28 . ASC TO HEX 로 변환 ============

// Input =  0x31 0x32 0x33 0x34     Output = 1234
unsigned char * Ascii2Hex(unsigned char *Data, unsigned int length)
{
unsigned int i=0, a=0;
unsigned char wizfi_buf[256] = {0,};
unsigned char high,low;
unsigned char constant = 87; // 실수값에 '0'~'9'를 제외한 아스키코드값이 들어올경우 hex처리
unsigned char Alpa = 55; // 실수값에 '0'~'9'를 제외한 아스키코드값이 들어올경우 hex처리

	for(i=0; i<length; i++)
{
// 상위 니블
	if(Data[i] >= '0' && Data[i] <= '9') high = (Data[i] & 0x0F) << 4;
	else if(Data[i] >= 'A' && Data[i] <= 'Z') high = (Data[i]-Alpa) << 4;
	else high =  (Data[i]-constant) << 4;
// 하위 니블
	if(Data[i+1] >= '0' && Data[i+1] <= '9') low =  (Data[i+1] & 0x0F);
	else if(Data[i+1] >= 'A' && Data[i+1] <= 'Z') low = Data[i+1]-Alpa;
	else low = Data[i+1]-constant;

	wizfi_buf[a] = high+low;

	a++;
	i++;

}
//wizfi_buf[0] = 0x41;
	wizfi_buf[a] = Data[i];
//wizfi_buf[length/2] = 0x44;
return wizfi_buf;
}




int main(void)
{

unsigned char rs232_buf[128] ={0x30,0x64,0x34,0x34,0x61,0x35,0x65,0x33,0x35,0x34,0x62,0x62,0x31,0x63,0x30,0x34,0x30,0x44};
unsigned char buf[256] = {0,};
unsigned short int i = 0, a = 0;



  while(1)
   {
	memcpy(buf,Ascii2Hex(rs232_buf,strlen(rs232_buf)),strlen(rs232_buf));
	for(i=0; i<strlen(rs232_buf); i++) printf("%02xbuf[i]);
	printf("\r\n");
	Sleep(5000);
   }
}



=====================27 . itoa    ============

// Input = 0x12345678    Oupput = 0x31 0x32 0x33......
int main(void)
{

unsigned char rs232_buf[128] ={0x0a,0x30,0x32,0x30,0x30,0x31,0x38,0x34,0x34,0x30,0x62,0x31,0x63,0x32,0x38};
unsigned char buf[256] = {0x30,0x62,};
unsigned short int i = 0, a = 0, len = 0;
unsigned char str[5] = {0,};

int  nInt  = 1234567890;
char buffer[100];



sprintf(str,"%c%cbuf[0],buf[1]);

itoa( nInt, buffer, 10 ); //10진 문자열로 변환



  while(1)
   {

	Sleep(5000);
   }
}



//=====================26 . ASC TO HEX 로 변환 ============

 Input = "03010000000416"   Output =30333031 ...
unsigned char * Ascii2Hex(unsigned char *Data, unsigned int length)
{
unsigned int i=0, a=0;
unsigned char wizfi_buf[256] = {""};
unsigned char high,low;

	for(i=0; i<length; i++)
{
	high = ((Data[i] & 0xF0));
	low =  (Data[i] & 0x0F);

	wizfi_buf[i] = high+low;

}
return wizfi_buf;
}


int main(void)
{

unsigned char rs232_buf[128] ={"0a303130303030303030340d"};
unsigned char buf[256] = {0,};
unsigned short int i = 0, a = 0;

  while(1)
   {
	memcpy(buf,Ascii2Hex(rs232_buf,strlen(rs232_buf)),strlen(rs232_buf));
	for(i=0; i<strlen(rs232_buf); i++) printf("%02xbuf[i]);
	printf("\r\n");
	Sleep(5000);
   }
}

=====================25 . ASC TO HEX 로 변환 ============

unsigned char Conv(unsigned char Data)
{

	if( (0x00 <= Data) && (Data<= 0x09) )
{
	Data+= 0x30;
	return Data;
}
	else if((0x0a<= Data) && (Data<= 0x0f))
{
	Data += 55 ;
	return Data;
}
	else if((0x0A<= Data) && (Data<= 0x0F))
{
 Data += 55 ;
	return Data;
}
   return 0;
}

unsigned char * AscToHex(unsigned char *Data, unsigned int length)
{
unsigned int i=0, a=0;
unsigned char wizfi_buf[256] = {""};
unsigned char high,low;

	for(i=0; i<length*2; i++)
{
	high = ((Data[a] & 0xF0) >> 4);
	low =  (Data[a] & 0x0F);
	wizfi_buf[i] = Conv(high); // 상위비트검사
	wizfi_buf[i+1] = Conv(low); // 하위비트검사
	i++;
	a++;
}
return wizfi_buf;
}


int main(void)
{

unsigned char rs232_buf[128] ={0xB4,0x23,0x0a,0x56};
unsigned char buf[256] = {0,};
unsigned short int i = 0, a = 0;



  while(1)
   {

	memcpy(buf,AscToHex(rs232_buf,4),10);

	printf("%sbuf);
	printf("\r\n");

	Sleep(5000);
   }
}



=====================24 . sprintf함수를 이용해 Hex <-> Ascii 변환 ============

int main(void)
{
char ascii[128] = {"ABC"};
char hex[128] ={0x30,0x33,0x31,0x36,};
char buf[10] = {0,};
int i;
// Ascii -> Hex
sprintf(buf,"%02x%02x%02xascii[0],ascii[1],ascii[2]);
printf("Ascii -> Hex : %s buf);
printf("\r\n");
// Hex -> Ascii
sprintf(buf,"%shex);
printf("Hex -> Ascii : %s buf);
while(1)
  {

  }
}

// Sleep(1000);	1초 딜레이 함수
// printf("%s\r\nbuffer.buf);디버깅할때 사용

=====================23 . %연산자 동작시험 ============

int main(void)
{
	unsigned char a=0, i = 0;

  while(1)
   {
	i++;
	if(!(i%3)) printf("%d\r\ni);
	a ^= 1;
	printf("%d\r\na);
	Sleep(1000);
   }
}

========================22 . 연산자 동작시험 ============
void CharToBinPrint(char character)
{
int i;

for(i=7; i>=0; i--)
{
if(character&(0x01<<i)) printf("1");
else printf("0");
}
printf("\r\n");
}

int main(void)
{
	unsigned char i = 0x0F;

	i &= ~(0x7F);

  while(1)
   {

	CharToBinPrint(i);
	Sleep(1000);
   }


}



========================21 . 헥사로 채워진 배열의 위치찾기 ============

typedef struct {
	unsigned char * name[10];
}UNIT_EACH;


typedef struct
{
UNIT_EACH level;
UNIT_EACH velocity;
}UNIT;

UNIT unit;

const UNIT  unit_list =
{

{0x00,	0x02,	0x10,	0x12,	0x15,	0x16,},///<수위
{0x00,	0x15,},
};

unsigned char find_type(unsigned char type)
{
	unsigned char i;

	for(i=0; i<10; i++)
	if(type == unit_list.level.name[i]) break;
	return i;
}

int main(void)
{
char str[100];
char * p;

while(1)
   {

	printf("%d %02d\r\nfind_type(0x10),10);


	Sleep(1000);
   }

}

========================20 . 포인터로 2개의 변수값연결 ============

typedef struct {
	unsigned char * name[10];
}UNIT_EACH;


typedef struct
{
UNIT_EACH level;
UNIT_EACH velocity;
}UNIT;

UNIT unit;

const UNIT  unit_list =
{

{"mm	"Cm	"m	"in	"ft},///<수위
{"m/s}
};

int main(void)
{
char str[100];

while(1)
   {

	printf("%d    %s \r\nsizeof(unit), unit_list.level.name[0]);
	sprintf(str, "%.2f %s1.2,unit_list.level.name[0],sizeof(str));

	Sleep(1000);
   }

}



========================19 . 2차배열의 크기확인 ============

typedef struct {
	unsigned char * name[10];
}UNIT_EACH;


typedef struct
{
UNIT_EACH level;
UNIT_EACH velocity;
}UNIT;

UNIT unit;

const UNIT  unit_list =
{

{"mm	"Cm	"m	"in	"ft},///<수위
{"m/s}
};

int main(void)
{
char str[100];

while(1)
   {

	printf("%d    %s \r\nsizeof(unit), unit_list.level.name[0]);
	sprintf(str, "%.2f %s1.2,unit_list.level.name[0],sizeof(str));

	Sleep(1000);
   }

}



========================18 . strtok 함수를 이용해 문자열토크처리 ============

int main(void)
{
char strA[] = "14.37.38.148";// 대상문자열
char strB[] = "' .";// 구분할 문자열들 ( space, ' .)
char * tocken = NULL;
char ip[3];
int i=0;

while(1)
   {
    tocken = strtok(strA,strB);
	while(tocken)
{
	ip[i] = tocken;

	printf("%s     %d\ntocken, atoi(tocken));
	tocken = strtok(NULL, strB);
	i++;
}

	Sleep(1000);
   }

}


========================17 . 문자열 검색함수 strstr ============

int main(void)
{
char str[20]={"on ON off OFF"};
char * link;

link = "ON";

  while(1)
   {

	if(strstr(str, link)) printf("Find!\r\n");
	Sleep(1000);
   }

}


*========================16 . 문자열과 문자열을 연결시키는 포인터  ============


int main(void)
{
char str[]={"abc0967"};
char * ptr;
char test[10];

  while(1)
   {
	ptr = str;

	memcpy(test,ptr,strlen(ptr));
	printf("%s\r\ntest);
	Sleep(1000);
   }

}


=========================15 . 버퍼값 rotation 시킨후 다른버퍼에 저장 ======
void CharToBinPrint(char character)
{
int i;

for(i=7; i>=0; i--)
{
if(character&(0x01<<i)) printf("1");
else printf("0");
}
printf("\r\n");
}

int main(void)
{

unsigned char pixelData[5] = { 0x7f,0x02,0x0C,0x02,0x7f };
unsigned char rotate_data[8] = {0,};
int i;


while(1)
  {

// 2진수로 출력해보면 'M' 자가 시계방향으로 90도 누워있는것으로 보임
   for(i=0; i<5; i++)
	CharToBinPrint(pixelData[i]);

// 2진수로 출력해보면 'M' 자가 시계반대 방향으로 90도 회전하여 똑바로 세워져있는것으로 보임
printf("\r\n");

rotate_data[0] = ((pixelData[0]&0x01)<<5) + ((pixelData[1]&0x01)<<4) + ((pixelData[2]&0x01)<<3) + ((pixelData[3]&0x01)<<2) + ((pixelData[4]&0x01)<<1);
rotate_data[1] = ((pixelData[0]&0x02)<<4) + ((pixelData[1]&0x02)<<3) + ((pixelData[2]&0x02)<<2) + ((pixelData[3]&0x02)<<1) + ((pixelData[4]&0x02)<<0);
rotate_data[2] = ((pixelData[0]&0x04)<<3) + ((pixelData[1]&0x04)<<2) + ((pixelData[2]&0x04)<<1) + ((pixelData[3]&0x04)<<0) + ((pixelData[4]&0x04)>>1);
rotate_data[3] = ((pixelData[0]&0x08)<<2) + ((pixelData[1]&0x08)<<1) + ((pixelData[2]&0x08)<<0) + ((pixelData[3]&0x08)>>1) + ((pixelData[4]&0x08)>>2);
rotate_data[4] = ((pixelData[0]&0x10)<<1) + ((pixelData[1]&0x10)<<0) + ((pixelData[2]&0x10)>>1) + ((pixelData[3]&0x10)>>2) + ((pixelData[4]&0x10)>>3);
rotate_data[5] = ((pixelData[0]&0x20)<<0) + ((pixelData[1]&0x20)>>1) + ((pixelData[2]&0x20)>>2) + ((pixelData[3]&0x20)>>3) + ((pixelData[4]&0x20)>>4);
rotate_data[6] = ((pixelData[0]&0x40)>>1) + ((pixelData[1]&0x40)>>2) + ((pixelData[2]&0x40)>>3) + ((pixelData[3]&0x40)>>4) + ((pixelData[4]&0x40)>>5);
rotate_data[7] = ((pixelData[0]&0x80)>>2) + ((pixelData[1]&0x80)>>3) + ((pixelData[2]&0x80)>>4) + ((pixelData[3]&0x80)>>5) + ((pixelData[4]&0x80)>>6);


for(i=0; i<8; i++)
	CharToBinPrint(rotate_data[i]);


	Sleep(50000);
  }


}




========================14 . printf 2진수로 출력  ============
void CharToBinPrint(char character)
{
int i;

for(i=7; i>=0; i--)
{
if(character&(0x01<<i)) printf("1");
else printf("0");
}
printf("\r\n");
}

int main(void)
{


  while(1)
   {

	CharToBinPrint(0xFE);
	Sleep(1000);
   }


}

========================13 . 자동 캘리브레이션    ============
#define bit_test(x,n) (x & (0x01<<n-1))

float cali_adjust(float f1, float f2)
{
	float adjust;

	adjust = f1-f2;

	return adjust;

}

int main(void)
{


unsigned char str[] = "?";//{0x0e,0x23};//"??????";
float f1 = 4.0, f2 = 4.85;
float adjust;
unsigned char pixelData[5] = {1,3};
unsigned char rotate_data[5] = {0,};


  while(1)
   {
	rotate_data[0] = pixelData[0] + pixelData[1]&&0x01;
//printf("%x\r\nrotate_data[0]);
    printf("%-08.3f\r\n cali_adjust(f1,f2));
	Sleep(1000);
   }


}



=========================12 . 링버퍼의 포인터 원리    ============



void main()
{
#define MAX_BUF_SIZE		8
#define MAX_BUF_MASK		MAX_BUF_SIZE-1

unsigned char in=5;
unsigned char out=0;
int i;

	while(1)
{
	for(i=0; i<MAX_BUF_SIZE; i++)
{
	i &=  MAX_BUF_MASK;
	printf("%d\r\ni);
	Sleep(500);
}


}


}




====================== 11 . 구조체에서 포인터 역참조=================

int main(void)
{

unsigned char cmd_arr[5];
BUF buf = {3,5,cmd_arr};
BUF *p = &buf;
p->in=8;


buf.buf ='A';

	while(1)
{
	printf("%d   %d    %c\r\np->in , p->out, p->buf++);

	Sleep(500);

}


}




====================== 10 . 링버퍼 .===============================

// Opaque buffer element type.  This would be defined by the application.
typedef struct { unsigned char value; } ElemType;

// 링버퍼 구조체 선언
typedef struct {
   int         size;
   int         start;
   int         end;
   ElemType   *elems;
} CIRCULAR_BUFFER;
// 링버퍼 초기화
void cbInit(CIRCULAR_BUFFER *cb, int size) {
   cb->size  = size + 1;
   cb->start = 0;
   cb->end   = 0;
//동적메모리 할당
   cb->elems = calloc(cb->size, sizeof(ElemType));
}
// 동적메모리 할당해제
void cbFree(CIRCULAR_BUFFER *cb) {
   free(cb->elems);
}
// 링버퍼 오버플로우발생시 1을 반환
int cbIsFull(CIRCULAR_BUFFER *cb) {
   return (cb->end + 1) % cb->size == cb->start;
}
// 링버퍼 srart와 end포인트가 같아지면 1 을 반환,  Otherwise 0 을 반환
int cbIsEmpty(CIRCULAR_BUFFER *cb) {
   return cb->end == cb->start;
}

// Write an element, overwriting oldest element if buffer is full. App can
//   choose to avoid the overwrite by checking cbIsFull().
void cbWrite(CIRCULAR_BUFFER *cb, ElemType *elem) {
   cb->elems[cb->end] = *elem;
   cb->end = (cb->end + 1) % cb->size;
   if (cb->end == cb->start)
       cb->start = (cb->start + 1) % cb->size;

}

// Read oldest element. App must ensure !cbIsEmpty() first.
// start포인터부터 end포인터까지 읽는다.
void cbRead(CIRCULAR_BUFFER *cb, ElemType *elem) {
   *elem = cb->elems[cb->start];
   cb->start = (cb->start + 1) % cb->size;
}



int main(int argc, char **argv) {
   CIRCULAR_BUFFER *cb;
   ElemType elem = {'A'};
   int testBufferSize = 6;
unsigned char i;
   cbInit(&cb, testBufferSize);



   // Fill buffer with test elements 3 times
   //for (elem.value = 0; elem.value < 1 * testBufferSize; ++ elem.value)
for (i = 0; i <= testBufferSize; ++i)
{
// 버퍼의 오버플로우검출
	if(!cbIsFull(&cb))
{
	cbWrite(&cb, &elem);
	elem.value++;
}
	else
 printf("Overflow\r\n");
}






//while (!cbIsEmpty(&cb)) {
while(1) {

	cbRead(&cb, &elem);
	printf("%c\n elem.value);

	Sleep(500);
   }

   cbFree(&cb);
   return 0;
}




====================== 9 . Float To String 함수 .===============================

* float f : 문자열로 변환할 실수값
* int length : 문자열로 변환할 소수점 자릿수, 0이면 정수로 변환
* char *buffer : 변환값을 저장할 문자열포인터

void FloatToString(float f, int length, char* buffer)
{
   int i = 0;
   int num = 0;
   int pos = 0;
   int dec = 0;

   if(f < 0)
   {
       buffer[pos++] = '-';
       f *= -1;
   }

   dec = f;

   while(dec > 0)
   {
       num++;
       dec /= 10;
    }

    dec = f;
    f = (f-dec) * 10;

    if(num == 0)
    {
        buffer[pos++] = '0';
    }
    else
    {
        for(i = num; i > 0; i--)
       {
           buffer[i-1 + pos] = dec % 10 + '0';
           dec /= 10;
       }

       pos += num;
   }

   if(f == 0.0f)
       return;
   else
   {
       if(length > 0)
           buffer[pos++] = '.';

       for(i = 0; i < length; i++)
       {
           int value = f;
           buffer[pos++] = value + '0';
           f = (f-value) * 10;
           if(f == 0.0f)
               break;
       }
   }
}








====================== 7 . 주어진 문자열에서 원하는 문자를 찾는함수.===============================

int  ch = 'r';

char string[] = "The quick brown dog jumps over the lazy fox";
char fmt1[] =   "         1         2         3         4         5";
char fmt2[] =   "12345678901234567890123456789012345678901234567890";


int main( void )
{

while(1)
{
char *pdest;
int result;

printf_s( "String to be searched:\n      %s\n string );
printf_s( "      %s\n      %s\n\n fmt1, fmt2 );
printf_s( "Search char:   %c\n ch );

// Search forward.
pdest = strchr( string, ch );
result = (int)(pdest - string + 1);
if ( pdest != NULL )
printf_s( "Result:   first %c found at position %d\n
ch, result );
else
printf_s( "Result:   %c not found\n ch );

// Search backward.
pdest = strrchr( string, ch );
result = (int)(pdest - string + 1);
if ( pdest != NULL )
printf_s( "Result:   last %c found at position %d\n ch, result );
else
printf_s( "Result:\t%c not found\n ch );
Sleep(1000);
}
}


====================== 6 . 정해진 주기마다 시간 갱신.===============================


void get_est_time(unsigned long now, unsigned long time_distance);
void main( void )
{

int i=1000;

while( 1 )
{

i++;
get_est_time(i, 30);   // 숫자값(sec)을 바꾸면 정해진 주기마다 시간 갱신.
Sleep(1000);
}
}


//2000년1월1일 0시를 기준으로 한 예측시간 설정
void get_est_time(unsigned long now, unsigned long time_distance)
{
unsigned long ltmp, ltmp1;

if(!now  || !time_distance) return 0;

ltmp = now/time_distance;//몫

//행동 예측시간
ltmp1 = (ltmp+1)*time_distance;
printf("%ldltmp1);

}




====================== 5 . 문자열에서 스페이스로 구분하기 ============================
void main( void )
{
int count=0;
char string[] = "2012 04 10";
char seps[]   = " \t\n";
char *token;
//char data[100][100];


token = strtok( string, seps );

while( token != NULL )
{

printf( " %s\n token );




// strcpy(data[count++],token);





token = strtok( NULL, seps );
Sleep(1000);
}
}


====================== 4 . 근사값 찾기 ============================
int main(void)
{
int i = 0;
float data[] = {10.0, 20.0, 30.0, 40.0, 50.0};
int size = sizeof(data) / sizeof(float);
float min = 100.0; // 차이값의 최소값을 저장
float sub;  //차이값

int index; //차이값이 들어있는 배열의 인덱스를 저장
float input;
//[1] Input //////////////////////////
printf("원본 데이터 : ");
for (i = 0; i < size; i++)
printf("%3.1f data[i]);
printf("\n\n");
printf("타겟 데이터 : ");

scanf("%f &input);
//[2] Process ////////////////////////


for (i = 0; i < size; i++)
{
sub = input - data[i]; //차이값의 절대값
if(sub<0) sub = -sub;
printf("%f\r\nsub);
if (sub < min) //최소값 알고리즘
{
min = sub;
index = i;
}
}
//[3] Output /////////////////////////
printf("\n");
printf("%f와 가장 가까운값은 %f입니다.\n input, data[index]);

Sleep(13000);
}


====================== 3 . itoa 정수를 문자열로============================

int main( void )
{
char buffer[65] = {0};
int num = 100;

itoa( num, buffer, 10 );
printf( "base %d: %s \n num, buffer);


Sleep(100000);
return 0;
}




====================== 2 . MINIMUM 근사값찾기 =============================

int main(void)
{
int i = 0;
float data[] = {10.0, 20.0, 30.0, 40.0, 50.0};
int size = sizeof(data) / sizeof(float);
float min = 100.0; // 차이값의 최소값을 저장
float sub;  //차이값

int index; //차이값이 들어있는 배열의 인덱스를 저장
float input;
//[1] Input //////////////////////////
printf("원본 데이터 : ");
for (i = 0; i < size; i++)
printf("%3.1f data[i]);
printf("\n\n");
printf("타겟 데이터 : ");

scanf("%f &input);
//[2] Process ////////////////////////


for (i = 0; i < size; i++)
{
sub = input - data[i]; //차이값의 절대값
if(sub<0) sub = -sub;
printf("%f\r\nsub);
if (sub < min) //최소값 알고리즘
{
min = sub;
index = i;
}
}
//[3] Output /////////////////////////
printf("\n");
printf("%f와 가장 가까운값은 %f입니다.\n input, data[index]);

Sleep(13000);
}







====================== 1 . 콘솔창 한곳에서 printf하기 =============================
__time64_t ltime;
void gotoxy(int x, int y);



int main(void)

{

while(1)
{

gotoxy(2,4);


_time64( &ltime );
printf( "%s _ctime64( &ltime ) ); // C4996



Sleep(1000);
}
return 0;

}



void gotoxy(int x, int y)

{

COORD Pos = { x-1, y-1 };

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

=========================================================================== */

#endif
#endif
