#include "StdAfx.h"
#include "ResizeControlMgr.h"


CResizeControlMgr::CResizeControlMgr(void)
{
}


CResizeControlMgr::~CResizeControlMgr(void)
{
	m_ptrList.RemoveAll();
}


void CResizeControlMgr::InsertControl(CResizingControl *pControl)
{
	m_ptrList.AddTail((void *)pControl);
}

void CResizeControlMgr::ResizingControl(int cx, int cy)
{
	POSITION pos = m_ptrList.GetHeadPosition();
	while(pos)
	{
		CResizingControl *pControl = (CResizingControl *)m_ptrList.GetNext(pos);
		pControl->ResizingControl(cx, cy);
	}
}