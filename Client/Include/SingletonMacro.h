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

// �ν��Ͻ��� ���� static ��� ���� ��ũ��
#define DEFINITION_SINGLE(Type)	Type*	Type::m_Inst = nullptr;