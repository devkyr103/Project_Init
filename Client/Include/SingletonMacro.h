#pragma once

#define DECLARE_SINGLE(Type)	\
private:\
	static	Type*	mInst;\
public:\
	inline static	Type*	GetInst()\
	{\
		if(!mInst)\
			mInst = new Type;\
		return mInst;\
	}\
	inline static void DestroyInst()\
	{\
		if(mInst)\
		{\
			delete mInst;\
			mInst = nullptr;\
		}\
	}\
private:\
	Type();\
	~Type();

// �ν��Ͻ��� ���� static ��� ���� ��ũ��
#define DEFINITION_SINGLE(Type)	Type*	Type::mInst = nullptr;