
#pragma once

class CMFCDnDDlg : public CDialogEx
{
public:
	CMFCDnDDlg(CWnd* pParent = nullptr);

private:
	CComboBox raceCombo;
	CString racialBonuses;
	int RaceModifier(int race_index, UINT id);
	CString RaceExplaModifier(int race_index);
	void UpdateStats(int n, UINT id);
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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeCombo1();
};
