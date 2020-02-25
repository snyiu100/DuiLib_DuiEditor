
// DuiEditorView.h : CDuiEditorView ��Ľӿ�
//

#pragma once
#include "DockControlTreeCtrl.h"
#include "UIManager.h"
#include "UITrackerMuliti.h"
#include "DuiEditorCommandHistory.h"
#include <list>

#include "UIWindowEx.h"
class CDuiEditorViewDesign : public CScrollView
{
protected: // �������л�����
	CDuiEditorViewDesign();
	DECLARE_DYNCREATE(CDuiEditorViewDesign)

// ����
public:
	CDuiEditorDoc* GetDocument() const;

	CUIManager m_Manager;
	int m_zoom;
	CDuiEditorCommandHistory m_cmdHistory;

	int m_nFormatInsert;	//����ģʽ��ͨ�Ļ��߾��Զ�λ��
	BOOL m_bShowUiPreview;	//�Ƿ��ڱ༭������ʾUIЧ��
	BOOL m_bViewRuleBar;	//�Ƿ���ʾ���
	BOOL m_bViewGrid;		//�Ƿ���ʾ����
	BOOL m_bViewMouse;		//�Ƿ���ʾ�����


	PROCESS_INFORMATION m_piProcInfo; 
	STARTUPINFO m_siStartInfo; 
// ����
public:
	void InitView();
// ��д
protected:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CDuiEditorViewDesign();

protected:
	BOOL m_bMouseTracking;
// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI *pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI *pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI *pCmdUI);
	afx_msg void OnEditClear();
	afx_msg void OnUpdateEditClear(CCmdUI *pCmdUI);
	afx_msg void OnEditCopyName();
	afx_msg void OnUpdateEditCopyName(CCmdUI *pCmdUI);
	afx_msg void OnEditCopyNameEx();
	afx_msg void OnUpdateEditCopyNameEx(CCmdUI *pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
	afx_msg void OnEditRedo();
	afx_msg void OnUpdateEditRedo(CCmdUI *pCmdUI);
	afx_msg void OnEditInsertFont();
	afx_msg void OnEditInsertDefault();
	afx_msg void OnEditInsertStyleNode();

	afx_msg void OnUiformDebug();
	afx_msg void OnUpdateUiformDebug(CCmdUI *pCmdUI);
	afx_msg void OnUiformDebugEnd();
	afx_msg void OnUpdateUiformDebugEnd(CCmdUI *pCmdUI);
	afx_msg void OnCommandTabLayoutSetSel(UINT nID);

	afx_msg void OnFormatAlignLeft();
	afx_msg void OnUpdateFormatAlignLeft(CCmdUI *pCmdUI);
	afx_msg void OnFormatAlignRight();
	afx_msg void OnUpdateFormatAlignRight(CCmdUI *pCmdUI);
	afx_msg void OnFormatAlignTop();
	afx_msg void OnUpdateFormatAlignTop(CCmdUI *pCmdUI);
	afx_msg void OnFormatAlignBottom();
	afx_msg void OnUpdateFormatAlignBottom(CCmdUI *pCmdUI);
	afx_msg void OnFormatAlignSameSpaceVert();
	afx_msg void OnUpdateFormatAlignSameSpaceVert(CCmdUI *pCmdUI);
	afx_msg void OnFormatAlignSameSpaceHori();
	afx_msg void OnUpdateFormatAlignSameSpaceHori(CCmdUI *pCmdUI);
	afx_msg void OnFormatAlignCenterVert();
	afx_msg void OnUpdateFormatAlignCenterVert(CCmdUI *pCmdUI);
	afx_msg void OnFormatAlignCenterHori();
	afx_msg void OnUpdateFormatAlignCenterHori(CCmdUI *pCmdUI);
	afx_msg void OnFormatSameWidth();
	afx_msg void OnUpdateFormatSameWidth(CCmdUI *pCmdUI);
	afx_msg void OnFormatSameHeight();
	afx_msg void OnUpdateFormatSameHeight(CCmdUI *pCmdUI);
	afx_msg void OnFormatSameSize();
	afx_msg void OnUpdateFormatSameSize(CCmdUI *pCmdUI);
	afx_msg void OnEditZoomIn();
	afx_msg void OnUpdateEditZoomIn(CCmdUI *pCmdUI);
	afx_msg void OnEditZoomOut();
	afx_msg void OnUpdateEditZoomOut(CCmdUI *pCmdUI);
	afx_msg void OnEditZoomFull();
	afx_msg void OnUpdateEditZoomFull(CCmdUI *pCmdUI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	afx_msg void OnFormatInsertNormalControl();
	afx_msg void OnUpdateFormatInsertNormalControl(CCmdUI *pCmdUI);
	afx_msg void OnFormatInsertFloatControl();
	afx_msg void OnUpdateFormatInsertFloatControl(CCmdUI *pCmdUI);
	afx_msg void OnFormatShowRulerbar();
	afx_msg void OnUpdateFormatShowRulerbar(CCmdUI *pCmdUI);
	afx_msg void OnFormatShowGrid();
	afx_msg void OnUpdateFormatShowGrid(CCmdUI *pCmdUI);
	afx_msg void OnFormatShowMouse();
	afx_msg void OnUpdateFormatShowMouse(CCmdUI *pCmdUI);
	afx_msg void OnFormatShowUiPreview();
	afx_msg void OnUpdateFormatShowUiPreview(CCmdUI *pCmdUI);
	afx_msg void OnSetDPI(UINT id);
	afx_msg void OnUpdateSetDPI(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // DuiEditorView.cpp �еĵ��԰汾
inline CDuiEditorDoc* CDuiEditorViewDesign::GetDocument() const
   { return reinterpret_cast<CDuiEditorDoc*>(m_pDocument); }
#endif
