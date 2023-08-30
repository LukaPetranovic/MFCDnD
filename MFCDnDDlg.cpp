
// MFCDnDDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCDnD.h"
#include "MFCDnDDlg.h"
#include "afxdialogex.h"
#include "StatCalculator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDnDDlg dialog



CMFCDnDDlg::CMFCDnDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCDND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	Race humanRace, elfRace;
	humanRace.name = _T("Human");
	race.push_back(humanRace);
	elfRace.name = _T("Elf");
	race.push_back(elfRace);

}

void CMFCDnDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDnDDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCDnDDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCDnDDlg message handlers

BOOL CMFCDnDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	raceCombo.Attach(GetDlgItem(IDC_COMBO1)->GetSafeHwnd());

	CComboBox* pRaceCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	for (const Race& race : race) {
		pRaceCombo->AddString(race.name);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDnDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCDnDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDnDDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	int selectedRaceIndex = raceCombo.GetCurSel();

	if (selectedRaceIndex == CB_ERR) {
		MessageBox(_T("Not a valid selection."), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	Race selectedRace;
	int randomStat, modifier;
	CEdit* pStrEdit;

	StatCalculator statCalculator;
	switch (selectedRaceIndex) {
	case 0:
		selectedRace = race[selectedRaceIndex];
		randomStat = statCalculator.CalculateRandomStat();
		strModifier.LoadString(IDS_STR_MOD);

		modifier = _wtoi(strModifier);

		modifiedStatStr.Format(_T("%d"), randomStat);

		pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);
		break;
	case 1:
		selectedRace = race[selectedRaceIndex];
		randomStat = statCalculator.CalculateRandomStat();
		strModifier.LoadString(IDS_STR_MOD);

		modifier = _wtoi(strModifier);

		modifiedStatStr.Format(_T("%d"), randomStat);

		pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);
		break;
	}
	// Remove if else block and add switch block
	/*if (selectedRaceIndex != CB_ERR && selectedRaceIndex == 0) {
		Race selectedRace = race[selectedRaceIndex];
		//int baseStat = 8;

		int randomStat = statCalculator.CalculateRandomStat();

		//CString strModifier;
		strModifier.LoadString(IDS_STR_MOD);

		int modifier = _wtoi(strModifier);

		//CString modifiedStatStr;
		modifiedStatStr.Format(_T("%d"), randomStat);

		CEdit* pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);

	}
	else if (selectedRaceIndex != CB_ERR && selectedRaceIndex == 1) {
		Race selectedRace = race[selectedRaceIndex];
		//int baseStat = 8;


		//CString strModifier;
		strModifier.LoadString(IDS_STR_MOD);

		int modifier = _wtoi(strModifier);

		int modifiedStat = baseStat + modifier + 2;

		//CString modifiedStatStr;
		modifiedStatStr.Format(_T("%d"), modifiedStat);

		CEdit* pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);
	}*/
	//CDialogEx::OnOK();
}
