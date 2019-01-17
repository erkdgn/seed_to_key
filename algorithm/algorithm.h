
// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SA_ALLINONE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SA_ALLINONE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SA_EXPORTS
#define SA_API extern "C" __declspec(dllexport)
#else
#define SA_API extern "C" __declspec(dllimport)
#endif


#define PROJECT_NAME	"Undefined Project"
#define LEVEL_EXTEND	0x01
#define LEVEL_PROGRAM	0x11
#define LEVEL_EOL		0x61

// For 'ETS'
SA_API BOOL WINAPIV Seed2Key(ULONG VendorCode, BYTE* Seed, UINT SeedSize, BYTE* Key, UINT* KeySize, USHORT SAAlg);

// For 'Tellus'


// For 'CANoe'
enum VKeyGenResultEx
{
	KGRE_Ok = 0,
	KGRE_BufferToSmall = 1,
	KGRE_SecurityLevelInvalid = 2,
	KGRE_VariantInvalid = 3,
	KGRE_UnspecifiedError = 4
};

// The client has to provide a keyArray buffer and has to transfer this buffer - 
// including its size - to the GenerateKey method. The method checks, if the size is
// sufficient. The client can discover the required size by examinig the service used
// transfer the key to the ECU.
// Returns false if the key could not be generated:
//  -> keyArraySize to small
//  -> generation for specified security level not possible
//  -> variant unknown
SA_API VKeyGenResultEx  GenerateKeyEx(
	const unsigned char*  ipSeedArray, unsigned short  iSeedArraySize,
	const unsigned int    iSecurityLevel, const char*   ipVariant,
	unsigned char*        iopKeyArray, unsigned int  iMaxKeyArraySize,
	unsigned int&         oActualKeyArraySize);


// For 'Vehecle Spy"
/**
* Generates an unlock key based on a given seed.
* @param ucSecurityLevel The security level requested that generated this seed. Usually the subfunction to the $27 service.
* @param iSeedKeySize Size of pucSeed and pucSeed in bytes.
* @param iExtraBytesSize Size of pucExtraBytes in bytes.
* @param pucSeed Pointer to a buffer containing the seed.
* @param pucKey Pointer to a buffer where the calculated key should be written to. This is already allocated.
* @param pucExtraByes Extra bytes which can be used as a general extra parameter (for algorithms that require more than seed as input).
* @return Return true if the key calculated successfully, otherwise false.
*/
SA_API bool __stdcall ES_CalculateKeyFromSeed(unsigned char ucSecurityLevel,
	int iSeedKeySize, int iExtraBytesSize, 
	unsigned char* pucSeed, unsigned char* pucKey, 
	unsigned char* pucExtraBytes);
