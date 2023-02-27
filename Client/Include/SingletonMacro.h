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

// 인스턴스를 위한 static 멤버 정의 메크로
#define DEFINITION_SINGLE(Type)	Type*	Type::mInst = nullptr;