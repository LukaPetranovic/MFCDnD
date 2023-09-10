
// MFCDnDDlg.h : header file
//

#pragma once
#include "Race.hpp"



// CMFCDnDDlg dialog
class CMFCDnDDlg : public CDialogEx
{
public:
	CMFCDnDDlg(CWnd* pParent = nullptr);

private:
	CComboBox raceCombo;
	CString strModifier, dexModifier, conModifier, intModifier, wisModifier, chaModifier;
	CString modifiedStatStr, modifiedStatDex, modifiedStatCon, modifiedStatInt, modifiedStatWis, modifiedStatCha;
	CString racialBonuses;
	CString errorMessage;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCDND_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);


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
	void UpdateStats(int randomStat, const CString& modifierStr, CEdit* EditControl);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeCombo1();
	void RaceModifiers(int selectedRaceIndex, int& randomStrStat, int& randomDexStat, int& randomConStat, int& randomIntStat, int& randomWisStat, int& randomChaStat);
};
