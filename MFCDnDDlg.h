
// MFCDnDDlg.h : header file
//

#pragma once
#include "Race.hpp"
#include <vector>



// CMFCDnDDlg dialog
class CMFCDnDDlg : public CDialogEx
{
// Construction
public:
	CMFCDnDDlg(CWnd* pParent = nullptr);	// standard constructor

private:
	std::vector<Race> race;
	CComboBox raceCombo;
	CString strModifier, dexModifier, conModifier, intModifier, wisModifier, chaModifier;
	CString modifiedStatStr, modifiedStatDex, modifiedStatCon, modifiedStatInt, modifiedStatWis, modifiedStatCha;
	int baseStat = 8;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCDND_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
