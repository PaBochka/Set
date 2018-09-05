#include <iostream>
#include "TSet.h"
using namespace std;
TSet::TSet(int mp) : MaxPower(mp), BitField(mp)
{}
TSet::TSet(const TSet &s) : MaxPower(s.MaxPower), BitField(s.BitField)
{}
TSet::TSet(const TBitField &bf) : MaxPower(bf.GetLength()), BitField(bf)
{}
TSet::operator TBitField()
{
	TBitField res(this->BitField);
	return res;
}
int TSet::GetMaxPower(void) const
{
	return MaxPower;
}
void TSet::InsElem(const int n)
{
	BitField.SetBit(n);
}
void TSet::DelElem(const int n)
{
	BitField.ClrBit(n);
}
int TSet::IsMember(const int n) const
{
	return BitField.GetBit(n);
}
int TSet::operator==(const TSet &s)
{
	int res=0;
		if (BitField == s.BitField)
			res = 1;
	return res;
}
TSet &TSet::operator=(const TSet &s)
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return(*this);
}
TSet TSet::operator+ (const TSet &s)
{
	return(BitField | s.BitField);
}
TSet TSet::operator* (const TSet &s)
{
	return(BitField&s.BitField);
}
TSet TSet::operator~ (void)
{
	return (~BitField);
}
ostream &operator<<(ostream &ostr, const TSet &bf)
{
	for (int i = 0; i < bf.MaxPower; i++)
	{
		/*if (bf.IsMember(i))
			ostr << (bf.IsMember(i)); else ostr << 0;
		ostr << '\n';*/
		if (bf.IsMember(i))
			ostr << i << " ";
	}
	return ostr;
}
istream &operator>>(istream &istr, TSet &bf)
{
	int numb;
	for (int i = 0; i < bf.MaxPower; i++)
	{
		istr >> numb;
		if ((numb >= 0) && (numb < bf.MaxPower))
			bf.InsElem(numb); else break;
	}
	return istr;
}

TSet TSet::operator+ (const int n)
{
	TSet temp(MaxPower);
	temp = (*this);
	temp.InsElem(n);
	return temp;
}
TSet TSet::operator- (const int n)
{
	TSet temp(MaxPower);
	temp = (*this);
	temp.DelElem(n);
	return temp;
}