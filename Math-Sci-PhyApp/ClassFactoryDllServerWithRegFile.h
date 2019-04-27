class ISum :public IUnknown
{
public:
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int *) = 0; //pure virtual

};

class ISubtract :public IUnknown
{
public:
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int *) = 0; //pure virtual
};

//CLSID of SumSubtract Component {C7A4A9C4-9496-4935-A944-F2D5B3393739}

const CLSID CLSID_SumSubtract = { 0xc7a4a9c4, 0x9496, 0x4935, 0xa9, 0x44, 0xf2, 0xd5, 0xb3, 0x39, 0x37, 0x39 };

//IID od ISum Interface

const IID IID_ISum = { 0xde40fbd, 0x774d, 0x4664,0xb7, 0xf6, 0xa, 0xee, 0xe4, 0xfb, 0x8c, 0x92 };

//IID of ISubtract Interface

const IID IID_ISubtract = { 0xc7734b, 0xbead, 0x4ca0, 0x94, 0xd6, 0xbe, 0x49, 0x84, 0x36, 0x81, 0xef };










