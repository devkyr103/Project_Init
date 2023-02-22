#pragma once

#define DECLARE_SINGLE(Type)	\
private:\
	static	Type*	m_Inst;\
public:\
	inline static	Type*	GetInst()\
	{\
		if(!m_Inst)\
			m_Inst = new Type;\
		return m_Inst;\
	}\
	inline static void DestroyInst()\
	{\
		if(m_Inst)\
		{\
			delete m_Inst;\
			m_Inst = nullptr;\
		}\
	}\
private:\
	Type();\
	~Type();

// 인스턴스를 위한 static 멤버 정의 메크로
#define DEFINITION_SINGLE(Type)	Type*	Type::m_Inst = nullptr;